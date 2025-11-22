#ifndef WORKOUTGLOVES_H
#define WORKOUTGLOVES_H
#include <string>
#include "good.h"

class WorkoutGloves : public Good
{
    std::string size;     // "S", "M", "L", "XL"
    std::string material; // "leather", "synthetic", "mesh"
    bool wrist_support;

public:
    WorkoutGloves(double price, const std::string &size, const std::string &material, bool wrist_support);

    std::string get_size() const;
    std::string get_material() const;
    bool has_wrist_support() const;
};

#endif