#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include <string>

#include "BankAccount.h"
#include "Currency.h"

class Overdraft;
enum class Currency;

class CurrentAccount : public BankAccount
{
    friend class Overdraft;
    bool hasOverdraft;
    Overdraft *overdraft;

public:
    CurrentAccount(double balance, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager);
    CurrentAccount(double balance, Currency currency, const std::string &accountName, double overdraftLimit, double interestRate, int maxOverdraftDuration,
                   Customer *owner, DataManager *dataManager);
    bool withdraw(double amount) override;
    void deposit(double amount) override;
    ~CurrentAccount();
};

#endif
