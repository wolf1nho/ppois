#include "Towel.h"

Towel::Towel(double price, TowelSize size, Material material, Color color, Absorbency absorbency)
    : Good(price), size(size), material(material), color(color), absorbency(absorbency)
{
}