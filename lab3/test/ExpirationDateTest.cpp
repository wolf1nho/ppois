#include <gtest/gtest.h>
#include <string>

#include "../card/ExpirationDate.h"
#include "../getter/TimeGetter.h"


TEST(ExpirationDateTest, Functions)
{
    ExpirationDate expiry(TimeGetter::getTime());
    EXPECT_EQ(expiry.getMonth(), 11);
    EXPECT_EQ(expiry.getYear(), 2025);
    EXPECT_EQ(expiry.getExpirationDate(), std::to_string(TimeGetter::getThisMonth()) + "/" +std::to_string(TimeGetter::getThisYear()));
}