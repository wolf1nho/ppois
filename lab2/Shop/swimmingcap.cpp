#include "swimmingcap.h"

SwimmingCap::SwimmingCap(double price,
                         Material material,
                         Color color,
                         Size size,
                         WaterResistance water_resistance,
                         Elasticity elasticity)
    : Good(price),
      material(material),
      color(color),
      size(size),
      water_resistance(water_resistance),
      elasticity(elasticity)
{
}