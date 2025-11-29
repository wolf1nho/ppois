#include <gtest/gtest.h>
#include "../Human/receptionist.h"
#include "../Human/human.h"
#include "../Reception/passkey.h"
#include "../Human/human.h"
#include "../Reception/keycase.h"
#include "../Reception/subscription.h"
#include "../Human/customer.h"
#include "../Reception/clientsbase.h"

TEST(ReceptionistTest, FunctionalTest)
{
    KeyCase kc;
    ClientsBase cb;
    Reception rec;
    Fitness fitness(5, 10, 10, 10, 10, 10, 10, 10);
    rec.add_fitness(fitness);
    Gym gym(10, 100, true, 50, 200, 10, 10, 10, 10);
    rec.add_gym(gym);
    Sauna sauna(4, 10, 100, 90);
    rec.add_sauna(sauna);
    SwimmingPool swimmingpool(6, 220, 7, 50, 8, 25);
    rec.add_swimming_pool(swimmingpool);
    WrestlingRing wrestlingring(8, 40, true);
    rec.add_wrestling_ring(wrestlingring);
    for (int i = 1; i <= 10; i++)
    {
        kc.add(PassKey(nullptr, i, 'm'));
    }

    Receptionist r("John", 30, 'm', "1995-01-01", true, nullptr, false,
                   400, 80.0, 180, 5, 3000, "+222222",
                   &kc, &cb, &rec);

    Customer c("Ivan", 28, 'm', "1997-03-12", true, nullptr, false, 1000.0, 70.0, 175, nullptr);

    EXPECT_FALSE(r.client_has_sub(c));
    r.create_client_sub(c);
    r.add_gym_in_sub();
    r.add_sauna_in_sub();
    r.add_swimming_pool_in_sub();
    r.add_wrestling_ring_in_sub();
    r.add_fitness_in_sub();
    r.set_initial_num_of_sessions(10);
    r.set_validality_period(60);
    r.take_money_for_sub_from_client();
    EXPECT_EQ(c.get_money(), 670);
    r.change_sub_remaining_sessions();
    r.exchange_sub_for_key();
    r.issue_passkey_to_owner();
    r.take_passkey_to_bring_back(c);
    r.bring_passkey_back();
    r.bring_sub_back_to_owner();
}

TEST(ReceptionistTest, ExceptionsTest)
{
    KeyCase kc;
    ClientsBase cb;
    Reception rec;
    Gym gym(10, 100, true, 50, 200, 10, 10, 10, 10);
    rec.add_gym(gym);

    for (int i = 1; i <= 10; i++)
    {
        kc.add(PassKey(nullptr, i, 'm'));
    }

    Receptionist r("John", 30, 'm', "1995-01-01", true, nullptr, false,
                   400, 80.0, 180, 5, 3000, "+222222",
                   &kc, &cb, &rec);

    Customer c("Ivan", 28, 'm', "1997-03-12", true, nullptr, false, 1000.0, 70.0, 175, nullptr);
    EXPECT_THROW(r.check_sessions_and_validality_period(), ExceptionSubscriptionError);
    EXPECT_THROW(r.take_client_subscription(c), ExceptionSubscriptionError);
    r.create_client_sub(c);
    r.add_client_to_clientsbase(c);
    r.add_gym_in_sub();
    EXPECT_THROW(r.set_initial_num_of_sessions(-2), ExceptionIncorrectNumOfSessions);
    r.set_initial_num_of_sessions(1);
    r.set_validality_period(60);
    r.take_money_for_sub_from_client();
    r.change_sub_remaining_sessions();
    EXPECT_FALSE(r.check_sessions_and_validality_period());
}