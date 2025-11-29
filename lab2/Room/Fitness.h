#ifndef FITNESS_H
#define FITNESS_H
#include "Department.h"

class Fitness : public Department
{
    unsigned carpet_count;
    unsigned elastic_band_count;
    unsigned hoop_count;
    unsigned roller_count;
    unsigned fitball_count;
    unsigned treadmill_count;

public:
    Fitness(const double price, const double area, const unsigned carpet_count, const unsigned elastic_band_count,
            const unsigned hoop_count, const unsigned roller_count, const unsigned fitball_count, const unsigned treadmill_count);
    unsigned getCarpetCount() const;
    unsigned getElasticBandCount() const;
    unsigned getHoopCount() const;
    unsigned getRollerCount() const;
    unsigned getFitballCount() const;
    unsigned getTreadmillCount() const;
};

#endif