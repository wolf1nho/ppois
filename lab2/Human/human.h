#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "../Reception/passkey.h"
#include "../Reception/subscription.h"

class Subscription;
class PassKey;
class Receptionist;
class Scales;
class ClientsBase;

class Human
{
protected:
    friend class PassKey;
    friend class Receptionist;
    friend class ClientsBase;
    friend class Subscription;
    friend class Scales;

    std::string name;
    unsigned age;
    char gender; // female = f; male = m;
    std::string date_of_birth;
    Subscription *sub;
    bool can_link_passkey_and_locker;
    PassKey *passkey;
    bool sub_is_taken;
    double money;
    double weight;
    unsigned height;

public:
    Human(const std::string name,
          const unsigned age,
          const char gender,
          const std::string date_of_birth,
          const bool can_link_passkey_and_locker,
          PassKey *passkey,
          const bool sub_is_taken,
          const double money,
          const double weight,
          const unsigned height);
    ~Human();
    void set_name(std::string name);
    void set_age(unsigned age);
    void set_gender(char gender);
    void set_date_of_birth(std::string dob);
    void set_weight(double weight);
    void set_height(unsigned height);
    std::string get_name();
    unsigned get_age();
    std::string get_gender();
    char get_gender_char();
    bool is_male();
    bool is_female();
    std::string get_date_of_birth();
    double get_money() const;
    std::string get_remaining_sessions();
    std::string get_remaining_days();
    std::string get_validality_period();
    std::string get_initial_num_of_sessions();
};

#endif