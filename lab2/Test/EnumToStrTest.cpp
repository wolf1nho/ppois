#include <gtest/gtest.h>
#include "Enums/Enums.h"

TEST(EnumToStrTest, Material)
{
    EXPECT_EQ(EnumToStr::to_string(Material::Rubber), "rubber");
    EXPECT_EQ(EnumToStr::to_string(Material::EVA), "eva");
    EXPECT_EQ(EnumToStr::to_string(Material::Plastic), "plastic");
    EXPECT_EQ(EnumToStr::to_string(Material::PVC), "pvc");
    EXPECT_EQ(EnumToStr::to_string(Material::Leather), "leather");
    EXPECT_EQ(EnumToStr::to_string(Material::Cotton), "cotton");
    EXPECT_EQ(EnumToStr::to_string(Material::Polyester), "polyester");
    EXPECT_EQ(EnumToStr::to_string(Material::Spandex), "spandex");
    EXPECT_EQ(EnumToStr::to_string(Material::Microfiber), "microfiber");
    EXPECT_EQ(EnumToStr::to_string(Material::Bamboo), "bamboo");
    EXPECT_EQ(EnumToStr::to_string(Material::Steel), "steel");
    EXPECT_EQ(EnumToStr::to_string(Material::Wood), "wood");
    EXPECT_EQ(EnumToStr::to_string(Material::Textile), "textile");
    EXPECT_EQ(EnumToStr::to_string(Material::Foam), "foam");
    EXPECT_EQ(EnumToStr::to_string(Material::Mesh), "mesh");
    EXPECT_EQ(EnumToStr::to_string(Material::Synthetic), "syntetic");
    EXPECT_EQ(EnumToStr::to_string(Material::Nylon), "nylon");
    EXPECT_EQ(EnumToStr::to_string(Material::Silicone), "silicone");
    EXPECT_EQ(EnumToStr::to_string(Material::Latex), "latex");
    EXPECT_EQ(EnumToStr::to_string(Material::Lycra), "lycra");
}

TEST(EnumToStrTest, Size)
{
    EXPECT_EQ(EnumToStr::to_string(Size::XS), "XS");
    EXPECT_EQ(EnumToStr::to_string(Size::S), "S");
    EXPECT_EQ(EnumToStr::to_string(Size::M), "M");
    EXPECT_EQ(EnumToStr::to_string(Size::L), "L");
    EXPECT_EQ(EnumToStr::to_string(Size::XL), "XL");
    EXPECT_EQ(EnumToStr::to_string(Size::XXL), "XXL");
    EXPECT_EQ(EnumToStr::to_string(Size::EU38), "38");
    EXPECT_EQ(EnumToStr::to_string(Size::EU39), "39");
    EXPECT_EQ(EnumToStr::to_string(Size::EU40), "40");
    EXPECT_EQ(EnumToStr::to_string(Size::EU41), "41");
    EXPECT_EQ(EnumToStr::to_string(Size::EU42), "42");
    EXPECT_EQ(EnumToStr::to_string(Size::Universal), "universal");
    EXPECT_EQ(EnumToStr::to_string(Size::Large), "large");
    EXPECT_EQ(EnumToStr::to_string(Size::Child), "child");
}

TEST(EnumToStrTest, BallType)
{
    EXPECT_EQ(EnumToStr::to_string(BallType::Fitball), "fitball");
    EXPECT_EQ(EnumToStr::to_string(BallType::Medball), "medball");
    EXPECT_EQ(EnumToStr::to_string(BallType::Pilates), "pilates");
    EXPECT_EQ(EnumToStr::to_string(BallType::Yoga), "yoga");
    EXPECT_EQ(EnumToStr::to_string(BallType::Exercise), "exercise");
}
TEST(EnumToStrTest, HandleType)
{
    EXPECT_EQ(EnumToStr::to_string(HandleType::Foam), "foam");
    EXPECT_EQ(EnumToStr::to_string(HandleType::Plastic), "plastic");
    EXPECT_EQ(EnumToStr::to_string(HandleType::Wood), "wood");
    EXPECT_EQ(EnumToStr::to_string(HandleType::Rubber), "rubber");
}

