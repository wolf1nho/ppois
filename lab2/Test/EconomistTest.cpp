#include <gtest/gtest.h>
#include "Human/Economist.h"
#include "Human/Employee.h"

TEST(EconomistTest, GetAllSalaries_ReturnsCorrectSum)
{
    PassKey key;

   
    Economist eco("Anna",
                  29,
                  'f',
                  "1995-07-21",
                  true,
                  &key,
                  false,
                  500.0,
                  55.0,
                  165,
                  5,
                  3500.0,
                  "+111111111");

    Employee emp1("John", 40, 'm', "1984-01-01", true, nullptr, false, 200.0, 80.0, 180, 10, 3000.0, "+222222222");
    Employee emp2("Lisa", 28, 'f', "1996-03-15", true, nullptr, false, 150.0, 65.0, 170, 4, 2800.0, "+333333333");
    Employee emp3("Mark", 35, 'm', "1989-10-10", true, nullptr, false, 250.0, 75.0, 178, 6, 3200.0, "+444444444");

    std::vector<Employee *> employees = {&emp1, &emp2, &emp3};

    double total = eco.get_all_salaries(employees);

    EXPECT_DOUBLE_EQ(total, 3000.0 + 2800.0 + 3200.0);
}

TEST(EconomistTest, ChangeSalary_UpdatesEmployeeSalary)
{

    Economist eco("Olga",
                  32,
                  'f',
                  "1992-12-12",
                  true,
                  nullptr,
                  false,
                  800.0,
                  58.0,
                  167,
                  7,
                  4200.0,
                  "+999999999");

    Employee emp("Bob", 38, 'm', "1986-09-09", true, nullptr, false, 500.0, 82.0, 182, 12, 3800.0, "+555555555");

    eco.change_salary(&emp, 4500.0);

    EXPECT_DOUBLE_EQ(emp.get_salary(), 4500.0);
}
