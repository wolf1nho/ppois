#!/bin/bash
set -e

MODE=${1:-console}  # режим вывода: "console" (по умолчанию), "html" или "both"

SRC_ROOT=$(pwd)

rm -rf build_coverage
mkdir -p build_coverage
cd build_coverage

cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

make -j$(nproc)

./BankSystemTest

echo "Генерация отчёта покрытия (${MODE})..."

GCOVR_FILTERS=(
    "--filter=$SRC_ROOT/account/.*"
    "--filter=$SRC_ROOT/banksafebox/.*" 
    "--filter=$SRC_ROOT/card/.*"
    "--filter=$SRC_ROOT/customer/.*"
    "--filter=$SRC_ROOT/datamanager/.*"
    "--filter=$SRC_ROOT/exception/.*"
    "--filter=$SRC_ROOT/generator/.*"
    "--filter=$SRC_ROOT/getter/.*"
    "--filter=$SRC_ROOT/money/.*"
    "--filter=$SRC_ROOT/FAQ/.*"
)

GCOVR_EXCLUDES=(
    "--exclude=.*/build.*/.*"
    "--exclude=.*/CMakeFiles/.*"
)

if [ "$MODE" = "html" ] || [ "$MODE" = "both" ]; then
    mkdir coverage_report
    gcovr -r "$SRC_ROOT" \
            "${GCOVR_FILTERS[@]}" \
            "${GCOVR_EXCLUDES[@]}" \
            --html-details \
            --html-theme green \
            --html-title="BankSystem Coverage Report" \
            -o ./coverage_report/coverage.html

    echo "Отчёт покрытия создан: $(realpath ./coverage.html)"
fi

if [ "$MODE" = "console" ] || [ "$MODE" = "both" ]; then
    gcovr -r "$SRC_ROOT" \
            "${GCOVR_FILTERS[@]}" \
            "${GCOVR_EXCLUDES[@]}" \
            --print-summary

elif [ "$MODE" != "html" ]; then
    echo "Неизвестный режим: $MODE"
    echo "Использование: $0 [console|html|both]"
    exit 1
fi

if [ "$MODE" = "html" ] || [ "$MODE" = "both" ]; then
    echo "Открытие отчёта в браузере по умолчанию"
    xdg-open coverage_report/coverage.html
fi

