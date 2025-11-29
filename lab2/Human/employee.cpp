#include "employee.h"

Employee::Employee(std::string name, unsigned age, char gender, std::string date_of_birth,
                   bool can_link_passkey_and_locker, PassKey *passkey, bool sub_is_taken, double money,
                   double weight, unsigned height, unsigned work_experience, double salary, std::string phone_number)
    : Human(name, age, gender, date_of_birth, can_link_passkey_and_locker,
            passkey, sub_is_taken, money, weight, height),
      work_experience(work_experience), salary(salary), phone_number(phone_number)
{
}

void Employee::set_salary(unsigned salary)
{
    this->salary = salary;
}

void Employee::set_phone_number(std::string pn)
{
    this->phone_number = pn;
}

void Employee::set_work_experience(unsigned work_experience)
{
    this->work_experience = work_experience;
}

double Employee::get_salary() const
{
    return salary;
}
std::string Employee::get_phone_number() const
{
    return phone_number;
}
unsigned Employee::get_work_experience() const
{
    return work_experience;
}