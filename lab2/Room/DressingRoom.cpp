#include "DressingRoom.h"
#include <algorithm>

DressingRoom::DressingRoom(const double area,
                           Scales scales, const char gender)
    : Room(area), lockers(),
      scales(scales), gender(gender)
{
}

char DressingRoom::get_gender()
{
  return gender;
}

void DressingRoom::add_locker(const unsigned num)
{
  auto it = std::lower_bound(lockers.begin(), lockers.end(), num, [](const Locker &locker, unsigned int num)
                             { return locker.num < num; });
  lockers.insert(it, Locker(this->gender, num));
}