#include <gtest/gtest.h>
#include "Shop/ProteinBar.h"

TEST(ProteinBarTest, InitializationAndGetters)
{
    ProteinBar bar(
        2.99,               
        "Quest",           
        "Quest Protein Bar",
        "Chocolate Chip",    
        60.0,             
        200.0,             
        21.0,              
        22.0,              
        1.0,                 
        8.0,                 
        14.0,            
        true,           
        true,               
        true                 
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
