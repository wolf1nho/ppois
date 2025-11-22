#ifndef SWIMWEAR_H
#define SWIMWEAR_H
#include <string>
#include "good.h"

class Swimwear : public Good
{
    std::string size;     // "S", "M", "L", "XL"
    std::string material; // "polyester", "nylon", "spandex"
    std::string color;
    std::string style; // "briefs", "trunks", "jammers"

public:
    Swimwear(double price, const std::string &size, const std::string &material,
             const std::string &color, const std::string &style);

    std::string get_size() const;
    std::string get_material() const;
    std::string get_color() const;
    std::string get_style() const;
};

#endif