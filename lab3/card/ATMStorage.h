#ifndef ATMSTORAGE_H
#define ATMSTORAGE_H

#include <map>

#include "money/Money.h"
#include "account/Currency.h"

class ATMStorage
{
private:
    std::map<Currency, std::map<Nominal, int>> storage;

public:
    ATMStorage();

    const std::map<Nominal, int> &getNominals(Currency cur) const;

    void bringMoney(std::vector<Money> &sum);
};

#endif