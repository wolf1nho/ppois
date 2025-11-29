#include <gtest/gtest.h>
#include <vector>

#include "../account/Credit.h"
#include "../customer/Customer.h"
#include "../datamanager/DataManager.h"
#include "../account/CurrencyConverter.h"
#include "../account/Currency.h"
#include "../exception/Exception.h"
#include "../account/CurrentAccount.h"

TEST(CreditTest, Functions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    // ATM atm(ATMState::IDLE, &dataManager);
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    Credit *cr = c.getCredit();
    EXPECT_EQ(cr->getCurrentDebt(), 350);
    EXPECT_EQ(cr->getMonthlyPaymentAmount(), 350);
    EXPECT_EQ(cr->getInterestDebt(), 0);
    EXPECT_EQ(cr->getCurrentDebt(), 350);
    EXPECT_EQ(cr->getCurrentDebtWithoutInterest(), 350);
    EXPECT_EQ(cr->getCurrentDelayInDays(), 0);
    EXPECT_EQ(cr->getCurrentTotalDelayInDays(), 0);
}