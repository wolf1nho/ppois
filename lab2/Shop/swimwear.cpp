#include "swimwear.h"

Swimwear::Swimwear(double price, Size size, Material material, Color color, SwimwearStyle style)
    : Good(price), size(size), material(material), color(color), style(style)
{
}