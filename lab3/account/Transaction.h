#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <string>

#include "Currency.h"

enum class TransactionType
{
    PAYMENT,
    TRANSFER,
    SALARY,
    TAX,
    RETURN,
};

enum class TransactionStatus
{
    PENDING,
    SUCCEED,
    FAILED
};

class BankAccount;
class DataManager;

class Transaction
{
protected:
    std::string id;
    BankAccount *from;
    double amount;
    time_t transactionTime;
    Currency currency;
    TransactionStatus status;
    TransactionType type;
    DataManager *dataManager;

public:
    Transaction(BankAccount *from, double amount, Currency currency, TransactionType type, DataManager *dataManager);
    std::string getID() const;
    virtual void setAmount(double amount, Currency currency);
    TransactionStatus getStatus();
    virtual void execute();
};

#endif