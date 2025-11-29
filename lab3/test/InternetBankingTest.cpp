#include <gtest/gtest.h>
#include <string>

#include "../card/InternetBankingAccount.h"

TEST(InternerBankingTest, test1)
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
    ib.transfer(30, Currency::BYN, c1.getAccount("1"), TransactionType::TRANSFER);
    EXPECT_DOUBLE_EQ(c1.getAccount("1")->getBalance(), 30);
    EXPECT_DOUBLE_EQ(c.getAccount("1")->getBalance(), 290);

    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");
    ib.creditPayment(350, Currency::BYN, c.getCredit());
    EXPECT_TRUE(c.getCredit()->isRepaid());
}