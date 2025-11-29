#include "jumprope.h"

JumpRope::JumpRope(double price, const std::string &length, Material material, HandleType handle_type)
    : Good(price), length(length), material(material), handle_type(handle_type)
{
}