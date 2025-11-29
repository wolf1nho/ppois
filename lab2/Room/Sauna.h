#ifndef SAUNA_H
#define SAUNA_H
#include "Department.h"

class Sauna : public Department
{
    unsigned max_temperature; 
    unsigned max_humidity;    // влажность в %
public:
    Sauna(const double price, const double area, const unsigned max_temperature, const unsigned max_humidity);
    unsigned getMaxTemperature() const;
    unsigned getMaxHumidity() const;
};

#endif