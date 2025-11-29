#include <gtest/gtest.h>

#include "money/CurrencyRateTableau.h"
#include "datamanager/DataManager.h"
#include "account/CurrencyConverter.h"
#include "account/Currency.h"

TEST(CurrencyRateTableauTest, Basics)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);

    EXPECT_EQ(CurrencyRateTableau::getCurrencyTableau(&dataManager), "EUR = 3.500000\nUSD = 3.000000\n");
}