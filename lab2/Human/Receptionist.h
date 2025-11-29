#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include "Employee.h"
#include "Reception/KeyCase.h"
#include "Reception/PassKey.h"
#include "Reception/Reception.h"
#include "Exception/Exception.h"

class KeyCase;
class PassKey;
class PassKey;
class Subscription;
class ClientsBase;
class Reception;
class Human;

class Receptionist : public Employee
{
    friend class Human;

    KeyCase *keycase;
    PassKey *passkey_to_issue;
    PassKey *passkey_to_bring_back;
    Subscription *client_sub;
    ClientsBase *clientsbase;
    Reception *reception;

    void make_sub_empty();
    void make_sub_empty(Human &human);

public:
    Receptionist(std::string name,
                 unsigned age,
                 char gender,
                 std::string date_of_birth,
                 bool can_link_passkey_and_locker,
                 PassKey *passkey,
                 bool sub_is_taken,
                 double money,
                 double weight,
                 unsigned height,
                 unsigned work_experience,
                 double salary,
                 std::string phone_number,
                 KeyCase *keycase,
                 ClientsBase *clientsbase,
                 Reception *reception);

    double get_bank();

    void take_key_from_keycase();
    bool check_sessions_and_validality_period();
    void take_client_subscription(Human &human);
    void create_client_sub(Human &human);
    void create_client_sub(Human &human, int initial_num_of_sessions, int validality_period,
                           Fitness *fitness, Gym *gym, Sauna *sauna, SwimmingPool *swimming_pool, WrestlingRing *wrestling_ring);
    void add_client_to_clientsbase(Human &human);

    void add_gym_in_sub();
    void add_fitness_in_sub();
    void add_sauna_in_sub();
    void add_swimming_pool_in_sub();
    void add_wrestling_ring_in_sub();

    void take_money_for_sub_from_client();

    void set_initial_num_of_sessions(int num_of_sessions);
    void set_validality_period(unsigned num_of_days);

    void change_sub_remaining_sessions();

    unsigned find_free_passkey(char g) const;

    bool client_has_sub(Human &human);
    void exchange_sub_for_key();
    void issue_passkey_to_owner();
    void take_passkey_to_bring_back(Human &human);
    void bring_passkey_back();
    void bring_sub_back_to_owner();
    unsigned find_node();
    void change_remaining_days();
};

#endif