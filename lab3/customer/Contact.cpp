#include "Contact.h"

Contact::Contact(const std::string &nickname, Customer *customer, BankAccount *account)
    : nickname(nickname), customer(customer), account(account)
{
}