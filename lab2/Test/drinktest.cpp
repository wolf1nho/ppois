#include <gtest/gtest.h>
#include "../Shop/drink.h"
#include "../Exception/exception.h"

TEST(DrinkTest, InitializationAndGetters)
{
    Drink drink(
        2.5,              // price
        0.5,              // volume
        "Coca-Cola Zero", // drink_name
        true,             // carbonated
        false,            // milky
        false,            // energy_drink
        true,             // zero_sugar
        false,            // fruity
        "Cola",           // taste
        true,             // plastic
        false,            // glass
        false             // tin_can
    );

    EXPECT_DOUBLE_EQ(drink.get_volume(), 0.5);
    EXPECT_EQ(drink.get_drink_name(), "Coca-Cola Zero");
    EXPECT_TRUE(drink.is_carbonated());
    EXPECT_FALSE(drink.is_milky());
    EXPECT_FALSE(drink.is_energy_drink());
    EXPECT_TRUE(drink.is_zero_sugar());
    EXPECT_FALSE(drink.is_fruity());
    EXPECT_EQ(drink.get_taste(), "Cola");
    EXPECT_TRUE(drink.is_plastic());
    EXPECT_FALSE(drink.is_glass());
    EXPECT_FALSE(drink.is_tin_can());
}

TEST(DrinkTest, FruityEnergyDrinkGlass)
{
    Drink drink(
        3.99,
        0.33,
        "Monster Mango Loco",
        true,  // carbonated
        false, // milky
        true,  // energy
        false, // zero sugar
        true,  // fruity
        "Mango",
        false, // plastic
        true,  // glass
        false  // tin_can
    );

    EXPECT_TRUE(drink.is_energy_drink());
    EXPECT_TRUE(drink.is_fruity());
    EXPECT_EQ(drink.get_taste(), "Mango");
    EXPECT_TRUE(drink.is_glass());
}

TEST(DrinkTest, ThrowsOnInvalidPackaging)
{
    EXPECT_THROW({ Drink d(
                       2.0, 1.0, "Pepsi", true, false, false, false, false,
                       "Cola", true, true, false); }, ExceptionIncorrectPackaging);

    EXPECT_THROW({ Drink d(
                       2.0, 1.0, "Pepsi", true, false, false, false, false,
                       "Cola", false, true, true); }, ExceptionIncorrectPackaging);

    EXPECT_THROW({ Drink d(
                       2.0, 1.0, "Pepsi", true, false, false, false, false,
                       "Cola", true, false, true); }, ExceptionIncorrectPackaging);

    EXPECT_THROW({ Drink d(
                       2.0, 1.0, "Pepsi", true, false, false, false, false,
                       "Cola", false, false, false); }, ExceptionIncorrectPackaging);
}

TEST(DrinkTest, ThrowsOnInvalidVolume)
{
    EXPECT_THROW({ Drink d(1.5, -0.1, "Milk", false, true, false, false, false, "Vanilla", true, false, false); }, ExceptionIncorrectVolume);

    EXPECT_THROW({ Drink d(10.0, 6.0, "Water", false, false, false, false, false, "None", false, false, true); }, ExceptionIncorrectVolume);
}

TEST(DrinkTest, TinCanZeroSugarEnergyDrink)
{
    Drink drink(
        4.2,
        0.25,
        "Red Bull Zero",
        true,
        false,
        true,
        true,
        false,
        "Classic",
        false, // plastic
        false, // glass
        true   // tin_can
    );

    EXPECT_TRUE(drink.is_energy_drink());
    EXPECT_TRUE(drink.is_zero_sugar());
    EXPECT_TRUE(drink.is_tin_can());
    EXPECT_EQ(drink.get_taste(), "Classic");
}
