#include "passkey.h"
#include "../Human/human.h"
#include "../Exception/exception.h"

PassKey::PassKey()
{
    num = 0;
    locker = nullptr;
    gender = 'm';
}

PassKey::PassKey(Locker *locker, unsigned num, char gender)
{
    if (gender != 'm' && gender != 'f')
        throw ExceptionIncorrectGender("Либо m, либо f");
    this->num = num;
    this->locker = locker;
    if (locker)
        locker->num = num;
    this->gender = gender;
}

unsigned PassKey::get_num()
{
    return num;
}

void PassKey::close_locker()
{
    if (this->locker->passkey == this)
        locker->locked = true;
}

void PassKey::open_locker()
{
    if (this->locker->passkey == this)
        locker->locked = false;
}

void PassKey::link(Locker *locker)
{
    if (owner->can_link_passkey_and_locker)
    {
        if (this->locker->passkey)
        {
            this->locker->passkey->unlink();
            this->locker->unlink();
        }
        this->locker = locker;
        locker->passkey = this;
        this->num = locker->num;
    }
}

void PassKey::unlink()
{
    locker = nullptr;
    num = 0;
}

std::string PassKey::get_gender()
{
    if (gender == 'm')
        return "male";
    else
        return "female";
};

bool PassKey::is_male()
{
    if (gender == 'm')
        return true;
    else
        return false;
}

bool PassKey::is_female()
{
    if (gender == 'f')
        return true;
    else
        return false;
}
void PassKey::set_owner(Human *owner)
{
    this->owner = owner;
}
