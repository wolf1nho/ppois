#include <gtest/gtest.h>
#include "../Shop/swimminggoggles.h"

// 🔹 Базовый тест — корректная инициализация
TEST(SwimmingGogglesTest, InitializationAndGetters)
{
    SwimmingGoggles goggles(25.0, "blue", true, "medium");

    EXPECT_EQ(goggles.getLensColor(), "blue");
    EXPECT_TRUE(goggles.isAntiFog());
    EXPECT_EQ(goggles.getSize(), "medium");
}
