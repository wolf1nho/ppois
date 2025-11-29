#include <gtest/gtest.h>
#include "Shop/WorkoutGloves.h"

TEST(WorkoutGlovesTest, Initialization)
{
    WorkoutGloves gloves(1200.0, Size::L, Material::Leather, true);

    EXPECT_DOUBLE_EQ(gloves.get_price(), 1200.0);
    EXPECT_EQ(gloves.get_size(), Size::L);
    EXPECT_EQ(gloves.get_material(), Material::Leather);
    EXPECT_TRUE(gloves.has_wrist_support());
}

TEST(WorkoutGlovesTest, ToStringConversions)
{
    WorkoutGloves powerGloves(1500.0, Size::XL, Material::Leather, true);
    WorkoutGloves breathable(900.0, Size::S, Material::Mesh, false);

    EXPECT_EQ(powerGloves.get_size_str(), "XL");
    EXPECT_EQ(powerGloves.get_material_str(), "leather");
    EXPECT_TRUE(powerGloves.has_wrist_support());

    EXPECT_EQ(breathable.get_size_str(), "S");
    EXPECT_EQ(breathable.get_material_str(), "mesh");
    EXPECT_FALSE(breathable.has_wrist_support());
}

TEST(WorkoutGlovesTest, WristSupportLogic)
{
    WorkoutGloves withSupport(1100.0, Size::M, Material::Synthetic, true);
    WorkoutGloves withoutSupport(700.0, Size::M, Material::Synthetic, false);

    EXPECT_TRUE(withSupport.has_wrist_support());
    EXPECT_FALSE(withoutSupport.has_wrist_support());
}