#!/bin/bash
set -e

rm -rf build
mkdir -p build
cd build
cmake ..
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