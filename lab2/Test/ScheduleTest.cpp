#include <gtest/gtest.h>
#include "Schedule/Schedule.h"

TEST(ScheduleTest, DefaultConstructor)
{
    Schedule schedule;
    EXPECT_EQ(schedule.get_open_time(), 7u);
    EXPECT_EQ(schedule.get_close_time(), 23u);
}

TEST(ScheduleTest, ValidCustomConstructor)
{
    Schedule schedule(8u, 20u);
    EXPECT_EQ(schedule.get_open_time(), 8u);
    EXPECT_EQ(schedule.get_close_time(), 20u);
}

TEST(ScheduleTest, InvalidOpenTime)
{
    EXPECT_THROW({ Schedule schedule(-1, 24); }, ExceptionIncorrectOpenAndCloseTime);
}

TEST(ScheduleTest, ThrowsWhenOpenAfterClose)
{
    EXPECT_THROW({ Schedule schedule(22u, 10u); }, ExceptionIncorrectOpenAndCloseTime);
}

TEST(ScheduleTest, ThrowsWhenInvalidTimeValue)
{
    EXPECT_THROW({ Schedule schedule(25u, 26u); }, ExceptionIncorrectTimeValue);
}

TEST(ScheduleTest, EdgeValues)
{
    Schedule schedule(0u, 23u);
    EXPECT_EQ(schedule.get_open_time(), 0u);
    EXPECT_EQ(schedule.get_close_time(), 23u);
}

TEST(ScheduleTest, AllDayValues)
{
    Schedule schedule(0u, 0u);
    EXPECT_EQ(schedule.get_open_time(), 0u);
    EXPECT_EQ(schedule.get_close_time(), 0u);
}
