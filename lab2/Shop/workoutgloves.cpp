#include "workoutgloves.h"

WorkoutGloves::WorkoutGloves(double price, const std::string &size, const std::string &material, bool wrist_support)
    : Good(price), size(size), material(material), wrist_support(wrist_support) {}

std::string WorkoutGloves::get_size() const { return size; }
std::string WorkoutGloves::get_material() const { return material; }
bool WorkoutGloves::has_wrist_support() const { return wrist_support; }