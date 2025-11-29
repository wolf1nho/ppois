#include <gtest/gtest.h>

#include "money/BanknoteValidator.h"
#include "money/Money.h"
#include "account/Currency.h"

TEST(BanknoteValidatorTest, Basics)
{
    BanknoteValidator bv;
    EXPECT_TRUE(bv.checkExistance(Nominal::N100, Currency::BYN));
    EXPECT_FALSE(bv.checkExistance(Nominal::N1, Currency::BYN));
}