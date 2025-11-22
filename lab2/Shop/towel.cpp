#include "towel.h"

Towel::Towel(double price, const std::string &size, const std::string &material, const std::string &color)
    : Good(price), size(size), material(material), color(color) {}

std::string Towel::get_size() const { return size; }
std::string Towel::get_material() const { return material; }
std::string Towel::get_color() const { return color; }