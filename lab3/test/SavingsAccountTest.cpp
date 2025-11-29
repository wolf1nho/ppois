#include <gtest/gtest.h>

#include "../account/BankAccount.h"
#include "../account/CurrencyConverter.h"
#include "../datamanager/DataManager.h"
#include "../customer/Customer.h"
#include "../account/SavingsAccount.h"
#include "../exception/Exception.h"

TEST(SavingsAccountTest, NotRevocableSavingsAccountConstructor)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    SavingsAccount *sa = new SavingsAccount(0, Currency::BYN, "1", 10, &c, &dataManager);
    c.getAccount("1")->deposit(100);
    EXPECT_THROW(c.getAccount("1")->withdraw(100), Exception);
    sa->applyDailyInterest();
    EXPECT_DOUBLE_EQ(sa->getBalance(), 100);
}

TEST(SavingsAccountTest, RevocableSavingsAccountConstructor)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    SavingsAccount *sa = new SavingsAccount(0, Currency::BYN, "1", 10, 200, &c, &dataManager);
    c.getAccount("1")->deposit(100);
    EXPECT_FALSE(c.getAccount("1")->withdraw(100));
    c.getAccount("1")->deposit(100);
    EXPECT_FALSE(c.getAccount("1")->withdraw(100));
    c.getAccount("1")->deposit(100);
    EXPECT_TRUE(c.getAccount("1")->withdraw(100));
}