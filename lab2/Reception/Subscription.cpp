#include "Subscription.h"
#include "Exception/Exception.h"

Subscription::Subscription(Human &owner) : remaining_days(0), remaining_sessions(0), initial_num_of_sessions(0), validality_period(0),
                                           fitness(nullptr), gym(nullptr), sauna(nullptr), swimming_pool(nullptr), wrestling_ring(nullptr)
{
    link(owner);
    departments = false;
}

Subscription::Subscription(Human &owner, int initial_num_of_sessions, int validality_period,
                           Fitness *fitness, Gym *gym, Sauna *sauna, SwimmingPool *swimming_pool, WrestlingRing *wrestling_ring)
    : initial_num_of_sessions(initial_num_of_sessions), validality_period(validality_period),
      remaining_days(validality_period), remaining_sessions(initial_num_of_sessions),
      fitness(fitness), gym(gym), sauna(sauna), swimming_pool(swimming_pool), wrestling_ring(wrestling_ring)
{
    link(owner);
    is_departments();
    if (!departments)
        throw ExceptionSubscriptionError("Подписка без секций");
}

void Subscription::link(Human &human)
{
    owner = &human;
    human.sub = this;
    gender = human.gender;
}

char Subscription::get_gender()
{
    return gender;
}

void Subscription::is_departments()
{
    if (!gym || !sauna || !fitness || !swimming_pool || !wrestling_ring)
    {
        departments = true;
    }
    else
        departments = false;
}

double Subscription::price()
{
    double price = 0;
    if (departments)
    {
        if (gym)
            price += gym->price;
        if (fitness)
            price += fitness->price;
        if (sauna)
            price += sauna->price;
        if (swimming_pool)
            price += swimming_pool->price;
        if (wrestling_ring)
            price += wrestling_ring->price;
    }
    return price * initial_num_of_sessions;
}

void Subscription::make_empty()
{
    remaining_days = 0;
    remaining_sessions = 0;
}