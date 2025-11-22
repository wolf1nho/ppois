#ifndef SWIMMINGPOOL_H
#define SWIMMINGPOOL_H
#include "department.h"

class SwimmingPool : public Department
{
    double depth;
    double lenght;
    unsigned pool_paths_count;
    double diving_tower_height;

public:
    SwimmingPool(const double price, const double area, const double depth, const double length,
                 const unsigned pool_paths_count, const double diving_tower_height);

    double getDepth() const;
    double getLenght() const;
    unsigned getPoolPathsCount() const;
    double getDivingTowerHeight() const;
};

#endif