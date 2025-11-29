#ifndef RECEPTION_H
#define RECEPTION_H
#include <vector>
#include "Room/Department.h"
#include "Human/Receptionist.h"
#include "Room/Gym.h"
#include "Room/Fitness.h"
#include "Room/Sauna.h"
#include "Room/SwimmingPool.h"
#include "Room/WrestlingRing.h"

class Fitness;
class Gym;
class Sauna;
class SwimmingPool;
class WrestlingRing;

class Reception
{
    friend class Receptionist;

    Fitness *fitness;
    Gym *gym;
    Sauna *sauna;
    SwimmingPool *swimming_pool;
    WrestlingRing *wrestling_ring;
    double bank;

public:
    Reception();
    void add_gym(Gym &gym);
    void add_sauna(Sauna &sauna);
    void add_fitness(Fitness &fitness);
    void add_swimming_pool(SwimmingPool &swimming_pool);
    void add_wrestling_ring(WrestlingRing &wrestling_ring);
};

#endif