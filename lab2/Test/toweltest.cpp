#include <gtest/gtest.h>
#include "../Shop/towel.h"

// 🔹 Базовый тест — корректная инициализация и геттеры
TEST(TowelTest, InitializationAndGetters)
{
    Towel towel(19.99, "70x140", "cotton", "white");

    EXPECT_EQ(towel.get_size(), "70x140");
    EXPECT_EQ(towel.get_material(), "cotton");
    EXPECT_EQ(towel.get_color(), "white");
}