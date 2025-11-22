#include <gtest/gtest.h>
#include "../Shop/workoutgloves.h"

// 🔹 Проверка корректной инициализации и геттеров
TEST(WorkoutGlovesTest, BasicInitialization)
{
    WorkoutGloves gloves(29.99, "M", "leather", true);

    EXPECT_EQ(gloves.get_size(), "M");
    EXPECT_EQ(gloves.get_material(), "leather");
    EXPECT_TRUE(gloves.has_wrist_support());
}