#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

#include "Currency.h"

enum class AccountType
{
    Credit,
    Current,
    Savings
};

class AccountTransacion;
class Card;
class Cashback;
class ATM;
class Customer;
class DataManager;
class InternetBanking;

class BankAccount
{
    friend class AccountTransaction;
    friend class Card;
    friend class Cashback;
    friend class ATM;
    friend class InternetBanking;

protected:
    std::string accountName;
    std::string id;
    double balance;
    Currency currency;
    bool frozen;
    AccountType type;
    Customer *owner;
    DataManager *dataManager;

public:
    BankAccount(AccountType type, double initialBalance, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager);
    virtual ~BankAccount() = default;

    std ::string getID() const;
    double getBalance() const;
    Currency getCurrency() const;
    bool isFrozen();
    AccountType getType();
    std::string getAccountName();
    void freezeAccount();
    void unfreezeAccount();

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
};

#endif
