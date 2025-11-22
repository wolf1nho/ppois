#include <gtest/gtest.h>
#include "../Shop/flipflops.h"

// 🔹 Тест базовой инициализации и геттеров
TEST(FlipFlopsTest, InitializationAndGetters)
{
    FlipFlops ff(15.99, "41", "Black", "rubber");

    EXPECT_DOUBLE_EQ(ff.get_price(), 15.99);
    EXPECT_EQ(ff.get_size(), "41");
    EXPECT_EQ(ff.get_color(), "Black");
    EXPECT_EQ(ff.get_material(), "rubber");
}

// 🔹 Тест на другой цвет и материал
TEST(FlipFlopsTest, DifferentMaterial)
{
    FlipFlops ff(9.5, "39", "Blue", "eva");

    EXPECT_DOUBLE_EQ(ff.get_price(), 9.5);
    EXPECT_EQ(ff.get_size(), "39");
    EXPECT_EQ(ff.get_color(), "Blue");
    EXPECT_EQ(ff.get_material(), "eva");
}

// 🔹 Тест на пластиковые шлёпанцы другого размера
TEST(FlipFlopsTest, PlasticType)
{
    FlipFlops ff(7.99, "42", "Red", "plastic");

    EXPECT_DOUBLE_EQ(ff.get_price(), 7.99);
    EXPECT_EQ(ff.get_size(), "42");
    EXPECT_EQ(ff.get_color(), "Red");
    EXPECT_EQ(ff.get_material(), "plastic");
}
