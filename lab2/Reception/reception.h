#ifndef RECEPTION_H
#define RECEPTION_H
#include <vector>
#include "../Room/department.h"
#include "../Human/receptionist.h"
#include "../Room/gym.h"
#include "../Room/fitness.h"
#include "../Room/sauna.h"
#include "../Room/swimmingpool.h"
#include "../Room/wrestlingring.h"

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