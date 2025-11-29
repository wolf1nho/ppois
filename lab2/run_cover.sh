#!/bin/bash
set -e

MODE=${1:-console}  # режим вывода: "console" (по умолчанию), "html" или "both"

SRC_ROOT=$(pwd)

rm -rf build_coverage
mkdir -p build_coverage
cd build_coverage

cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

make -j$(nproc)

./SportClubTest

echo "Генерация отчёта покрытия (${MODE})..."

GCOVR_FILTERS=(
    "--filter=$SRC_ROOT/Human/.*"
    "--filter=$SRC_ROOT/Room/.*" 
    "--filter=$SRC_ROOT/Reception/.*"
    "--filter=$SRC_ROOT/Shop/.*"
    "--filter=$SRC_ROOT/Schedule/.*"
    "--filter=$SRC_ROOT/SM/.*"
    "--filter=$SRC_ROOT/Mirror/.*"
    "--filter=$SRC_ROOT/Exception/.*"
    "--filter=$SRC_ROOT/Enums/.*"
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
            --html-title="SportClub Coverage Report" \
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

