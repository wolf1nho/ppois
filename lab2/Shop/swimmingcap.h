#ifndef SWIMMINGCAP_H
#define SWIMMINGCAP_H
#include <string>
#include "good.h"

class SwimmingCap : Good
{
    std::string material; // "silicone", "latex", "lycra"
    std::string color;
    std::string size; // "universal", "large", "child"

public:
    SwimmingCap(double price, const std::string &material, const std::string &color, const std::string &size);

    std::string get_material() const;
    std::string get_color() const;
    std::string get_size() const;
};

#endif