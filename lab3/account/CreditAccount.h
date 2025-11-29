#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "BankAccount.h"

class Credit;
// class BankAccount;

class CreditAccount : public BankAccount
{
private:
    friend class Credit;

    Credit *credit;
    // возобновляемые кредитные линии
    // погашение задолженности

public:
    CreditAccount(Credit *credit, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager);
    bool withdraw(double amount) override;
    void deposit(double amount) override;
};

#endif
