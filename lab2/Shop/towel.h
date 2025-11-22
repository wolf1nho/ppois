#ifndef TOWEL_H
#define TOWEL_H
#include <string>
#include "good.h"

class Towel : public Good
{
    std::string size;     // "small", "medium", "large", "xlarge"
    std::string material; // "cotton", "microfiber", "bamboo"
    std::string color;

public:
    Towel(double price, const std::string &size, const std::string &material, const std::string &color);

    std::string get_size() const;
    std::string get_material() const;
    std::string get_color() const;
};

#endif