#include "BankAccount.h"
#include "../exception/Exception.h"
#include "../datamanager/DataManager.h"

BankAccount::BankAccount(AccountType type, double initialBalance, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager)
    : type(type), balance(initialBalance), currency(currency), owner(owner), frozen(false), accountName(accountName)
{
    for (int i = 0; i < owner->accounts.size(); i++)
        if (owner->accounts[i]->getAccountName() == accountName)
            throw Exception("уже есть счет с таким именем");
    dataManager->generatorID.generateID(id);
    dataManager->addAccount(this);
    owner->accounts.push_back(this);
}

std::string BankAccount::getID() const { return id; }
double BankAccount::getBalance() const { return balance; }
Currency BankAccount::getCurrency() const { return currency; }
bool BankAccount::isFrozen() { return frozen; }
AccountType BankAccount::getType() { return type; }
std::string BankAccount::getAccountName() { return accountName; }

void BankAccount::deposit(double amount)
{
    if (frozen)
        throw ExceptionFrozenAccount("");

    if (amount > 0)
        balance += amount;
    else
        throw ExceptionIncorrectAmount("Отрицательная сумма");
}

bool BankAccount::withdraw(double amount)
{
    if (frozen)
        throw ExceptionFrozenAccount("");
    if (amount <= 0)
        throw ExceptionIncorrectAmount("");
    if (amount <= balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void BankAccount::freezeAccount()
{
    if (frozen)
        throw ExceptionFrozenAccount("Счет уже заморожен");
    frozen = true;
}

void BankAccount::unfreezeAccount()
{
    if (!frozen)
        throw ExceptionFrozenAccount("Счет уже заморожен");
    frozen = false;
}