#include <gtest/gtest.h>
#include <vector>

#include "money/CalculatingMachine.h"

#include "money/Money.h"

TEST(CalculatingMachineTest, Basics)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    std::vector sum(4, Money(Nominal::N100, Currency::USD));
    sum.emplace_back(Nominal::N100, Currency::EUR);

    EXPECT_DOUBLE_EQ(CalculatingMachine::calculateMoney(sum, Currency::BYN, &converter), 1550);
}