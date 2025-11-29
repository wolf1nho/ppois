#include <gtest/gtest.h>
#include "../Shop/proteinbar.h"

// 🔹 Тест базовой инициализации и геттеров
TEST(ProteinBarTest, InitializationAndGetters)
{
    ProteinBar bar(
        2.99,                // price
        "Quest",             // brand
        "Quest Protein Bar", // product_name
        "Chocolate Chip",    // flavor
        60.0,                // weight_grams
        200.0,               // total_calories
        21.0,                // protein_grams
        22.0,                // carbs_grams
        1.0,                 // sugar_grams
        8.0,                 // fat_grams
        14.0,                // fiber_grams
        true,                // vegan
        true,                // gluten_free
        true                 // low_sugar
    );

    EXPECT_EQ(bar.get_brand(), "Quest");
    EXPECT_EQ(bar.get_product_name(), "Quest Protein Bar");
    EXPECT_EQ(bar.get_flavor(), "Chocolate Chip");
    EXPECT_DOUBLE_EQ(bar.get_weight_grams(), 60.0);
    EXPECT_DOUBLE_EQ(bar.get_total_calories(), 200.0);
    EXPECT_DOUBLE_EQ(bar.get_protein_grams(), 21.0);
    EXPECT_DOUBLE_EQ(bar.get_carbs_grams(), 22.0);
    EXPECT_DOUBLE_EQ(bar.get_sugar_grams(), 1.0);
    EXPECT_DOUBLE_EQ(bar.get_fat_grams(), 8.0);
    EXPECT_DOUBLE_EQ(bar.get_fiber_grams(), 14.0);
    EXPECT_TRUE(bar.get_is_vegan());
    EXPECT_TRUE(bar.get_is_gluten_free());
    EXPECT_TRUE(bar.get_is_low_sugar());
}
