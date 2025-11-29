#include "Fitness.h"

Fitness::Fitness(const double price, const double area, const unsigned carpet_count, const unsigned elastic_band_count,
                 const unsigned hoop_count, const unsigned roller_count, const unsigned fitball_count, const unsigned treadmill_count)
    : Department(price, area), carpet_count(carpet_count), elastic_band_count(elastic_band_count), hoop_count(hoop_count), roller_count(roller_count), fitball_count(fitball_count), treadmill_count(treadmill_count)
{
}

unsigned Fitness::getCarpetCount() const
{
    return carpet_count;
}

unsigned Fitness::getElasticBandCount() const
{
    return elastic_band_count;
}

unsigned Fitness::getHoopCount() const
{
    return hoop_count;
}

unsigned Fitness::getRollerCount() const
{
    return roller_count;
}

unsigned Fitness::getFitballCount() const
{
    return fitball_count;
}

unsigned Fitness::getTreadmillCount() const
{
    return treadmill_count;
}
