#include "ATMStorage.h"

ATMStorage::ATMStorage()
{
    storage[Currency::BYN] = {
        {Nominal::N500, 100},
        {Nominal::N200, 10000},
        {Nominal::N100, 10000},
        {Nominal::N50, 1000},
        {Nominal::N20, 1000},
        {Nominal::N10, 1000},
        {Nominal::N5, 1000}};

    storage[Currency::USD] = {
        {Nominal::N100, 100},
        {Nominal::N50, 1000},
        {Nominal::N20, 1000},
        {Nominal::N10, 1000},
        {Nominal::N5, 1000},
        {Nominal::N2, 1000},
        {Nominal::N1, 1000}};

    storage[Currency::EUR] = {
        {Nominal::N500, 100},
        {Nominal::N200, 10000},
        {Nominal::N100, 10000},
        {Nominal::N50, 1000},
        {Nominal::N20, 1000},
        {Nominal::N10, 1000},
        {Nominal::N5, 1000}};
}

const std::map<Nominal, int> &ATMStorage::getNominals(Currency cur) const
{
    return storage.at(cur);
}

void ATMStorage::bringMoney(std::vector<Money> &sum)
{
    for (int i = 0; i != sum.size();)
    {
        storage[sum[i].getCurrency()][sum[i].getNominal()]++;
        sum.erase(sum.begin());
    }
}