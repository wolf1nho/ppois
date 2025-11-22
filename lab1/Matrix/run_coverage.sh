#!/bin/bash
set -e

MODE=${1:-console}  # режим вывода: "console" (по умолчанию), "html" или "both"

SRC_ROOT=$(pwd)

rm -rf build-coverage
mkdir -p build-coverage
cd build-coverage

cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

make -j$(nproc)

TEST_BINARY="./MatrixTests"

if [ ! -f "$TEST_BINARY" ]; then
    TEST_BINARY=$(find . -type f -executable -name "MatrixTests" | head -n 1)
fi

if [ -z "$TEST_BINARY" ]; then
    echo "Не найден исполняемый файл тестов!"
    exit 1
else
    echo "Найден тестовый бинарник: $TEST_BINARY"
    "$TEST_BINARY"
fi

echo "Генерация отчёта покрытия (${MODE})..."

if [ "$MODE" = "html" ] || [ "$MODE" = "both" ]; then
    gcovr -r "$SRC_ROOT" \
        --filter="$SRC_ROOT/Matrix.cpp" \
        --filter="$SRC_ROOT/tests/MatrixTests.cpp" \
        --html-details \
        --html-title="Matrix Coverage Report" \
        -o ./coverage.html

    echo "Отчёт покрытия создан: $(realpath ./coverage.html)"

elif [ "$MODE" = "console" ] || [ "$MODE" = "both" ]; then
    gcovr -r "$SRC_ROOT" \
        --filter="$SRC_ROOT/Matrix.cpp" \
        --filter="$SRC_ROOT/tests/MatrixTests.cpp"

else
    echo "Неизвестный режим: $MODE"
    echo "Использование: $0 [console|html|both]"
    exit 1
fi
