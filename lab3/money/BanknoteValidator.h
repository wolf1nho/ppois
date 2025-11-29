#ifndef BANKNOTEVALIDATOR_H
#define BANKNOTEVALIDATOR_H

#include <unordered_map>
#include <unordered_set>

#include "money/Money.h"
#include "account/Currency.h"

class BanknoteValidator
{
    std::unordered_map<Currency, std::unordered_set<Nominal>> denominations;

public:
    BanknoteValidator();
    bool checkExistance(Nominal nominal, Currency currency);
};

#endif