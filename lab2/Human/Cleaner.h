#ifndef CLEANER_H
#define CLEANER_H
#include "Room/Room.h"
#include "Mirror/Mirror.h"
#include "Employee.h"

class PassKey;
class Room;
class Mirror;

class Cleaner : public Employee
{
public:
    Cleaner(std::string name,
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
    void clean_area(Room &room);
    void clean_mirror(Mirror &mirror);
};

#endif