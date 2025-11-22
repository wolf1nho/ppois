#ifndef CLIENTSBASE_H
#define CLIENTSBASE_H
#include <vector>
#include "subscription.h"
#include "../Human/human.h"

class Human;
class Receptionist;

class ClientsBase
{
    friend class Receptionist;

    std::vector<Human *> clients;

    void add_client(Human *human);
    void change_remaining_days();
};

#endif