#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Human.h"

class PassKey;
class Economist;

class Employee : public Human
{
    friend class Economist;

protected:
    unsigned work_experience;
    double salary;
    std::string phone_number;

public:
    Employee(std::string name,
             unsigned age,
             char gender, // female = f; male = m;
             std::string date_of_birth,
             bool can_link_passkey_and_locker,
             PassKey *passkey,
             bool sub_is_taken,
             double money,
             double weight,
             unsigned height,
             unsigned work_experience,
             double salary,
             std::string phone_number);
    double get_salary() const;
    unsigned get_work_experience() const;
    std::string get_phone_number() const;
    void set_salary(unsigned int salary);
    void set_phone_number(std::string pn);
    void set_work_experience(unsigned int work_experience);
};

#endif
