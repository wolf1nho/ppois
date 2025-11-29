#include <gtest/gtest.h>
#include "Room/DressingRoom.h"
#include "Room/Scales.h"

TEST(DressingRoomTest, InitializationAndGetter)
{
    double area = 50.0;
    Scales scales("Philips", "P-100", 180.0, 0.01,
                  true, false, false, true, false, 25.0);
    char gender = 'm';

    DressingRoom room(area, scales, gender);
    for (int i = 1; i <= 10; i++)
    {
        room.add_locker(i);
    }

    EXPECT_EQ(room.get_gender(), gender);
}

TEST(DressingRoomTest, FemaleDressingRoom)
{
    double area = 40.0;
    Scales scales("Philips", "P-100", 180.0, 0.01,
                  true, false, false, true, false, 25.0);
    char gender = 'f';

    DressingRoom room(area, scales, gender);
    for (int i = 1; i <= 10; i++)
    {
        room.add_locker(i);
    }

    EXPECT_EQ(room.get_gender(), gender);
}


TEST(DressingRoomTest, CustomGenderSymbol)
{
    Scales scales("Philips", "P-100", 180.0, 0.01,
                  true, false, false, true, false, 25.0);

    DressingRoom room(25.0, scales, 'm');

    EXPECT_EQ(room.get_gender(), 'm');
}
