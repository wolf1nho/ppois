#include <gtest/gtest.h>
#include "Room/Room.h"
#include "Exception/Exception.h"

TEST(RoomTest, Constructor_ValidArea_DefaultCleaned)
{
    Room r(50.0);

    EXPECT_TRUE(r.is_cleaned()) << "По умолчанию комната должна быть чистой";
}

TEST(RoomTest, Constructor_ValidArea_CustomCleaned)
{
    Room r1(40.0, false);
    Room r2(60.0, true);

    EXPECT_FALSE(r1.is_cleaned()) << "Комната должна быть не убрана";
    EXPECT_TRUE(r2.is_cleaned()) << "Комната должна быть убрана";
}

TEST(RoomTest, Constructor_ThrowsOnZeroArea)
{
    EXPECT_THROW({ Room r(0.0); }, ExceptionIncorrectArea);
    EXPECT_THROW({ Room r(0.0, true); }, ExceptionIncorrectArea);
}

TEST(RoomTest, Constructor_ThrowsOnNegativeArea)
{
    EXPECT_THROW({ Room r(-5.0); }, ExceptionIncorrectArea);
    EXPECT_THROW({ Room r(-10.0, false); }, ExceptionIncorrectArea);
}