TEST(EnumToStrTest, Color)
{
    EXPECT_EQ(EnumToStr::to_string(Color::White), "white");
    EXPECT_EQ(EnumToStr::to_string(Color::Black), "black");
    EXPECT_EQ(EnumToStr::to_string(Color::Red), "red");
    EXPECT_EQ(EnumToStr::to_string(Color::Blue), "blue");
    EXPECT_EQ(EnumToStr::to_string(Color::Green), "green");
    EXPECT_EQ(EnumToStr::to_string(Color::NeonGreen), "neon green");
    EXPECT_EQ(EnumToStr::to_string(Color::Gray), "gray");
    EXPECT_EQ(EnumToStr::to_string(Color::Pink), "pink");
}

TEST(EnumToStrTest, SiWaterResistanceze)
{
    EXPECT_EQ(EnumToStr::to_string(WaterResistance::High), "high");
    EXPECT_EQ(EnumToStr::to_string(WaterResistance::Medium), "medium");
    EXPECT_EQ(EnumToStr::to_string(WaterResistance::Low), "low");
}
TEST(EnumToStrTest, Elasticity)
{
    EXPECT_EQ(EnumToStr::to_string(Elasticity::High), "high");
    EXPECT_EQ(EnumToStr::to_string(Elasticity::Medium), "medium");
    EXPECT_EQ(EnumToStr::to_string(Elasticity::Low), "low");
}

TEST(EnumToStrTest, LensColor)
{

    EXPECT_EQ(EnumToStr::to_string(LensColor::Clear), "clear");
    EXPECT_EQ(EnumToStr::to_string(LensColor::Blue), "blue");
    EXPECT_EQ(EnumToStr::to_string(LensColor::Mirrored), "mirrored");
    EXPECT_EQ(EnumToStr::to_string(LensColor::Smoke), "smoke");
    EXPECT_EQ(EnumToStr::to_string(LensColor::Yellow), "yellow");
    EXPECT_EQ(EnumToStr::to_string(LensColor::Pink), "pink");
    EXPECT_EQ(EnumToStr::to_string(LensColor::ClubBranded), "club");
}
TEST(EnumToStrTest, GoggleSize)
{
    EXPECT_EQ(EnumToStr::to_string(GoggleSize::Adult), "adult");
    EXPECT_EQ(EnumToStr::to_string(GoggleSize::Youth), "youth");
    EXPECT_EQ(EnumToStr::to_string(GoggleSize::Child), "child");
}

TEST(EnumToStrTest, LensType)
{

    EXPECT_EQ(EnumToStr::to_string(LensType::Standard), "standard");
    EXPECT_EQ(EnumToStr::to_string(LensType::UVProtection), "uv protection");
    EXPECT_EQ(EnumToStr::to_string(LensType::Polarized), "polarized");
    EXPECT_EQ(EnumToStr::to_string(LensType::Photochromic), "photochromic");
}

TEST(EnumToStrTest, SwimwearStyle)
{
    EXPECT_EQ(EnumToStr::to_string(SwimwearStyle::Briefs), "briefs");
    EXPECT_EQ(EnumToStr::to_string(SwimwearStyle::Trunks), "trunks");
    EXPECT_EQ(EnumToStr::to_string(SwimwearStyle::Jammers), "jammers");
    EXPECT_EQ(EnumToStr::to_string(SwimwearStyle::OnePiece), "one piece");
    EXPECT_EQ(EnumToStr::to_string(SwimwearStyle::Bikini), "bikini");
}

TEST(EnumToStrTest, TowelSize)
{
    EXPECT_EQ(EnumToStr::to_string(TowelSize::Small), "small");
    EXPECT_EQ(EnumToStr::to_string(TowelSize::Medium), "medium");
    EXPECT_EQ(EnumToStr::to_string(TowelSize::Large), "large");
    EXPECT_EQ(EnumToStr::to_string(TowelSize::XLarge), "xlarge");
}
TEST(EnumToStrTest, Absorbency)
{
    EXPECT_EQ(EnumToStr::to_string(Absorbency::Low), "low");
    EXPECT_EQ(EnumToStr::to_string(Absorbency::Medium), "medium");
    EXPECT_EQ(EnumToStr::to_string(Absorbency::High), "high");
}