#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <map>
#include <string>

#include "Currency.h"

class CurrencyConverter
{
    friend class CurrencyRateTableau;
    std::map<Currency, double> converter;
    Currency baseCurrency;

public:
    CurrencyConverter(Currency baseCur, Currency second, double secondPrice, Currency third, double thirdPrice);
    double convert(Currency first, Currency second, double amount);
    Currency getBaseCurrency();
};

#endif