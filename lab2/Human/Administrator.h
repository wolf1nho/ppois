#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Employee.h"
#include "Schedule/Schedule.h"

class Schedule;
class Trainer;

class Administrator : public Employee
{

public:
    Administrator(std::string name,
                  unsigned age,
                  char gender,
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

    void change_open_time(Schedule &schedule, unsigned time);
    void change_close_time(Schedule &schedule, unsigned time);
    void assign_to_duty(Trainer &trainer);
    void take_off_duty(Trainer &trianer);
};

#endif