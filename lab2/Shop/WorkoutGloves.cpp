#include "WorkoutGloves.h"

WorkoutGloves::WorkoutGloves(double price,
                             Size size,
                             Material material,
                             bool wrist_support)
    : Good(price), size(size), material(material), wrist_support(wrist_support)
{
}