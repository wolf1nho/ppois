#include <gtest/gtest.h>
#include "Shop/FlipFlops.h"

TEST(FlipFlopsTest, Initialization) {
    FlipFlops flipflops(550.0, Size::EU40, Color::Black, Material::Rubber, "Arena");

    EXPECT_DOUBLE_EQ(flipflops.get_price(), 550.0);
    EXPECT_EQ(flipflops.get_size(), Size::EU40);
    EXPECT_EQ(flipflops.get_color(), Color::Black);
    EXPECT_EQ(flipflops.get_material(), Material::Rubber);
    EXPECT_EQ(flipflops.get_brand(), "Arena");
}

TEST(FlipFlopsTest, DefaultBrandIsEmpty) {
    FlipFlops generic(400.0, Size::EU39, Color::Blue, Material::EVA, "");
    EXPECT_EQ(generic.get_brand(), "");
}

TEST(FlipFlopsTest, ToStringConversions) {
    FlipFlops summerFlipFlops(480.0, Size::EU39, Color::NeonGreen, Material::EVA, "Nike");
    FlipFlops classicFlipFlops(600.0, Size::EU42, Color::White, Material::Rubber, "Adidas");

    EXPECT_EQ(summerFlipFlops.get_size_str(), "39");
    EXPECT_EQ(summerFlipFlops.get_color_str(), "neon green");
    EXPECT_EQ(summerFlipFlops.get_material_str(), "eva");
    EXPECT_EQ(summerFlipFlops.get_brand(), "Nike");

    EXPECT_EQ(classicFlipFlops.get_size_str(), "42");
    EXPECT_EQ(classicFlipFlops.get_color_str(), "white");
    EXPECT_EQ(classicFlipFlops.get_material_str(), "rubber");
    EXPECT_EQ(classicFlipFlops.get_brand(), "Adidas");
}

TEST(FlipFlopsTest, BrandCanBeCustom) {
    FlipFlops branded(700.0, Size::EU41, Color::Red, Material::Plastic, "Nike");
    EXPECT_EQ(branded.get_brand(), "Nike");

    FlipFlops noBrand(300.0, Size::EU38, Color::Gray, Material::EVA, "");
    EXPECT_EQ(noBrand.get_brand(), "");
}