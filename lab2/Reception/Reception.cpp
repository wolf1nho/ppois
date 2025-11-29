#include "Reception.h"

Reception::Reception()
{
    gym = nullptr;
    fitness = nullptr;
    sauna = nullptr;
    swimming_pool = nullptr;
    wrestling_ring = nullptr;
    bank = 0;
}

void Reception::add_fitness(Fitness &fitness)
{
    this->fitness = &fitness;
}

void Reception::add_gym(Gym &gym)
{
    this->gym = &gym;
}
void Reception::add_sauna(Sauna &sauna)
{
    this->sauna = &sauna;
}

void Reception::add_swimming_pool(SwimmingPool &swimming_pool)
{
    this->swimming_pool = &swimming_pool;
}
void Reception::add_wrestling_ring(WrestlingRing &wrestling_ring)
{
    this->wrestling_ring = &wrestling_ring;
}