#include "CurrentAccount.h"
#include "exception/Exception.h"
#include "Overdraft.h"

CurrentAccount::CurrentAccount(double balance, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager)
    : BankAccount(AccountType::Current, balance, currency, accountName, owner, dataManager), overdraft(nullptr), hasOverdraft(false)
{
}

CurrentAccount::CurrentAccount(double balance, Currency currency, const std::string &accountName, double overdraftLimit, double interestRate, int maxOverdraftDuration,
                               Customer *owner, DataManager *dataManager)
    : BankAccount(AccountType::Current, balance, currency, accountName, owner, dataManager), hasOverdraft(true)
{
    overdraft = new Overdraft(this, overdraftLimit, interestRate, maxOverdraftDuration);
}

bool CurrentAccount::withdraw(double amount)
{
    if (frozen)
        throw ExceptionFrozenAccount("");
    if (amount <= 0)
        throw ExceptionIncorrectAmount("");
    if (hasOverdraft)
        return overdraft->withdraw(amount);
    if (amount <= balance)
    {
        balance -= (amount);
        return true;
    }
    return false;
}

void CurrentAccount::deposit(double amount)
{
    if (frozen)
        throw ExceptionFrozenAccount("");
    if (amount <= 0)
        throw ExceptionIncorrectAmount("");
    if (hasOverdraft)
        return overdraft->deposit(amount);
    balance += amount;
}

CurrentAccount::~CurrentAccount()
{
    if (hasOverdraft)
        delete overdraft;
}