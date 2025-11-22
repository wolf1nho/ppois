#include <gtest/gtest.h>
#include "../SM/sm.h"

// 🔹 Базовая проверка корректной инициализации и геттеров
TEST(SMTest, BasicInitialization)
{
    SM sm("FitnessBlog", "fit_guru", 25000, "Instagram", 120);

    EXPECT_EQ(sm.get_profile_name(), "FitnessBlog");
    EXPECT_EQ(sm.get_username(), "fit_guru");
    EXPECT_EQ(sm.get_followers_count(), 25000u);
    EXPECT_EQ(sm.get_SM_name(), "Instagram");
}
