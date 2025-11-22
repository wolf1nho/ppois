#!/bin/bash
set -e

# === Параметры ===
MODE=${1:-console}  # режим вывода: "console" (по умолчанию), "html" или "both"

# === Путь к корню проекта ===
SRC_ROOT=$(pwd)

# === Очистка и подготовка директории сборки ===
rm -rf build-coverage
mkdir -p build-coverage
cd build-coverage

# === Конфигурация проекта с поддержкой покрытия ===
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE=ON ..

# === Сборка проекта ===
make -j$(nproc)

# === Поиск исполняемого файла тестов ===
TEST_BINARY="./VectorTests"
if [ ! -f "$TEST_BINARY" ]; then
    TEST_BINARY=$(find . -type f -executable -name "VectorTests" | head -n 1)
fi

# === Проверка наличия файла тестов ===
if [ -z "$TEST_BINARY" ]; then
    echo "❌ Не найден исполняемый файл тестов!"
    exit 1
else
    echo "✅ Найден тестовый бинарник: $TEST_BINARY"
    "$TEST_BINARY"
fi

# === Генерация отчёта покрытия ===
echo "📊 Генерация отчёта покрытия (${MODE})..."

if [ "$MODE" = "html" ] || [ "$MODE" = "both" ]; then
    gcovr -r "$SRC_ROOT" \
        --filter="$SRC_ROOT/Vector.cpp" \
        --filter="$SRC_ROOT/tests/VectorTests.cpp" \
        --html-details \
        --html-title="Vector Coverage Report" \
        -o ./coverage.html

    echo "✅ Отчёт покрытия создан: $(realpath ./coverage.html)"

elif [ "$MODE" = "console" ] || [ "$MODE" = "both" ]; then
    gcovr -r "$SRC_ROOT" \
        --filter="$SRC_ROOT/Vector.cpp" \
        --filter="$SRC_ROOT/tests/VectorTests.cpp"

else
    echo "⚠️ Неизвестный режим: $MODE"
    echo "Использование: $0 [console|html|both]"
    exit 1
fi
