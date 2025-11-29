#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H
#include <vector>
#include <string>
#include "Human/Human.h"
#include "Room/Fitness.h"
#include "Room/Gym.h"
#include "Room/Sauna.h"
#include "Room/SwimmingPool.h"
#include "Room/WrestlingRing.h"

class Human;
class Fitness;
class Gym;
class Sauna;
class SwimmingPool;
class WrestlingRing;

class Subscription
{
protected:
    Fitness *fitness;
    Gym *gym;
    Sauna *sauna;
    SwimmingPool *swimming_pool;
    WrestlingRing *wrestling_ring;
    unsigned validality_period;
    unsigned remaining_days;
    int initial_num_of_sessions; // -1 = unlimited
    int remaining_sessions;      // -1 = unlimited
    Human *owner;
    char gender;
    bool departments;
    void is_departments();

public:
    Subscription(Human &human);
    Subscription(Human &owner, int initial_num_of_sessions, int validality_period,
                 Fitness *fitness, Gym *gym, Sauna *sauna, 
                 SwimmingPool *swimming_pool, WrestlingRing *wrestling_ring);
    void link(Human &human);
    char get_gender();
    double price();
    void make_empty();

    friend class Human;
    friend class Receptionist;
    friend class ClientsBase;
};

#endif