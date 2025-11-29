#include <gtest/gtest.h>
#include "../Room/swimmingpool.h"

// Тест на корректную инициализацию и геттеры
TEST(SwimmingPoolTest, InitializationAndGetters)
{
    double price = 12000.0;
    double area = 400.0;
    double depth = 2.5;
    double length = 25.0;
    unsigned pool_paths_count = 5;
    double diving_tower_height = 3.0;

    SwimmingPool pool(price, area, depth, length, pool_paths_count, diving_tower_height);

    EXPECT_DOUBLE_EQ(pool.getDepth(), depth);
    EXPECT_DOUBLE_EQ(pool.getLenght(), length);
    EXPECT_EQ(pool.getPoolPathsCount(), pool_paths_count);
    EXPECT_DOUBLE_EQ(pool.getDivingTowerHeight(), diving_tower_height);
}
