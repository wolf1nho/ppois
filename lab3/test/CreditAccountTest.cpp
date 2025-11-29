#include <gtest/gtest.h>
#include <vector>

#include "../customer/Customer.h"
#include "../datamanager/DataManager.h"
#include "../account/CurrencyConverter.h"
#include "../account/Currency.h"
#include "../exception/Exception.h"
#include "../account/CurrentAccount.h"
#include "../account/Credit.h"
#include "../card/ATM.h"

TEST(CreditAccountTest, DepositAndWithdraw)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    // ATM atm(ATMState::IDLE, &dataManager);
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    EXPECT_TRUE(c.getAccount("кредит на дом")->withdraw(350));
    EXPECT_FALSE(c.getAccount("кредит на дом")->withdraw(350));
}

TEST(CreditAccountTest, Exceptions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    EXPECT_ANY_THROW(c.getAccount("кредит на дом")->deposit(100));
    EXPECT_ANY_THROW(c.getAccount("кредит на дом")->withdraw(0));
}
