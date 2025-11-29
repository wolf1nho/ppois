#include "CurrencyExchange.h"
#include "getter/TimeGetter.h"

CurrencyExchange::CurrencyExchange(Currency from, Currency to, double amount)
    : from(from), to(to), amount(amount), exchangeTime(TimeGetter::getTime())
{
}