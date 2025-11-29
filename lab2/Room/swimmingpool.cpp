#include "swimmingpool.h"

SwimmingPool::SwimmingPool(const double price, const double area, const double depth, const double length,
                           const unsigned pool_paths_count, const double diving_tower_height)
    : Department(price, area), depth(depth), lenght(length),
      pool_paths_count(pool_paths_count),
      diving_tower_height(diving_tower_height) {}

double SwimmingPool::getDepth() const
{
    return depth;
}

double SwimmingPool::getLenght() const
{
    return lenght;
}

unsigned SwimmingPool::getPoolPathsCount() const
{
    return pool_paths_count;
}

double SwimmingPool::getDivingTowerHeight() const
{
    return diving_tower_height;
}