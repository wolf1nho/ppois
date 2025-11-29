#include <gtest/gtest.h>

#include "../card/Terminal.h"

TEST(TerminalTest, TerminalConstructorAndFunctions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCard(0, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    c1.addCurrentAccountAndCard(0, Currency::BYN, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Terminal t(c1.getAccount("1"), &dataManager);
    Card card = c.getCard("1");
    t.setAmount(1750, Currency::BYN);
    t.pay(card);
}