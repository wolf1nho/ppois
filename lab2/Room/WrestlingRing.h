#ifndef WRESTLINGRING_H
#define WRESTLINGRING_H
#include "Department.h"

class WrestlingRing : public Department
{
    bool wrestling_bag;

public:
    WrestlingRing(const double price, const double area, const bool wrestling_bag);
    bool has_wrestling_bag();
};

#endif