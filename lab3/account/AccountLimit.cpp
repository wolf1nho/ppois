#include "AccountLimit.h"

AccountLimit::AccountLimit(double maxAmount)
    : currentUsage(0), maxAmount(maxAmount)
{
}

bool AccountLimit::canPerform(const double amount) const
{
    return (currentUsage + amount) <= maxAmount;
}

void AccountLimit::addUsage(const double amount)
{
    currentUsage += amount;
}

void AccountLimit::reset()
{
    currentUsage = 0.0;
}