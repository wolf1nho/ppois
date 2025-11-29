#ifndef BALL_H
#define BALL_H

#include <string>
#include "good.h"
#include "../Enums/enums.h"

class Ball : public Good
{
    BallType type;
    std::string diameter;
    Material material;
    double weight_kg;

public:
    Ball(double price, BallType type, const std::string &diameter, Material material, double weight_kg);

    BallType get_type() const { return type; }
    std::string get_diameter() const { return diameter; }
    Material get_material() const { return material; }
    double get_weight_kg() const { return weight_kg; }

    std::string get_type_str() const { return EnumToStr::to_string(type); }
    std::string get_material_str() const { return EnumToStr::to_string(material); }
};

#endif