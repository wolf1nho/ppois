#include <gtest/gtest.h>

#include "../card/Card.h"
#include "../getter/TimeGetter.h"

TEST(CardTest, Functions)
{
    CurrencyConverter converter(Currency::BYN, Currency::EUR, 3.5, Currency::USD, 3);
    DataManager dataManager(&converter);
    Customer c("John", "Pork", "AB1234567", "+375291234567", "johnpork@gmail.com", "Minsk", &dataManager);
    c.addCurrentAccountAndCardWithOverdraft(10, Currency::EUR, 200, 5, 0, PaymentSystem::Visa, CardType::DEBIT, "1", "1");
    EXPECT_ANY_THROW(c.addCurrentAccountAndCardWithOverdraft(10, Currency::EUR, 200, 5, 0, PaymentSystem::Visa, CardType::DEBIT, "1", "1"));
    EXPECT_ANY_THROW(c.addCurrentAccountAndCardWithOverdraft(10, Currency::EUR, 200, 5, 0, PaymentSystem::Visa, CardType::CREDIT, "2", "2"));
    Card card = c.getCard("1");
    card.activate();
    card.getCardNum();
    card.freeze();
    card.unfreeze();
    card.block();

}