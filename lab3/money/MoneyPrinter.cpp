#include "MoneyPrinter.h"
#include "exception/Exception.h"

MoneyPrinter::MoneyPrinter() : bv(BanknoteValidator())
{
}

std::vector<Money> MoneyPrinter::printMoney(Nominal nominal, Currency currency, int count)
{
    if (bv.checkExistance(nominal, currency))
        return std::vector<Money>(count, Money(nominal, currency));
    throw Exception("");
}