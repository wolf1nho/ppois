#include <gtest/gtest.h>
#include "../Human/employee.h"

// --- Тест конструктора и геттеров ---
TEST(EmployeeTest, SetSalary_UpdatesCorrectly)
{
    Employee emp("Anna",
                 28,
                 'f',
                 "1996-03-22",
                 true,
                 nullptr,
                 true,
                 800.0,
                 60.0,
                 170,
                 5,
                 3000.0,
                 "+987654321");

    emp.set_salary(4200);
    EXPECT_DOUBLE_EQ(emp.get_salary(), 4200.0);
}

TEST(EmployeeTest, SetPhoneNumber_UpdatesCorrectly)
{

    Employee emp("Bob",
                 42,
                 'm',
                 "1982-11-01",
                 true,
                 nullptr,
                 false,
                 1000.0,
                 90.0,
                 185,
                 15,
                 6000.0,
                 "+111111111");
    EXPECT_EQ(emp.get_phone_number(), "+111111111");
    emp.set_phone_number("+999999999");
    EXPECT_EQ(emp.get_phone_number(), "+999999999");
}

// --- Тест set_work_experience() ---
TEST(EmployeeTest, SetWorkExperience_UpdatesCorrectly)
{
    Employee emp("Lisa",
                 31,
                 'f',
                 "1993-09-09",
                 true,
                 nullptr,
                 true,
                 900.0,
                 65.0,
                 172,
                 7,
                 4000.0,
                 "+222222222");

    emp.set_work_experience(12);
    EXPECT_EQ(emp.get_work_experience(), 12);
}
