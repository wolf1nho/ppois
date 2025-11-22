#include "swimmingcap.h"

SwimmingCap::SwimmingCap(double price, const std::string &material, const std::string &color, const std::string &size)
    : Good(price), material(material), color(color), size(size) {}

std::string SwimmingCap::get_material() const { return material; }
std::string SwimmingCap::get_color() const { return color; }
std::string SwimmingCap::get_size() const { return size; }