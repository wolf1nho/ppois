#include <gtest/gtest.h>
#include "../Shop/swimmingcap.h"

// 🔹 Базовый тест — корректная инициализация
TEST(SwimmingCapTest, InitializationAndGetters)
{
    SwimmingCap cap(12.5, "silicone", "blue", "universal");

    EXPECT_EQ(cap.get_material(), "silicone");
    EXPECT_EQ(cap.get_color(), "blue");
    EXPECT_EQ(cap.get_size(), "universal");
}
