#include <gtest/gtest.h>

#include "money/MoneyPrinter.h"
#include "exception/Exception.h"

TEST(MoneyPrinterTest, Basics)
{
    MoneyPrinter mp;
    Nominal nominal = Nominal::N100;
    Currency currency = Currency::EUR;
    int count = 5;
    EXPECT_EQ(mp.printMoney(nominal, currency, count), std::vector<Money>(count, Money(nominal, currency)));
    EXPECT_THROW(mp.printMoney(Nominal::N200, currency, count), Exception);
}