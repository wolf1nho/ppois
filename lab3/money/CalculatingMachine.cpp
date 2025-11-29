#include "CalculatingMachine.h"

double CalculatingMachine::calculateMoney(std::vector<Money> sum, Currency currency, CurrencyConverter *cc)
{
    double amount = 0;
    for (auto it : sum)
    {
        amount += cc->convert(it.getCurrency(), currency, it.getAmount());
    }
    return amount;
}