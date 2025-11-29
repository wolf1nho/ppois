#include <gtest/gtest.h>

#include "../customer/Customer.h"
#include "../getter/TimeGetter.h"
#include "../money/Wallet.h"

TEST(OverdraftTest, Functions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCardWithOverdraft(10, Currency::EUR, 200, 5, 0, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    // Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    // c1.addCurrentAccountAndCard(0, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    // Terminal t(c1.getAccount("1"), &dataManager);
    Card card = c.getCard("1");
    // t.setAmount(1750, Currency::BYN);
    // t.pay(card);
    ATM atm(ATMState::IDLE, &dataManager);
    int pin = card.showPin();
    atm.insertCard(card);
    atm.enterPin(pin);
    Wallet w = c.getWallet();
    // sum.push_back(Money(Nominal::N500, Currency::EUR));
    // w.bringMoneyToWallet(sum);
    // atm.deposit(w.takeMoney(500, Currency::EUR));
    std::vector<Money> sum = atm.withdraw(10, Currency::EUR);
    w.bringMoneyToWallet(sum);
    sum = atm.withdraw(50, Currency::EUR);
    w.bringMoneyToWallet(sum);
    sum = atm.withdraw(30, Currency::EUR);
    w.bringMoneyToWallet(sum);
    EXPECT_DOUBLE_EQ(atm.getBalance(), -80);
    sum = w.takeMoney(50, Currency::EUR);
    atm.deposit(sum);
    EXPECT_DOUBLE_EQ(atm.getBalance(), -30);
    sum = w.takeMoney(30, Currency::EUR);
    atm.deposit(sum);
    EXPECT_DOUBLE_EQ(atm.getBalance(), 0);
}
