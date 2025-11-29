#include "flipflops.h"

FlipFlops::FlipFlops(double price, Size size, Color color, Material material, std::string brand)
    : Good(price), size(size), color(color), material(material), brand(brand)
{
}