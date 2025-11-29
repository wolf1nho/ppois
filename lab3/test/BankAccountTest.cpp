#include <gtest/gtest.h>

#include "../account/BankAccount.h"
#include "../account/CurrencyConverter.h"
#include "../datamanager/DataManager.h"
#include "../customer/Customer.h"
#include "../exception/Exception.h"

TEST(BankAccountTest, ConstructorAndFunctions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    BankAccount *ba = new BankAccount(AccountType::Current, 0, Currency::BYN, "1", &c, &dataManager);
    ba->deposit(100);
    ba->freezeAccount();
    EXPECT_TRUE(ba->isFrozen());
    ba->unfreezeAccount();
    EXPECT_FALSE(ba->isFrozen());
    EXPECT_DOUBLE_EQ(ba->getBalance(), 100);
    EXPECT_TRUE(ba->withdraw(100));
    EXPECT_DOUBLE_EQ(ba->getBalance(), 0);
}

TEST(BankAccountTest, Exception)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    BankAccount *ba = new BankAccount(AccountType::Current, 0, Currency::BYN, "1", &c, &dataManager);
    EXPECT_THROW(ba->unfreezeAccount(), ExceptionFrozenAccount);
    ba->freezeAccount();
    EXPECT_THROW(ba->freezeAccount(), ExceptionFrozenAccount);
}