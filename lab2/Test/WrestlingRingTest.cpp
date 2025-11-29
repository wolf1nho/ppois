#include <gtest/gtest.h>
#include "Room/WrestlingRing.h"

TEST(WrestlingRingTest, InitializationAndGetter)
{
    double price = 8000.0;
    double area = 100.0;
    bool has_bag = true;

    WrestlingRing ring(price, area, has_bag);
    EXPECT_TRUE(ring.has_wrestling_bag());
}

TEST(WrestlingRingTest, WithoutWrestlingBag)
{
    WrestlingRing ring(5000.0, 80.0, false);
    EXPECT_FALSE(ring.has_wrestling_bag());
}
