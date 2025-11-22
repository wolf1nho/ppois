#include "swimwear.h"

Swimwear::Swimwear(double price, const std::string &size, const std::string &material,
                   const std::string &color, const std::string &style)
    : Good(price), size(size), material(material), color(color), style(style) {}

std::string Swimwear::get_size() const { return size; }
std::string Swimwear::get_material() const { return material; }
std::string Swimwear::get_color() const { return color; }
std::string Swimwear::get_style() const { return style; }