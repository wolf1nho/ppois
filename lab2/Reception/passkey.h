#ifndef PASSKEY_H
#define PASSKEY_H
#include <string>
#include "../Room/locker.h"
// #include "keycase.h"
// #include "../Human/receptionist.h"
// #include "../Human/human.h"

class Locker;
class Human;
class Receptionist;

class PassKey
{
    friend class Locker;
    friend class KeyCase;
    friend class Receptionist;

    Locker *locker;
    unsigned num;
    Human *owner;
    char gender;

    void set_owner(Human *owner);
    void unlink_with_owner();

public:
    PassKey();
    PassKey(Locker *locker, unsigned num, char gender);
    unsigned get_num();
    void close_locker();
    void open_locker();
    void link(Locker *locker);
    void unlink();
    std::string get_gender();
    bool is_male();
    bool is_female();
};

#endif