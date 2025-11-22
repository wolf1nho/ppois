#ifndef SWIMMINGGOGGLES_H
#define SWIMMINGGOGGLES_H
#include <string>
#include "good.h"

class SwimmingGoggles : public Good
{
    std::string lens_color; // "clear", "blue", "mirrored", "smoke"
    bool is_anti_fog;
    std::string size; // "adult", "youth", "child"

public:
    SwimmingGoggles(double price, const std::string &lens_color, bool anti_fog, const std::string &size);

    std::string getLensColor() const;
    bool isAntiFog() const;
    std::string getSize() const;
};

#endif