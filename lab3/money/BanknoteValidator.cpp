#include "BanknoteValidator.h"

BanknoteValidator::BanknoteValidator()
{
    denominations[Currency::BYN] = {Nominal::N5,
                                    Nominal::N10,
                                    Nominal::N20,
                                    Nominal::N50,
                                    Nominal::N100,
                                    Nominal::N200,
                                    Nominal::N500};
    denominations[Currency::EUR] = {Nominal::N5,
                                    Nominal::N10,
                                    Nominal::N20,
                                    Nominal::N50,
                                    Nominal::N100,
                                    Nominal::N200,
                                    Nominal::N500};
    denominations[Currency::EUR] = {Nominal::N1,
                                    Nominal::N2,
                                    Nominal::N5,
                                    Nominal::N10,
                                    Nominal::N20,
                                    Nominal::N50,
                                    Nominal::N100};
}

bool BanknoteValidator::checkExistance(Nominal nominal, Currency currency)
{
    auto it = denominations.find(currency);
    return it->second.count(nominal) > 0;
}