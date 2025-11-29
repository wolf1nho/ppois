#include <gtest/gtest.h>
#include "Shop/Good.h"
#include "Exception/Exception.h"

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