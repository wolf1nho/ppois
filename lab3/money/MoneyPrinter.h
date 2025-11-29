#ifndef MONEYPRINTER_H
#define MONEYPRINTER_H

#include <vector>

#include "Money.h"
#include "account/Currency.h"
#include "BanknoteValidator.h"

class MoneyPrinter
{
    BanknoteValidator bv;

public:
    MoneyPrinter();
    std::vector<Money> printMoney(Nominal nominal, Currency currency, int count);
};

#endif