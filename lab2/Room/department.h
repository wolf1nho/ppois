#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "room.h"

class Department : public Room
{
protected:
    friend class Subscription;

    double price;

public:
    Department(const double price, const double area);
};

#endif