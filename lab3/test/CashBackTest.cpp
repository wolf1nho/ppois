#include <gtest/gtest.h>
#include <string>

#include "../card/InternetBankingAccount.h"
#include "../card/Cashback.h"

TEST(CashbackTest, test1)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCard(300, Currency::USD, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    c1.addCurrentAccountAndCard(0, Currency::BYN, PaymentSystem::Visa, CardType::DEBIT, "1", "1");

    Card card = c.getCard("1");

    std::string password = "12345";
    InternetBanking ib(password, &c, &dataManager);
    ib.login(password);
    ib.addCard(card);
    EXPECT_TRUE(ib.cardIsAdded(card));
    EXPECT_DOUBLE_EQ(ib.getBalance(), 300);
    EXPECT_EQ(ib.getProfileName(), "John Pork");

    EXPECT_DOUBLE_EQ(c.getAccount("1")->getBalance(), 300);
    ib.addCashbackFunction(10);
    EXPECT_DOUBLE_EQ(ib.getCashbackAmount(), 0);
    ib.TakeCashback();
    EXPECT_DOUBLE_EQ(c.getAccount("1")->getBalance(), 300);

    Terminal t(c1.getAccount("1"), &dataManager);
    t.setAmount(300, Currency::BYN);
    t.pay(card);
    EXPECT_DOUBLE_EQ(ib.getCashbackAmount(), 10);
    ib.TakeCashback();
    EXPECT_DOUBLE_EQ(c.getAccount("1")->getBalance(), 210);
    ib.logout();
}