#ifndef SWIMWEAR_H
#define SWIMWEAR_H

#include <string>
#include "Good.h"
#include "Enums/Enums.h"

class Swimwear : public Good
{
    Size size;
    Material material;
    Color color;
    SwimwearStyle style;

public:
    Swimwear(double price, Size size, Material material, Color color, SwimwearStyle style);

    Size get_size() const { return size; }
    Material get_material() const { return material; }
    Color get_color() const { return color; }
    SwimwearStyle get_style() const { return style; }

    std::string get_size_str() const { return EnumToStr::to_string(size); }
    std::string get_material_str() const { return EnumToStr::to_string(material); }
    std::string get_color_str() const { return EnumToStr::to_string(color); }
    std::string get_style_str() const { return EnumToStr::to_string(style); }
};

#endif