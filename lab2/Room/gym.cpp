#include "gym.h"

Gym::Gym(const double price, const double area, const bool crossbar, const unsigned trainer_count, const unsigned pancakes_count,
         const unsigned dumbbell_count, const unsigned barbell_count,
         const unsigned kettlebell_count, const unsigned strap_count)
    : Department(price, area), crossbar(crossbar),
      trainer_count(trainer_count), pancakes_count(pancakes_count),
      dumbbell_count(dumbbell_count), barbell_count(barbell_count),
      kettlebell_count(kettlebell_count), strap_count(strap_count) {}

bool Gym::is_crossbar() const
{
    return crossbar;
}

unsigned Gym::getTrainerCount() const
{
    return trainer_count;
}

unsigned Gym::getPancakesCount() const
{
    return pancakes_count;
}

unsigned Gym::getDumbbellCount() const
{
    return dumbbell_count;
}

unsigned Gym::getBarbellCount() const
{
    return barbell_count;
}

unsigned Gym::getKettlebellCount() const
{
    return kettlebell_count;
}

unsigned Gym::getStrapCount() const
{
    return strap_count;
}