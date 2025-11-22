#!/bin/bash
set -e

#SRC_ROOT=$(pwd)

rm -rf build
mkdir -p build
cd build
cmake ..
make -j$(nproc)

TEST_BINARY="./VectorTests"

if [ ! -f "$TEST_BINARY" ]; then
    TEST_BINARY=$(find . -type f -executable -name "VectorTests" | head -n 1)
fi
if [ -z "$TEST_BINARY" ]; then
    echo "Не найден исполняемый файл тестов!"
    exit 1
else
    echo "Найден тестовый бинарник: $TEST_BINARY"
    "$TEST_BINARY"
fi