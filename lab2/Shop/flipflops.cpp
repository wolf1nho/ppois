#include "flipflops.h"

FlipFlops::FlipFlops(double price, const std::string &size, const std::string &color, const std::string &material)
    : Good(price), size(size), color(color), material(material) {}

std::string FlipFlops::get_size() const { return size; }
std::string FlipFlops::get_color() const { return color; }
std::string FlipFlops::get_material() const { return material; }