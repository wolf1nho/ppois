#include <gtest/gtest.h>
#include "Shop/SwimmingCap.h"

TEST(SwimmingCapTest, Initialization)
{
    SwimmingCap cap(
        450.0,
        Material::Silicone,
        Color::Black,
        Size::Universal,
        WaterResistance::High,
        Elasticity::High);

    EXPECT_DOUBLE_EQ(cap.get_price(), 450.0);
    EXPECT_EQ(cap.get_material(), Material::Silicone);
    EXPECT_EQ(cap.get_color(), Color::Black);
    EXPECT_EQ(cap.get_size(), Size::Universal);
    EXPECT_EQ(cap.get_water_resistance(), WaterResistance::High);
    EXPECT_EQ(cap.get_elasticity(), Elasticity::High);
}

TEST(SwimmingCapTest, ToStringConversions)
{
    SwimmingCap siliconeCap(
        500.0,
        Material::Silicone,
        Color::NeonGreen,
        Size::Universal,
        WaterResistance::High,
        Elasticity::High);

    SwimmingCap lycraCap(
        200.0,
        Material::Lycra,
        Color::Pink,
        Size::Child,
        WaterResistance::Low,
        Elasticity::Medium);

    EXPECT_EQ(siliconeCap.get_material_str(), "silicone");
    EXPECT_EQ(siliconeCap.get_color_str(), "neon green");
    EXPECT_EQ(siliconeCap.get_size_str(), "universal");
    EXPECT_EQ(siliconeCap.get_water_resistance_str(), "high");
    EXPECT_EQ(siliconeCap.get_elasticity_str(), "high");

    EXPECT_EQ(lycraCap.get_material_str(), "lycra");
    EXPECT_EQ(lycraCap.get_size_str(), "child");
    EXPECT_EQ(lycraCap.get_water_resistance_str(), "low");
    EXPECT_EQ(lycraCap.get_elasticity_str(), "medium");
}

TEST(SwimmingCapTest, MaterialImpactsProperties)
{
    SwimmingCap cap(480.0, Material::Silicone, Color::White, Size::Universal, WaterResistance::High, Elasticity::High);
    EXPECT_EQ(cap.get_material_str(), "silicone");
    EXPECT_EQ(cap.get_water_resistance_str(), "high");
    EXPECT_EQ(cap.get_elasticity_str(), "high");
}
