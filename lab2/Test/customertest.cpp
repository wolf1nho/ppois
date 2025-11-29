#include <gtest/gtest.h>
#include "../Human/customer.h"
#include "../Human/trainer.h"
#include "../Exception/exception.h"

TEST(CustomerTest, GetPersonalTrainerName)
{
    Trainer t("Alex",
              35,
              'm',
              "1989-03-15",
              true,
              nullptr,
              false,
              500.0,
              85.0,
              185,
              12,
              3500.0,
              "+123456789",
              "fitlife_alex",
              "alex_trainer",
              12000, // followers_count_tiktok
              8000,  // followers_count_insta
              150,   // post_count
              25000, // likes_count
              1200,  // repost_count
              90,    // stories_count
              "Professional fitness trainer",
              true);
    EXPECT_TRUE(t.is_on_duty());

    Customer c("Ivan", 28, 'm', "1997-03-12", true, nullptr, false, 100.0, 70.0, 175, nullptr);
    EXPECT_THROW(c.get_personal_trainer_name(), ExceptionPersonalTrainerError);
    c.set_personal_trainer(&t);
    EXPECT_EQ(c.get_personal_trainer_name(), "Alex");
}
