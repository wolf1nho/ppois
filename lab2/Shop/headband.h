#ifndef HEADBAND_H
#define HEADBAND_H

#include <string>
#include "good.h"
#include "Enums/enums.h"

class Headband : public Good
{
    Material material;
    Color color;
    Size size;

public:
    Headband(double price, Material material, Color color, Size size);

    Material get_material() const { return material; }
    Color get_color() const { return color; }
    Size get_size() const { return size; }

    std::string get_material_str() const { return EnumToStr::to_string(material); }
    std::string get_color_str() const { return EnumToStr::to_string(color); }
    std::string get_size_str() const { return EnumToStr::to_string(size); }
};

#endif