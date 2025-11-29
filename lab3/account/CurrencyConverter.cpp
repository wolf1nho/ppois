#include "CurrencyConverter.h"
#include "exception/Exception.h"
#include "getter/Getter.h"

CurrencyConverter::CurrencyConverter(Currency baseCur, Currency second, double secondPrice, Currency third, double thirdPrice)
    : baseCurrency(baseCur)
{
    if (secondPrice < 0 && thirdPrice < 0)
        throw ExceptionIncorrectPrice("стоимость валюты меньше 0");
    converter[baseCur] = 1;
    converter[second] = secondPrice;
    converter[third] = thirdPrice;
}

double CurrencyConverter::convert(Currency first, Currency second, double amount)
{
    if (first == second)
        return amount;
    return amount * converter[first] / converter[second];
}

Currency CurrencyConverter::getBaseCurrency()
{
    return baseCurrency;
}
