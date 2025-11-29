#include <gtest/gtest.h>

#include "../account/Receipt.h"
#include "../customer/Customer.h"

TEST(ReceiptTest, AccountTransactionReceipt)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCard(100, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    Card card = c.getCard("1");
    Customer c1("Alex", "Feduk", "AB2234567", "+375331234567", "feduk@gmail.com", "Minsk", &dataManager);
    c1.addCurrentAccountAndCard(0, Currency::BYN, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    AccountTransaction *transaction = new AccountTransaction(c.getAccount("1"), c1.getAccount("1"), 100, Currency::EUR, TransactionType::TRANSFER, &dataManager);
    transaction->execute();
    Receipt r(*transaction);
    std::cout << r.getStr();
}

TEST(ReceiptTest, CreditPaymentReceipt)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCard(100, Currency::EUR, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    c.takeCreditAndCreditCard(350, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "2");

    c.getCredit()->getPayment()->setFromAccount(c.getAccount("1"));
    c.getCredit()->getPayment()->setAmount(350, Currency::BYN);
    c.getCredit()->getPayment()->execute();
    Receipt r(*c.getCredit()->getPayment());
    std::cout << r.getStr();
}