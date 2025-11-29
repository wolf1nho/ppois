#include "ClientsBase.h"
#include "Exception/Exception.h"

void ClientsBase::add_client(Human *human)
{
    if (human->sub)
        clients.push_back(human);
    else
        throw ExceptionSubscriptionError("У клиента еще нет абонемента");
}

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