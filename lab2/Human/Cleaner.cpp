#include "Cleaner.h"

Cleaner::Cleaner(std::string name, unsigned age, char gender, std::string date_of_birth,
                 bool can_link_passkey_and_locker, PassKey *passkey, bool sub_is_taken, double money,
                 double weight, unsigned height, unsigned work_experience, double salary, std::string phone_number)
    : Employee(name, age, gender, date_of_birth, can_link_passkey_and_locker, passkey,
               sub_is_taken, money, weight, height, work_experience, salary, phone_number)
{
}

void Cleaner::clean_area(Room &room)
{
    room.cleaned = true;
}

void Cleaner::clean_mirror(Mirror &mirror)
{
    mirror.cleaned = true;
}
