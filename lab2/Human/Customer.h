#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Human.h"

class Trainer;

class Customer : public Human
{
    Trainer *personal_trainer;

public:
    Customer(std::string name,
             unsigned age,
             char gender, // female = f; male = m;
             std::string date_of_birth,
             bool can_link_passkey_and_locker,
             PassKey *passkey,
             bool sub_is_taken,
             double money,
             double weight,
             unsigned height,
             Trainer *personal_trainer);
    std::string get_personal_trainer_name();
    void set_personal_trainer(Trainer *trainer);
};

#endif