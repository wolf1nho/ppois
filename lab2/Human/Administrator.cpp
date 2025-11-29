#include "Administrator.h"
#include "Trainer.h"

Administrator::Administrator(std::string name, unsigned age,
                             char gender, std::string date_of_birth,
                             bool can_link_passkey_and_locker, PassKey *passkey,
                             bool sub_is_taken, double money,
                             double weight, unsigned height,
                             unsigned work_experience, double salary, std::string phone_number)
    : Employee(name, age, gender, date_of_birth, can_link_passkey_and_locker,
               passkey, sub_is_taken, money, weight,
               height, work_experience, salary, phone_number)
{
}

void Administrator::change_open_time(Schedule &schedule, unsigned time)
{
    schedule.open_time = time;
}

void Administrator::change_close_time(Schedule &schedule, unsigned time)
{
    schedule.close_time = time;
}

void Administrator::assign_to_duty(Trainer &trainer)
{
    trainer.on_duty = true;
}
void Administrator::take_off_duty(Trainer &trainer)
{
    trainer.on_duty = false;
}