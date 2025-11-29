#ifndef DRESSINGROOM_H
#define DRESSINGROOM_H
#include "room.h"
#include <vector>
#include "locker.h"
#include "scales.h"

class Scales;

class DressingRoom : public Room
{
public:
    Scales scales;
    std::vector<Locker> lockers;
    char gender;

    DressingRoom(const double area, Scales scales, const char gender);
    char get_gender();
    void add_locker(const unsigned num);
};

#endif