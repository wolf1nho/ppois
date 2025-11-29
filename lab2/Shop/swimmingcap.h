#ifndef SWIMMINGCAP_H
#define SWIMMINGCAP_H

#include <string>
#include "good.h"
#include "../Enums/enums.h"

class SwimmingCap : public Good
{
    Material material;
    Color color;
    Size size;
    WaterResistance water_resistance;
    Elasticity elasticity;

public:
    SwimmingCap(double price, Material material, Color color,
                Size size, WaterResistance water_resistance,
                Elasticity elasticity);

    Material get_material() const { return material; }
    Color get_color() const { return color; }
    Size get_size() const { return size; }
    WaterResistance get_water_resistance() const { return water_resistance; }
    Elasticity get_elasticity() const { return elasticity; }

    std::string get_material_str() const { return EnumToStr::to_string(material); }
    std::string get_color_str() const { return EnumToStr::to_string(color); }
    std::string get_size_str() const { return EnumToStr::to_string(size); }
    std::string get_water_resistance_str() { return EnumToStr::to_string(water_resistance); }
    std::string get_elasticity_str() { return EnumToStr::to_string(elasticity); }
};

#endif