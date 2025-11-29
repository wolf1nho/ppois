#include <gtest/gtest.h>
#include "../Room/sauna.h"
#include "../Exception/exception.h"

TEST(SaunaTest, InitializationAndGetters)
{
    double price = 5000.0;
    double area = 45.5;
    unsigned temp = 95;
    unsigned humidity = 60;

    Sauna sauna(price, area, temp, humidity);

    EXPECT_EQ(sauna.getMaxTemperature(), temp);
    EXPECT_EQ(sauna.getMaxHumidity(), humidity);
}

TEST(SaunaTest, HumidityBoundary)
{
    Sauna sauna_low(1000.0, 20.0, 80, 0);
    EXPECT_EQ(sauna_low.getMaxHumidity(), 0u);

    Sauna sauna_high(2000.0, 30.0, 90, 100);
    EXPECT_EQ(sauna_high.getMaxHumidity(), 100u);
}

TEST(SaunaTest, HumidityTooHighThrows)
{
    EXPECT_THROW(
        Sauna(1000.0, 20.0, 80, 101),
        ExceptionHumidityError);
}
