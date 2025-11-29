#ifndef TOWEL_H
#define TOWEL_H

#include <string>
#include "Good.h"
#include "Enums/Enums.h" 

class Towel : public Good
{
    TowelSize size;
    Material material;
    Color color;
    Absorbency absorbency;

public:
    Towel(double price, TowelSize size, Material material, Color color, Absorbency absorbency = Absorbency::Medium);

    TowelSize get_size() const { return size; }
    Material get_material() const { return material; }
    Color get_color() const { return color; }
    Absorbency get_absorbency() const { return absorbency; }

    std::string get_size_str() const { return EnumToStr::to_string(size); }
    std::string get_material_str() const { return EnumToStr::to_string(material); }
    std::string get_color_str() const { return EnumToStr::to_string(color); }
    std::string get_absorbency_str() const { return EnumToStr::to_string(absorbency); }
};

#endif