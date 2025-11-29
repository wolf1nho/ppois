#include <gtest/gtest.h>
#include "account/AccountLimit.h"
#include <cmath>


TEST(AccountLimitTest, Constructor_InitializesCorrectly) {
    AccountLimit limit(100.0);
   
    EXPECT_TRUE(limit.canPerform(100.0));  
    EXPECT_FALSE(limit.canPerform(100.1)); 
}

TEST(AccountLimitTest, CanPerform_WithinLimit) {
    AccountLimit limit(200.0);
    EXPECT_TRUE(limit.canPerform(50.0));
    EXPECT_TRUE(limit.canPerform(200.0));
    EXPECT_TRUE(limit.canPerform(0.0));
}

TEST(AccountLimitTest, CanPerform_ExceedsLimit) {
    AccountLimit limit(100.0);
    EXPECT_FALSE(limit.canPerform(100.1));
    EXPECT_FALSE(limit.canPerform(150.0));
}

TEST(AccountLimitTest, AddUsage_IncreasesCurrentUsage) {
    AccountLimit limit(300.0);
    EXPECT_TRUE(limit.canPerform(200.0));

    limit.addUsage(150.0);
    EXPECT_TRUE(limit.canPerform(150.0)); 
    EXPECT_FALSE(limit.canPerform(150.1)); 

    limit.addUsage(100.0); 
    EXPECT_FALSE(limit.canPerform(60.0));  
}

TEST(AccountLimitTest, Reset_ClearsUsage) {
    AccountLimit limit(100.0);
    limit.addUsage(80.0);
    EXPECT_FALSE(limit.canPerform(30.0)); 

    limit.reset();
    EXPECT_TRUE(limit.canPerform(100.0)); 
    EXPECT_FALSE(limit.canPerform(100.1));
}