#include <gtest/gtest.h>
#include "../Shop/good.h"
#include "../Exception/exception.h"

// Тест корректной инициализации и всех геттеров
TEST(GoodTest, InvalidConstructor)
{
    EXPECT_THROW({ Good g(-1); }, ExceptionIncorrectPrice);
}

TEST(GoodTest, GetPrice)
{
    double price = 10;
    Good g(price);
    EXPECT_EQ(g.get_price(), price);
}