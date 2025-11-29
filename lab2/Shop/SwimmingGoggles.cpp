#include "SwimmingGoggles.h"

SwimmingGoggles::SwimmingGoggles(double price, LensColor lens_color, bool anti_fog,
                                 GoggleSize size, LensType lens_type)
    : Good(price), lens_color(lens_color), anti_fog(anti_fog), size(size), lens_type(lens_type) {}