#include "sauna.h"
#include "../Exception/exception.h"

Sauna::Sauna(const double price, const double area, const unsigned max_temperature, const unsigned max_humidity)
    : Department(price, area), max_temperature(max_temperature), max_humidity(max_humidity)
{
    if (max_humidity > 100)
        throw ExceptionHumidityError("Влажность от 0 до 100%");
}

unsigned Sauna::getMaxTemperature() const
{
    return max_temperature;
}

unsigned Sauna::getMaxHumidity() const
{
    return max_humidity;
}