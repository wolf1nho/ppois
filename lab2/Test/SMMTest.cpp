#include <gtest/gtest.h>
#include "Human/SMM.h"

TEST(SMMTest, Constructor_InitializesFieldsCorrectly)
{
    PassKey key;
    SMM smm("Alex", 25, 'm', "2000-01-01",
            true, &key, false,
            150.0, 75.0, 180, 3, 50000.0, "123456789",
            "alex_profile", "alex_tk",
            1000, 2000, 50, 100, 30, 10, "cool bio");

    EXPECT_EQ(smm.get_total_followers(), 3000u);
}

TEST(SMMTest, MakePost_IncreasesPostCount)
{
    PassKey key;
    SMM smm("Kate", 28, 'f', "1996-03-03",
            true, &key, true,
            200.0, 65.0, 170, 5, 60000.0, "987654321",
            "kate_profile", "kate_insta",
            500, 700, 10, 200, 50, 5, "bio");
    smm.check_followers();
    unsigned old_total = smm.get_total_followers();

    smm.make_post();
    smm.check_followers();

    EXPECT_EQ(smm.get_total_followers(), old_total);
}

TEST(SMMTest, CheckFollowers_SumsCorrectly)
{
    PassKey key;
    SMM smm("John", 30, 'm', "1994-12-12",
            true, &key, false,
            100.0, 80.0, 185, 4, 55000.0, "000111222",
            "john_profile", "john_tk",
            400, 600, 20, 200, 40, 10, "bio");

    smm.check_followers();
    EXPECT_EQ(smm.get_total_followers(), 1000);
}

TEST(SMMTest, Destructor_DeletesSocialMedia)
{
    PassKey key;
    EXPECT_NO_THROW({
        SMM smm("Liza", 26, 'f', "1999-06-15",
                true, &key, false,
                120.0, 55.0, 165, 2, 40000.0, "1122334455",
                "liza_profile", "liza_tt",
                300, 500, 15, 100, 20, 5, "bio");
    });
}
