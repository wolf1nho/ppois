#include "human.h"
#include "../Exception/exception.h"

Human::Human(std::string name, unsigned age,
             char gender, std::string date_of_birth,
             bool can_link_passkey_and_locker,
             PassKey *passkey, bool sub_is_taken,
             double money, double weight, unsigned height)
    : name(name), age(age), gender(gender), date_of_birth(date_of_birth), sub(nullptr),
      can_link_passkey_and_locker(can_link_passkey_and_locker), passkey(passkey),
      sub_is_taken(sub_is_taken), money(money), weight(weight), height(height)
{
    if (height < 145)
        throw ExceptionIncorrectHeight("Карликов не пускаем в спортклуб");
    if (weight < 1)
        throw ExceptionIncorrectWeight("С таким весом надо идти к врачу");
    if (gender != 'm' && gender != 'f')
        throw ExceptionIncorrectGender("Либо m, либо f");
    if (money < 0)
        throw ExceptionIncorrectMoney("Должников не принимаем");
}

Human::~Human()
{
    if (sub)
        delete sub;
}

std::string Human::get_name()
{
    return name;
}

char Human::get_gender_char()
{
    return gender;
}

std::string Human::get_gender()
{
    if (gender == 'm')
        return "male";
    else
        return "female";
};

bool Human::is_male()
{
    if (gender == 'm')
        return true;
    else
        return false;
}

bool Human::is_female()
{
    if (gender == 'f')
        return true;
    else
        return false;
}

unsigned Human::get_age()
{
    return age;
}

std::string Human::get_date_of_birth()
{
    return date_of_birth;
}

void Human::set_name(std::string name)
{
    this->name = name;
}

void Human::set_age(unsigned age)
{
    this->age = age;
}

void Human::set_gender(char gender)
{
    this->gender = gender;
}

void Human::set_date_of_birth(std::string dob)
{
    this->date_of_birth = dob;
}

void Human::set_weight(double weight)
{
    this->weight = weight;
}

void Human::set_height(unsigned height)
{
    this->height = height;
}

double Human::get_money() const
{
    return money;
}

std::string Human::get_remaining_sessions()
{
    if (sub)
    {
        if (sub->remaining_sessions == -1)
            return "unlimited";
        else
            return std::to_string(sub->remaining_sessions);
    }
    else
        throw ExceptionSubscriptionError("Нет абонемента");
}
std::string Human::get_remaining_days()
{
    if (sub)
    {
        return std::to_string(sub->remaining_days);
    }
    else
        throw ExceptionSubscriptionError("Нет абонемента");
}

std::string Human::get_validality_period()
{
    if (sub)
    {
        return std::to_string(sub->validality_period);
    }
    else
        throw ExceptionSubscriptionError("Нет абонемента");
}

std::string Human::get_initial_num_of_sessions()
{
    if (sub)
    {
        if (sub->initial_num_of_sessions == -1)
            return "unlimited";
        else
            return std::to_string(sub->initial_num_of_sessions);
    }
    else
        throw ExceptionSubscriptionError("Нет абонемента");
}