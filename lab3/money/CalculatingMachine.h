#ifndef CALCULATINGMACHINE_H
#define CALCULATINGMACHINE_H

#include <vector>
#include "money/Money.h"
#include "account/Currency.h"
#include "account/CurrencyConverter.h"

class CalculatingMachine
{
public:
    static double calculateMoney(std::vector<Money> sum, Currency currency, CurrencyConverter *cc);
};

#endif