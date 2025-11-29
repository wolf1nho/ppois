#include <gtest/gtest.h>
#include "Shop/Towel.h"

TEST(TowelTest, Initialization) {
    Towel towel(450.0, TowelSize::Large, Material::Microfiber, Color::Blue, Absorbency::High);

    EXPECT_DOUBLE_EQ(towel.get_price(), 450.0);
    EXPECT_EQ(towel.get_size(), TowelSize::Large);
    EXPECT_EQ(towel.get_material(), Material::Microfiber);
    EXPECT_EQ(towel.get_color(), Color::Blue);
    EXPECT_EQ(towel.get_absorbency(), Absorbency::High);
}

TEST(TowelTest, DefaultAbsorbency) {
    Towel towel(300.0, TowelSize::Medium, Material::Cotton, Color::White);
    EXPECT_EQ(towel.get_absorbency(), Absorbency::Medium);
}

TEST(TowelTest, ToStringConversions) {
    Towel yogaTowel(350.0, TowelSize::Small, Material::Microfiber, Color::NeonGreen, Absorbency::High);
    Towel beachTowel(600.0, TowelSize::XLarge, Material::Cotton, Color::Red, Absorbency::Medium);

    EXPECT_EQ(yogaTowel.get_size_str(), "small");
    EXPECT_EQ(yogaTowel.get_material_str(), "microfiber");
    EXPECT_EQ(yogaTowel.get_color_str(), "neon green");
    EXPECT_EQ(yogaTowel.get_absorbency_str(), "high");

    EXPECT_EQ(beachTowel.get_size_str(), "xlarge");
    EXPECT_EQ(beachTowel.get_absorbency_str(), "medium");
}

TEST(TowelTest, MaterialImpliesAbsorbencyHint) {
    Towel microfiberTowel(500.0, TowelSize::Large, Material::Microfiber, Color::Black, Absorbency::High);
    EXPECT_EQ(microfiberTowel.get_material_str(), "microfiber");
    EXPECT_EQ(microfiberTowel.get_absorbency_str(), "high");
}