#ifndef JUMP_ROPE_H
#define JUMP_ROPE_H

#include <string>
#include "Good.h"
#include "Enums/Enums.h"

class JumpRope : public Good
{
    std::string length;
    Material material;
    HandleType handle_type;

public:
    JumpRope(double price, const std::string &length, Material material, HandleType handle_type);

    std::string get_length() const { return length; }
    Material get_material() const { return material; }
    HandleType get_handle_type() const { return handle_type; }

    std::string get_material_str() const { return EnumToStr::to_string(material); }
    std::string get_handle_type_str() const { return EnumToStr::to_string(handle_type); }
};

#endif