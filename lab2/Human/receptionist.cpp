#include "receptionist.h"
#include "human.h"
#include "../Reception/clientsbase.h"

Receptionist::Receptionist(std::string name, unsigned age,
                           char gender, std::string date_of_birth,
                           bool can_link_passkey_and_locker, PassKey *passkey,
                           bool sub_is_taken, double money,
                           double weight, unsigned height,
                           unsigned work_experience, double salary,
                           std::string phone_number, KeyCase *keycase,
                           ClientsBase *clientsbase, Reception *reception)
    : Employee(name, age, gender, date_of_birth,
               can_link_passkey_and_locker, passkey, sub_is_taken, money,
               weight, height, work_experience, salary, phone_number),
      keycase(keycase), passkey_to_issue(nullptr), passkey_to_bring_back(nullptr),
      client_sub(nullptr), clientsbase(clientsbase), reception(reception)
{
}

void Receptionist::take_client_subscription(Human &human)
{
    if (human.sub)
    {
        client_sub = human.sub;
        human.sub_is_taken = true;
    }
    else
        throw ExceptionSubscriptionError("У клиента нет абонемента");
}

void Receptionist::create_client_sub(Human &human, int initial_num_of_sessions, int validality_period,
                                     Fitness *fitness, Gym *gym, Sauna *sauna, SwimmingPool *swimming_pool, WrestlingRing *wrestling_ring)
{
    if (!client_sub)
    {
        if (!human.sub)
        {
            client_sub = new Subscription(human, initial_num_of_sessions, validality_period, fitness, gym, sauna, swimming_pool, wrestling_ring);
            take_client_subscription(human);
        }
        else
            throw ExceptionSubscriptionError("У клинета уже есть абонемент");
    }
    else
        throw ExceptionSubscriptionError("Обслуживается другой клиент");
}

void Receptionist::create_client_sub(Human &human)
{
    if (!client_sub)
    {
        if (!human.sub)
        {
            client_sub = new Subscription(human);
            take_client_subscription(human);
        }
        else
            throw ExceptionSubscriptionError("У клинета уже есть абонемент");
    }
    else
        throw ExceptionSubscriptionError("Обслуживается другой клиент");
}

void Receptionist::add_client_to_clientsbase(Human &human)
{
    clientsbase->add_client(&human);
}

void Receptionist::take_money_for_sub_from_client() // также изменяет количетсво оставшихся дней и сессий
{
    double price = client_sub->price();
    if (client_sub->owner->money < price)
        throw ExceptionNotEnoughMoney("Недостаточно средств");
    client_sub->owner->money -= price;
    reception->bank += price;
    client_sub->remaining_days = client_sub->validality_period;
    client_sub->remaining_sessions = client_sub->initial_num_of_sessions;
}

bool Receptionist::check_sessions_and_validality_period()
{
    if (client_sub)
    {
        return client_sub->remaining_days > 0 && client_sub->remaining_sessions > 0;
    }
    else
        throw ExceptionSubscriptionError("Нет клиентского абонемента на руках");
}

void Receptionist::change_sub_remaining_sessions()
{
    client_sub->remaining_sessions--;
    if (client_sub->remaining_sessions == 0)
        make_sub_empty();
}

void Receptionist::make_sub_empty()
{
    client_sub->make_empty();
}

bool Receptionist::client_has_sub(Human &human)
{
    return human.sub;
}

void Receptionist::add_gym_in_sub()
{
    client_sub->gym = reception->gym;
    client_sub->departments = true;
}

void Receptionist::add_fitness_in_sub()
{
    client_sub->fitness = reception->fitness;
    client_sub->departments = true;
}

void Receptionist::add_sauna_in_sub()
{
    client_sub->sauna = reception->sauna;
    client_sub->departments = true;
}

void Receptionist::add_swimming_pool_in_sub()
{
    client_sub->swimming_pool = reception->swimming_pool;
    client_sub->departments = true;
}

void Receptionist::add_wrestling_ring_in_sub()
{
    client_sub->wrestling_ring = reception->wrestling_ring;
    client_sub->departments = true;
}

void Receptionist::set_initial_num_of_sessions(int num_of_sessions)
{
    if (num_of_sessions < -1)
        throw ExceptionIncorrectNumOfSessions("Неверный аргумент");
    client_sub->initial_num_of_sessions = num_of_sessions;
}

void Receptionist::set_validality_period(unsigned num_of_days)
{
    client_sub->validality_period = num_of_days;
}

void Receptionist::exchange_sub_for_key()
{
    unsigned i = find_free_passkey(client_sub->gender);
    keycase->passkeys[i].first.set_owner(client_sub->owner);
    passkey_to_issue = &keycase->passkeys[i].first;
    keycase->passkeys.erase(keycase->passkeys.begin() + i);
    keycase->passkeys[i].second = client_sub;
    passkey_to_issue->owner = client_sub->owner;
    client_sub = nullptr;
}

unsigned Receptionist::find_free_passkey(const char g) const
{
    for (unsigned i = 0; i < keycase->passkeys.size(); i++)
    {
        if (keycase->passkeys[i].first.gender == g && !keycase->passkeys[i].second)
        {
            return i;
        }
    }
    throw ExceptionPasskeyError("Нет ключей");
}

void Receptionist::issue_passkey_to_owner()
{
    if (passkey_to_issue)
    {
        passkey_to_issue->owner->passkey = this->passkey_to_issue;
        passkey_to_issue = nullptr;
    }
}

void Receptionist::take_passkey_to_bring_back(Human &human)
{
    if (!passkey_to_bring_back)
    {
        if (human.passkey)
        {
            passkey_to_bring_back = human.passkey;
            human.passkey = nullptr;
        }
        else
            throw ExceptionPasskeyError("У клиента нет ключа");
    }
    else
        throw ExceptionPasskeyError("Уже есть ключ который надоо положить на место");
}

void Receptionist::bring_passkey_back()
{
    unsigned i = find_node();
    passkey_to_bring_back = nullptr;
    client_sub = keycase->passkeys[i].second;
    keycase->passkeys[i].second = nullptr;
}

void Receptionist::bring_sub_back_to_owner()
{
    client_sub->owner->sub = client_sub;
    client_sub->owner->sub_is_taken = false;
    client_sub = nullptr;
}

unsigned Receptionist::find_node()
{
    for (size_t i = 0; i < keycase->passkeys.size(); i++)
    {
        if (&keycase->passkeys[i].first == passkey_to_bring_back)
        {
            return i;
        }
    }
    throw ExceptionPasskeyError("Не найдена нужная ячейка");
}

void Receptionist::change_remaining_days()
{
    clientsbase->change_remaining_days();
}

double Receptionist::get_bank()
{
    return reception->bank;
}