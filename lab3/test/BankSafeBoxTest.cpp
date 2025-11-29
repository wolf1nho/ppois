#include <gtest/gtest.h>
#include "datamanager/DataManager.h"
#include "banksafebox/BankSafeBox.h"
#include "account/Currency.h"
#include "exception/Exception.h"

TEST(BankSafeBoxTest, Exceptions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);

    EXPECT_THROW(BankSafeBox(-10, &dataManager), ExceptionIncorrectPrice);
    EXPECT_THROW({ BankSafeBox b(10, &dataManager); b.getRenterName(); }, ExceptionSafeBoxError);
    EXPECT_THROW({ BankSafeBox b(10, &dataManager); b.unblock(); }, ExceptionSafeBoxError);
    EXPECT_THROW({ BankSafeBox b(10, &dataManager); b.free(); }, ExceptionSafeBoxError);
    EXPECT_THROW({ BankSafeBox b(10, &dataManager); 
        Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager); 
        b.rent(c);b.rent(c); }, ExceptionSafeBoxError);
}

TEST(BankSafeBoxTest, InitialStateAvailable)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    BankSafeBox b(50, &dataManager);
    EXPECT_EQ(b.getID().length(), 5);

    EXPECT_TRUE(b.isAvailable());
    EXPECT_EQ(b.getStatus(), BoxStatus::AVAILABLE);
    EXPECT_TRUE(b.isAvailable());
    EXPECT_FALSE(b.isRented());
    EXPECT_EQ(b.getRentDurationDays(), 0);
    b.rent(c);
    EXPECT_EQ(b.getRenterName(), c.getFullName());

    EXPECT_TRUE(b.isRented());
    EXPECT_EQ(b.getStatus(), BoxStatus::RENTED);
    b.block();
    EXPECT_EQ(b.getStatus(), BoxStatus::BLOCKED);
    b.unblock();
    EXPECT_EQ(b.getStatus(), BoxStatus::RENTED);
    EXPECT_EQ(b.getRentDurationDays(), 1);
    EXPECT_EQ(b.getPriceForRent(), 50);
    b.free();
    EXPECT_TRUE(b.isAvailable());
    EXPECT_EQ(b.getRentDurationDays(), 0);
    EXPECT_EQ(b.getPriceForRent(), 0);
    EXPECT_EQ(b.getPricePerDay(), 50);
    b.block();
    b.unblock();
    EXPECT_EQ(b.getStatus(), BoxStatus::AVAILABLE);
}
