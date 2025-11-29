#ifndef ECONOMIST_H
#define ECONOMIST_H
#include <vector>

#include "Employee.h"

class Subscription;
class PassKey;
class Employee;

class Economist : public Employee
{
public:
    Economist(std::string name, unsigned age,
              char gender, std::string date_of_birth,
              bool can_link_passkey_and_locker, PassKey *passkey,
              bool sub_is_taken, double money,
              double weight, unsigned height,
              unsigned work_experience, double salary,
              std::string phone_number);
    double get_all_salaries(std::vector<Employee *> &employees) const;
    void change_salary(Employee *employee, double new_salary);
};

#endif