#include <gtest/gtest.h>
#include "../Shop/swimwear.h"

// 🔹 Базовый тест — корректная инициализация и геттеры
TEST(SwimwearTest, InitializationAndGetters)
{
    Swimwear swim(49.99, "M", "nylon", "blue", "one-piece");

    EXPECT_EQ(swim.get_size(), "M");
    EXPECT_EQ(swim.get_material(), "nylon");
    EXPECT_EQ(swim.get_color(), "blue");
    EXPECT_EQ(swim.get_style(), "one-piece");
}