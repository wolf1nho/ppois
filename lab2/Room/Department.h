#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Room.h"

class Department : public Room
{
protected:
    friend class Subscription;

    double price;

public:
    Department(const double price, const double area);
};

#endif