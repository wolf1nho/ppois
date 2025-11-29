#ifndef WALLET_H
#define WALLET_H

#include <map>
#include <vector>

#include "Money.h"
#include "../account/Currency.h"

class Wallet
{
    std::map<Currency, std::map<Nominal, int>> money;

public:
    Wallet();
    std::vector<Money> takeMoney(double amount, Currency currency);
    void bringMoneyToWallet(std::vector<Money> &sum);
};

#endif