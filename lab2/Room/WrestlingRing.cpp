#include "WrestlingRing.h"

WrestlingRing::WrestlingRing(const double price, const double area,
                             const bool wrestling_bag)
    : Department(price, area), wrestling_bag(wrestling_bag) {}

bool WrestlingRing::has_wrestling_bag()
{
    return wrestling_bag;
}
