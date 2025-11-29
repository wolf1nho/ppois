#include "Wallet.h"
#include "../exception/Exception.h"

Wallet::Wallet()
{
    money[Currency::BYN] = {
        {Nominal::N500, 0},
        {Nominal::N200, 0},
        {Nominal::N100, 0},
        {Nominal::N50, 0},
        {Nominal::N20, 0},
        {Nominal::N10, 0},
        {Nominal::N5, 0}};

    money[Currency::USD] = {
        {Nominal::N100, 0},
        {Nominal::N50, 0},
        {Nominal::N20, 0},
        {Nominal::N10, 0},
        {Nominal::N5, 0},
        {Nominal::N2, 0},
        {Nominal::N1, 0}};

    money[Currency::EUR] = {
        {Nominal::N500, 0},
        {Nominal::N200, 0},
        {Nominal::N100, 0},
        {Nominal::N50, 0},
        {Nominal::N20, 0},
        {Nominal::N10, 0},
        {Nominal::N5, 0}};
}

std::vector<Money> Wallet::takeMoney(double amount, Currency currency)
{

    std::vector<Money> sumToAdd;

    for (auto it = money[currency].rbegin(); it != money[currency].rend(); ++it)
    {
        if (amount == 0)
            break;
        Nominal nominal = it->first;
        int &value = it->second;
        while (amount >= (double)nominal && amount > 0 && value != 0)
        {
            amount -= (double)nominal;
            value--;
            sumToAdd.emplace_back(nominal, currency);
        }
    }
    if (amount != 0)
    {
        bringMoneyToWallet(sumToAdd);
        throw Exception("Невозможно выдать данную сумму");
    }
    return sumToAdd;
}

void Wallet::bringMoneyToWallet(std::vector<Money> &sum)
{
    while (!sum.empty())
    {
        money[sum.front().getCurrency()][sum.front().getNominal()]++;
        sum.erase(sum.begin());
    }
}