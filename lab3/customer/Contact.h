#ifndef CONTACT_H
#define CONTACT_H

#include <string>

#include "Customer.h"
#include "account/BankAccount.h"

// class Customer;

class Contact
{
    std::string nickname; // "Мама"
    Customer *customer;
    BankAccount *account;

public:
    Contact(const std::string &nickname, Customer *customer, BankAccount *account);
    BankAccount *getAccount() { return account; }
    std::string getFullName() { return customer->getFullName(); }
    std::string getNickname() { return nickname; }
};

#endif