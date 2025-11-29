#ifndef GYM_H
#define GYM_H
#include "department.h"

class Gym : public Department
{
    bool crossbar;
    unsigned trainer_count;
    unsigned pancakes_count;
    unsigned dumbbell_count;
    unsigned barbell_count;
    unsigned kettlebell_count;
    unsigned strap_count;

public:
    Gym(const double price, const double area, const bool crossbar, const unsigned trainer_count, const unsigned pancakes_count,
        const unsigned dumbbell_count, const unsigned barbell_count,
        const unsigned kettlebell_count, const unsigned strap_count);
    bool is_crossbar() const;
    unsigned getTrainerCount() const;
    unsigned getPancakesCount() const;
    unsigned getDumbbellCount() const;
    unsigned getBarbellCount() const;
    unsigned getKettlebellCount() const;
    unsigned getStrapCount() const;
};

#endif