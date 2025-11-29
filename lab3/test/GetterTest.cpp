#include <gtest/gtest.h>

#include "../getter/Getter.h"

TEST(GetterTest, CurrencyGetters)
{
    EXPECT_EQ(Getter::getCurrency(Currency::BYN), "BYN");
    EXPECT_EQ(Getter::getCurrency(Currency::EUR), "EUR");
    EXPECT_EQ(Getter::getCurrency(Currency::USD), "USD");
}

TEST(GetterTest, TransactionTypeGetters)
{
    EXPECT_EQ(Getter::getTransactionType(TransactionType::PAYMENT), "payment");
    EXPECT_EQ(Getter::getTransactionType(TransactionType ::RETURN), "return");
    EXPECT_EQ(Getter::getTransactionType(TransactionType::SALARY), "salary");
    EXPECT_EQ(Getter::getTransactionType(TransactionType::TAX), "tax");
    EXPECT_EQ(Getter::getTransactionType(TransactionType::TRANSFER), "transfer");
}