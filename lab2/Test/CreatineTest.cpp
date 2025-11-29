#include <gtest/gtest.h>
#include "Shop/Creatine.h"

TEST(CreatineTest, InitializationAndGetters)
{
    Creatine creatine(
        24.99,
        "Optimum Nutrition",
        "Micronized Creatine Powder",
        "Powder",
        "Monohydrate",
        true,
        5,    
        5000, 
        60,  
        300, 
        "Unflavored",
        false,
        "USA",
        true);

    EXPECT_EQ(creatine.get_brand(), "Optimum Nutrition");
    EXPECT_EQ(creatine.get_product_name(), "Micronized Creatine Powder");
    EXPECT_EQ(creatine.get_form(), "Powder");
    EXPECT_EQ(creatine.get_type(), "Monohydrate");
    EXPECT_TRUE(creatine.get_is_micronized());
    EXPECT_EQ(creatine.get_serving_size_grams(), 5u);
    EXPECT_EQ(creatine.get_creatine_per_serving_mg(), 5000u);
    EXPECT_EQ(creatine.get_total_servings(), 60u);
    EXPECT_EQ(creatine.get_container_weight_grams(), 300u);
    EXPECT_EQ(creatine.get_flavor(), "Unflavored");
    EXPECT_FALSE(creatine.get_is_flavored());
    EXPECT_DOUBLE_EQ(creatine.get_price(), 24.99);
    EXPECT_EQ(creatine.get_country_of_origin(), "USA");
    EXPECT_TRUE(creatine.get_third_party_tested());
}
