#include "ball.h"

Ball::Ball(double price, BallType type, const std::string &diameter, Material material, double weight_kg)
    : Good(price), type(type), diameter(diameter), material(material), weight_kg(weight_kg)
{
}