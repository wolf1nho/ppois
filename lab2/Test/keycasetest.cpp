#include <gtest/gtest.h>

#include "../Reception/keycase.h"

TEST(KeyCaseTest, BasicsTest)
{
    KeyCase kc;
    EXPECT_TRUE(kc.is_empty());
    kc.add(PassKey(nullptr, 1, 'm'));
    EXPECT_FALSE(kc.is_empty());
}