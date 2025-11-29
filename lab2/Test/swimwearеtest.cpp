#include <gtest/gtest.h>
#include "Shop/swimwear.h"

// Тест: корректная инициализация
TEST(SwimwearTest, Initialization)
{
    Swimwear swimwear(1200.0, Size::M, Material::Polyester, Color::Blue, SwimwearStyle::Jammers);

    EXPECT_DOUBLE_EQ(swimwear.get_price(), 1200.0);
    EXPECT_EQ(swimwear.get_size(), Size::M);
    EXPECT_EQ(swimwear.get_material(), Material::Polyester);
    EXPECT_EQ(swimwear.get_color(), Color::Blue);
    EXPECT_EQ(swimwear.get_style(), SwimwearStyle::Jammers);
}

// Тест: строковое представление размера
TEST(SwimwearTest, SizeToString)
{
    Swimwear swimwear(1000.0, Size::L, Material::Nylon, Color::Black, SwimwearStyle::Trunks);
    EXPECT_EQ(swimwear.get_size_str(), "L");
}

// Тест: строковое представление стиля
TEST(SwimwearTest, StyleToString)
{
    Swimwear briefs(800.0, Size::S, Material::Spandex, Color::Red, SwimwearStyle::Briefs);
    Swimwear bikini(950.0, Size::M, Material::Polyester, Color::Pink, SwimwearStyle::Bikini);
    Swimwear onepiece(1100.0, Size::L, Material::Nylon, Color::Black, SwimwearStyle::OnePiece);

    EXPECT_EQ(briefs.get_style_str(), "briefs");
    EXPECT_EQ(bikini.get_style_str(), "bikini");
    EXPECT_EQ(onepiece.get_style_str(), "one piece");
}

// Тест: материал и цвет
TEST(SwimwearTest, MaterialAndColor)
{
    Swimwear suit(1300.0, Size::XL, Material::Polyester, Color::NeonGreen, SwimwearStyle::Jammers);

    EXPECT_EQ(suit.get_material_str(), "polyester");
    EXPECT_EQ(suit.get_color_str(), "neon green");
}