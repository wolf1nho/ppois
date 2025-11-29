#include <gtest/gtest.h>
#include "Shop/SwimmingGoggles.h"

TEST(SwimmingGogglesTest, Initialization)
{
    SwimmingGoggles goggles(
        890.0,
        LensColor::Mirrored,
        true,
        GoggleSize::Adult,
        LensType::UVProtection);

    EXPECT_DOUBLE_EQ(goggles.get_price(), 890.0);
    EXPECT_EQ(goggles.get_lens_color(), LensColor::Mirrored);
    EXPECT_TRUE(goggles.is_anti_fog());
    EXPECT_EQ(goggles.get_size(), GoggleSize::Adult);
    EXPECT_EQ(goggles.get_lens_type(), LensType::UVProtection);
}

TEST(SwimmingGogglesTest, DefaultLensType)
{
    SwimmingGoggles basic(600.0, LensColor::Clear, false, GoggleSize::Youth, LensType::Standard);
    EXPECT_EQ(basic.get_lens_type(), LensType::Standard);
}

TEST(SwimmingGogglesTest, ToStringConversions)
{
    SwimmingGoggles competitionGoggles(
        1100.0,
        LensColor::Smoke,
        true,
        GoggleSize::Adult,
        LensType::Polarized);

    SwimmingGoggles kidsGoggles(
        450.0,
        LensColor::Blue,
        true,
        GoggleSize::Child,
        LensType::Standard);

    EXPECT_EQ(competitionGoggles.get_lens_color_str(), "smoke");
    EXPECT_EQ(competitionGoggles.get_size_str(), "adult");
    EXPECT_EQ(competitionGoggles.get_lens_type_str(), "polarized");
    EXPECT_TRUE(competitionGoggles.is_anti_fog());

    EXPECT_EQ(kidsGoggles.get_lens_color_str(), "blue");
    EXPECT_EQ(kidsGoggles.get_size_str(), "child");
    EXPECT_EQ(kidsGoggles.get_lens_type_str(), "standard");
    EXPECT_TRUE(kidsGoggles.is_anti_fog());
}

TEST(SwimmingGogglesTest, AntiFogProperty)
{
    SwimmingGoggles withAntiFog(950.0, LensColor::Yellow, true, GoggleSize::Adult, LensType::Standard);
    SwimmingGoggles withoutAntiFog(700.0, LensColor::Clear, false, GoggleSize::Adult, LensType::Standard);

    EXPECT_TRUE(withAntiFog.is_anti_fog());
    EXPECT_FALSE(withoutAntiFog.is_anti_fog());
}
