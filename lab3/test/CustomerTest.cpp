#include <gtest/gtest.h>
#include "../customer/Customer.h"
#include "../datamanager/DataManager.h"
#include "../account/CurrencyConverter.h"
#include "../account/Currency.h"
#include "../exception/Exception.h"
#include "../account/CurrentAccount.h"
#include "../account/SavingsAccount.h"
#include "../account/Credit.h"

TEST(CustomerTest, ConstructorCreatesCustomerCorrectly)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);

    EXPECT_EQ(c.getFullName(), "John Pork");
    EXPECT_EQ(c.getPassportNumber(), "AB1234567");
    EXPECT_EQ(c.getPhoneNumber(), "+375291234567");
    EXPECT_EQ(c.getEmail(), "johnpork@gmail.com");
    EXPECT_EQ(c.getAddress(), "Minsk");
    EXPECT_TRUE(c.getVerificationStatus());
}

TEST(CustomerTest, Setters)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);

    c.setAddress("Moskow");
    c.setEmail("hello@gmail.com");
    c.setPhoneNumber("+375331234567");
    EXPECT_EQ(c.getPhoneNumber(), "+375331234567");
    EXPECT_EQ(c.getAddress(), "Moskow");
    c.verify();
    EXPECT_TRUE(c.getVerificationStatus());
    c.setVerified(false);
    EXPECT_FALSE(c.getVerificationStatus());
}

TEST(CustomerTest, TakeCredit)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);

    c.takeCreditAndCreditCard(100, Currency::BYN, 1, 2, true, PaymentSystem::Belcard, "кредит на дом", "1");
    EXPECT_THROW(c.addNewCard(c.getAccount("кредит на дом"), PaymentSystem::Visa, CardType::VIRTUAL, "2"), Exception);
    EXPECT_THROW(c.takeCreditAndCreditCard(1000, Currency::BYN, 5, 10, true, PaymentSystem::Belcard, "кредит на дом 2", "2"), Exception);
}
