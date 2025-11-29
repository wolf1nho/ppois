#ifndef FLIPFLOPS_H
#define FLIPFLOPS_H

#include <string>
#include "good.h"
#include "../Enums/enums.h"

class FlipFlops : public Good
{
    Size size;
    Color color;
    Material material;
    std::string brand;

public:
    FlipFlops(double price, Size size, Color color, Material material, std::string brand);

    Size get_size() const { return size; }
    Color get_color() const { return color; }
    Material get_material() const { return material; }
    std::string get_brand() const { return brand; }

    std::string get_size_str() const { return EnumToStr::to_string(size); }
    std::string get_color_str() const { return EnumToStr::to_string(color); }
    std::string get_material_str() const { return EnumToStr::to_string(material); }
};

#endif