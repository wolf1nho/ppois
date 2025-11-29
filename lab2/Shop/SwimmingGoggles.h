#ifndef SWIMMINGGOGGLES_H
#define SWIMMINGGOGGLES_H

#include <string>
#include "Good.h"
#include "Enums/Enums.h"

class SwimmingGoggles : public Good
{
    LensColor lens_color;
    bool anti_fog;
    GoggleSize size;
    LensType lens_type;

public:
    SwimmingGoggles(double price, LensColor lens_color, bool anti_fog,
                    GoggleSize size, LensType lens_type);

    LensColor get_lens_color() const { return lens_color; }
    bool is_anti_fog() const { return anti_fog; }
    GoggleSize get_size() const { return size; }
    LensType get_lens_type() const { return lens_type; }

    std::string get_lens_color_str() { return EnumToStr::to_string(lens_color); }
    std::string get_size_str() { return EnumToStr::to_string(size); }
    std::string get_lens_type_str() { return EnumToStr::to_string(lens_type); }
};

#endif