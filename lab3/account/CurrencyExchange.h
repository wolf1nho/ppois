#ifndef CURRENCY_EXCHANGE_H
#define CURRENCY_EXCHANGE_H

#include <ctime>

#include "Currency.h"

class CurrencyExchange
{
    Currency from;
    Currency to;
    double amount;
    time_t exchangeTime;

public:
    CurrencyExchange(Currency from, Currency to, double amount);
    Currency getFromCurrency() const { return from; }
    Currency getToCurrency() const { return to; }
    double getAmount() const { return amount; }
};

#endif