#include "clientsbase.h"
#include "../Exception/exception.h"

void ClientsBase::add_client(Human *human)
{
    if (human->sub)
        clients.push_back(human);
    else
        throw ExceptionSubscriptionError("У клиента еще нет абонемента");
}
/*
size_t ClientsBase::findInsertPosition(const std::string &new_client_name)
{
    size_t left = 0;
    size_t right = clients.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (clients[mid].name < new_client_name)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

void ClientsBase::insertSortedBinary(const Human &new_client)
{
    size_t pos = findInsertPosition(new_client.name);
    clients.insert(clients.begin() + pos, new_client);
}

Human ClientsBase::search_client(const std::string &client_name)
{
    size_t left = 0;
    size_t right = clients.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (clients[mid].name < client_name)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return clients[right];
}
 */
void ClientsBase::change_remaining_days()
{
    for (unsigned i = 0; i < clients.size(); i++)
    {
        if (clients[i]->sub->remaining_days > 0)
        {
            clients[i]->sub->remaining_days--;
            if (clients[i]->sub->remaining_days == 0)
                clients[i]->sub->make_empty();
        }
    }
}