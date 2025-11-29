#include <gtest/gtest.h>
#include "Human/Cleaner.h"

TEST(CleanerTest, Constructor_ValidInput_Success)
{
    PassKey key;
    Cleaner c("John",
              35,
              'm',
              "1990-05-10",
              true,
              &key,
              true,
              200.0,
              85.0,
              185,
              5,
              3000.0,
              "+123456789");
    EXPECT_EQ(c.get_work_experience(), 5u);
    EXPECT_DOUBLE_EQ(c.get_salary(), 3000.0);
    EXPECT_EQ(c.get_phone_number(), "+123456789");
}

TEST(CleanerTest, CleanArea_SetsRoomCleanedTrue)
{
    PassKey key;
    Cleaner c("Alex", 28, 'm', "1997-03-12", true, &key, false, 100.0, 70.0, 175, 2, 2500.0, "+987654321");

    Room room(25, false);
    c.clean_area(room);

    EXPECT_TRUE(room.is_cleaned());
}

TEST(CleanerTest, CleanMirror_SetsMirrorCleanedTrue)
{
    PassKey key;
    Cleaner c("Sarah", 32, 'f', "1992-11-05", true, &key, false, 150.0, 60.0, 170, 4, 2800.0, "+111222333");

    Mirror mirror(false, 25);
    c.clean_mirror(mirror);

    EXPECT_TRUE(mirror.is_cleaned());
}
