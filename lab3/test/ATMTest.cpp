#include <gtest/gtest.h>
#include <vector>

#include "../customer/Customer.h"
#include "../datamanager/DataManager.h"
#include "../account/CurrencyConverter.h"
#include "../account/Currency.h"
#include "../exception/Exception.h"
#include "../account/CurrentAccount.h"
#include "../account/SavingsAccount.h"
#include "../account/Credit.h"
#include "../card/ATM.h"

TEST(ATMTest, Functions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    ATM atm(ATMState::IDLE, &dataManager);
    c.addCurrentAccountAndCard(0, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Card card = c.getCard("1");
    int pin = card.showPin();
    atm.insertCard(card);
    atm.enterPin(pin);
    Wallet w = c.getWallet();
    std::vector<Money> sum;
    sum.push_back(Money(Nominal::N500, Currency::EUR));
    w.bringMoneyToWallet(sum);
    atm.deposit(w.takeMoney(500, Currency::EUR));
    sum = atm.withdraw(350, Currency::BYN);
    w.bringMoneyToWallet(sum);
    EXPECT_DOUBLE_EQ(atm.getBalance(), 400);
    Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    c1.addCurrentAccountAndCard(0, Currency::BYN, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    atm.transfer(350, Currency::BYN, c1.getAccount("1"), pin, TransactionType::TRANSFER);
    EXPECT_DOUBLE_EQ(c1.getAccount("1")->getBalance(), 350);
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    atm.creditPayment(250, Currency::BYN, c.getCredit(), pin);
    atm.creditPayment(100, Currency::BYN, c.getCredit(), pin);
    atm.ejectCard();
}

TEST(ATMTest, Exceptions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    ATM atm(ATMState::IDLE, &dataManager);
    EXPECT_THROW(atm.ejectCard(), ExceptionATMError);
    EXPECT_THROW(atm.enterPin(0), ExceptionATMError);
    c.addCurrentAccountAndCard(0, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Card card = c.getCard("1");

    EXPECT_THROW({ ATM notworkingatm(ATMState::MAINTANANCE, &dataManager);
        notworkingatm.insertCard(card) ; }, ExceptionATMError);
    card.activate();
    card.freeze();
    EXPECT_THROW(atm.insertCard(card), ExceptionCardFreezeError);
    card.unfreeze();
    card.block();
    EXPECT_THROW(atm.insertCard(card), ExceptionCardBlockError);
    c.addNewCard(c.getAccount("1"), PaymentSystem::Belcard, CardType ::DEBIT, "2");
    c.getAccount("1")->freezeAccount();
    Card card2 = c.getCard("2");
    EXPECT_THROW(atm.insertCard(card2), ExceptionFrozenAccount);

    /* int pin = card.showPin();
    atm.insertCard(card);
    atm.enterPin(pin);
    Wallet w = c.getWallet();
    std::vector<Money> sum;
    sum.push_back(Money(Nominal::N500, Currency::EUR));
    w.bringMoneyToWallet(sum);
    atm.deposit(w.takeMoney(500, Currency::EUR));
    sum = atm.withdraw(350, Currency::BYN);
    w.bringMoneyToWallet(sum);
    EXPECT_DOUBLE_EQ(atm.getBalance(), 400);
    Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    c1.addCurrentAccountAndCard(0, Currency::BYN, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    atm.transfer(350, Currency::BYN, c1.getAccount("1"), pin, TransactionType::TRANSFER);
    EXPECT_DOUBLE_EQ(c1.getAccount("1")->getBalance(), 350);
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    atm.creditPayment(250, Currency::BYN, c.getCredit(), pin);
    atm.creditPayment(100, Currency::BYN, c.getCredit(), pin);
    atm.ejectCard(); */
}
