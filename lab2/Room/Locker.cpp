#include "Locker.h"

Locker::Locker(const char gender, const unsigned num)
{
    locked = true;
    linked = false;
    this->num = num;
    passkey = nullptr;
    this->gender = gender;
    unsigned capacity;
    bool damaged = false;
    bool has_ventilation = false;
    bool has_mirror = false;
    std::string material = "wood";
    std::string color = "brown";
}

Locker::Locker(PassKey *passkey, const unsigned num, const char gender,
               const unsigned capacity, const bool damaged,
               const bool has_ventilation, const bool has_mirror,
               const std::string material, const std::string color)
{
    locked = true;
    linked = false;
    this->num = num;
    passkey->num = num;
    this->passkey = passkey;
    this->gender = gender;
    this->capacity = capacity;
    this->damaged = damaged;
    this->has_ventilation = has_ventilation;
    this->has_mirror = has_mirror;
    if (has_mirror)
        this->mirror = Mirror(true, 1.25);
    this->material = material;
    this->color = color;
}

bool Locker::is_locked()
{
    return locked;
}
bool Locker::is_opened()
{
    return !locked;
}

void Locker::link(PassKey *passkey)
{
    if (this->passkey->locker)
    {
        this->passkey->locker->unlink();
        this->passkey->unlink();
    }
    this->passkey = passkey;
    passkey->locker = this;
    this->num = passkey->num;
}

void Locker::unlink()
{
    passkey = nullptr;
    num = 0;
}

std::string Locker::get_color()
{
    return color;
}

std::string Locker::get_material()
{
    return material;
}

bool Locker::is_damaged()
{
    return damaged;
}

bool Locker::get_capacity()
{
    return capacity;
}

bool Locker::get_has_mirror()
{
    return has_mirror;
}

bool Locker::get_has_ventilation()
{
    return has_ventilation;
}