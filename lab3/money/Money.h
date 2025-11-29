#ifndef MONEY_H
#define MONEY_H

#include <vector>

#include "account/Currency.h"

enum class Nominal
{
    N500 = 500,
    N200 = 200,
    N100 = 100,
    N50 = 50,
    N20 = 20,
    N10 = 10,
    N5 = 5,
    N2 = 2,
    N1 = 1
};

class Money
{
    Nominal nominal;
    Currency currency;

public:
    Money(Nominal nominal, Currency currency);
    double getAmount() const;
    Currency getCurrency() const;
    Nominal getNominal() const;
    bool operator==(const Money &other) const;
};

#endif