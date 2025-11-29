#include <gtest/gtest.h>
#include "Human/Administrator.h"
#include "Schedule/Schedule.h"
#include "Human/Trainer.h"

TEST(AdministratorTest, ChangeScheduleTimes)
{
    PassKey key;
    Administrator admin("Bob", 45, 'm', "1979-05-05", true, &key, false, 1000.0, 80.0, 180, 20, 6000.0, "+987654321");

    Schedule schedule(8, 22);
    admin.change_open_time(schedule, 7);
    admin.change_close_time(schedule, 23);

    EXPECT_EQ(schedule.get_open_time(), 7);
    EXPECT_EQ(schedule.get_close_time(), 23);
}

TEST(AdministratorTest, AssignAndTakeOffDutyTrainer)
{
    PassKey key;

    Trainer trainer("Max",
                    30,
                    'm',
                    "1994-01-10",
                    true,
                    &key,
                    true,
                    800.0,
                    85.0,
                    185,
                    8,
                    4000.0,
                    "+111111111",
                    "trainer_max",
                    "maxfit",
                    5000,
                    8000,
                    120,
                    15000,
                    700,
                    60,
                    "Fitness expert",
                    false); 

    Administrator admin("Clara",
                        38,
                        'f',
                        "1986-11-02",
                        true,
                        &key,
                        false,
                        900.0,
                        70.0,
                        172,
                        10,
                        5000.0,
                        "+222222222");

    admin.assign_to_duty(trainer);
    EXPECT_TRUE(trainer.is_on_duty());

    admin.take_off_duty(trainer);
    EXPECT_FALSE(trainer.is_on_duty());
}