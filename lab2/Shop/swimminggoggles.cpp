#include "swimminggoggles.h"

SwimmingGoggles::SwimmingGoggles(double price, const std::string &lens_color, bool anti_fog, const std::string &size)
    : Good(price), lens_color(lens_color), is_anti_fog(anti_fog), size(size) {}

std::string SwimmingGoggles::getLensColor() const { return lens_color; }
bool SwimmingGoggles::isAntiFog() const { return is_anti_fog; }
std::string SwimmingGoggles::getSize() const { return size; }