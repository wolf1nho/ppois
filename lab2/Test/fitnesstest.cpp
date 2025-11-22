#include <gtest/gtest.h>
#include "../Room/fitness.h"

// Тест на корректность инициализации и геттеров
TEST(FitnessTest, InitializationAndGetters)
{
    // Данные для проверки
    double price = 12000.5;
    double area = 150.75;
    unsigned carpets = 10;
    unsigned elastic_bands = 15;
    unsigned hoops = 8;
    unsigned rollers = 5;
    unsigned fitballs = 12;
    unsigned treadmills = 3;

    Fitness fitness(price, area, carpets, elastic_bands, hoops, rollers, fitballs, treadmills);

    EXPECT_EQ(fitness.getCarpetCount(), carpets);
    EXPECT_EQ(fitness.getElasticBandCount(), elastic_bands);
    EXPECT_EQ(fitness.getHoopCount(), hoops);
    EXPECT_EQ(fitness.getRollerCount(), rollers);
    EXPECT_EQ(fitness.getFitballCount(), fitballs);
    EXPECT_EQ(fitness.getTreadmillCount(), treadmills);
}
