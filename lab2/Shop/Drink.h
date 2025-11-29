#ifndef DRINKS_H
#define DRINKS_H
#include <string>
#include "Good.h"

class Drink : public Good
{
    double volume;
    std::string drink_name;
    bool carbonated;
    bool milky;
    bool energy_drink;
    bool zero_sugar;
    bool fruity;
    std::string taste;
    bool plastic;
    bool glass;
    bool tin_can;

public:
    Drink(double price, double volume, const std::string &drink_name,
          bool carbonated, bool milky, bool energy_drink, bool zero_sugar, bool fruity,
          const std::string &taste, bool plastic, bool glass, bool tin_can);

    double get_volume() const;
    std::string get_drink_name() const;
    bool is_carbonated() const;
    bool is_milky() const;
    bool is_energy_drink() const;
    bool is_zero_sugar() const;
    bool is_fruity() const;
    std::string get_taste() const;
    bool is_plastic() const;
    bool is_glass() const;
    bool is_tin_can() const;
};

#endif