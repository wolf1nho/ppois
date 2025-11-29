#include "Economist.h"

Economist::Economist(std::string name, unsigned age,
                     char gender, std::string date_of_birth,
                     bool can_link_passkey_and_locker, PassKey *passkey,
                     bool sub_is_taken, double money,
                     double weight, unsigned height,
                     unsigned work_experience, double salary,
                     std::string phone_number)
    : Employee(name, age, gender, date_of_birth,
               can_link_passkey_and_locker, passkey, sub_is_taken, money,
               weight, height, work_experience, salary, phone_number)
{
}

double Economist::get_all_salaries(std::vector<Employee *> &employees) const
{
    double sum_salary = 0;
    for (size_t i = 0; i < employees.size(); i++)
    {
        sum_salary += employees[i]->salary;
    }
    return sum_salary;
}

void Economist::change_salary(Employee *employee, double new_salary)
{
    employee->salary = new_salary;
}
