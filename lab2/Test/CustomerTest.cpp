#include <gtest/gtest.h>
#include "Human/Customer.h"
#include "Human/Trainer.h"
#include "Exception/Exception.h"

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
              12000, 
              8000,  
              150,  
              25000, 
              1200,  
              90,   
              "Professional fitness trainer",
              true);
    EXPECT_TRUE(t.is_on_duty());

    Customer c("Ivan", 28, 'm', "1997-03-12", true, nullptr, false, 100.0, 70.0, 175, nullptr);
    EXPECT_THROW(c.get_personal_trainer_name(), ExceptionPersonalTrainerError);
    c.set_personal_trainer(&t);
    EXPECT_EQ(c.get_personal_trainer_name(), "Alex");
}
