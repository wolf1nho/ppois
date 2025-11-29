#include <gtest/gtest.h>
#include "../Room/gym.h"

// Тест на корректную инициализацию и геттеры
TEST(GymTest, InitializationAndGetters)
{
    double price = 25000.75;
    double area = 200.5;
    bool crossbar = true;
    unsigned trainer_count = 8;
    unsigned pancakes_count = 50;
    unsigned dumbbell_count = 30;
    unsigned barbell_count = 10;
    unsigned kettlebell_count = 12;
    unsigned strap_count = 4;

    Gym gym(price, area, crossbar, trainer_count, pancakes_count,
            dumbbell_count, barbell_count, kettlebell_count, strap_count);

    EXPECT_TRUE(gym.is_crossbar());
    EXPECT_EQ(gym.getTrainerCount(), trainer_count);
    EXPECT_EQ(gym.getPancakesCount(), pancakes_count);
    EXPECT_EQ(gym.getDumbbellCount(), dumbbell_count);
    EXPECT_EQ(gym.getBarbellCount(), barbell_count);
    EXPECT_EQ(gym.getKettlebellCount(), kettlebell_count);
    EXPECT_EQ(gym.getStrapCount(), strap_count);
}

TEST(GymTest, CrossbarFalse)
{
    Gym gym(15000.0, 180.0, false, 5, 20, 15, 7, 9, 2);

    EXPECT_FALSE(gym.is_crossbar());
    EXPECT_EQ(gym.getTrainerCount(), 5);
    EXPECT_EQ(gym.getPancakesCount(), 20);
    EXPECT_EQ(gym.getDumbbellCount(), 15);
    EXPECT_EQ(gym.getBarbellCount(), 7);
    EXPECT_EQ(gym.getKettlebellCount(), 9);
    EXPECT_EQ(gym.getStrapCount(), 2);
}
