#ifndef FLIPFLOPS_H
#define FLIPFLOPS_H
#include <string>
#include "good.h"

class FlipFlops : public Good
{
    std::string size; // "38", "39", "40", "41", "42"
    std::string color;
    std::string material; // "rubber", "eva", "plastic"

public:
    FlipFlops(double price, const std::string &size, const std::string &color, const std::string &material);

    std::string get_size() const;
    std::string get_color() const;
    std::string get_material() const;
};

#endif