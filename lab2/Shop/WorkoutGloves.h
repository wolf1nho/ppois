#ifndef WORKOUTGLOVES_H
#define WORKOUTGLOVES_H

#include <string>
#include "Good.h"
#include "Enums/Enums.h"

class WorkoutGloves : public Good
{
    Size size;
    Material material;
    bool wrist_support;

public:
    WorkoutGloves(
        double price,
        Size size,
        Material material,
        bool wrist_support);

    Size get_size() const { return size; }
    Material get_material() const { return material; }
    bool has_wrist_support() const { return wrist_support; }

    std::string get_size_str() const { return EnumToStr::to_string(size); }
    std::string get_material_str() const { return EnumToStr::to_string(material); }
};

#endif 