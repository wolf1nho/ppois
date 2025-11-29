#ifndef ACCOUNTTRANSACTION_H
#define ACCOUNTTRANSACTION_H

#include "Transaction.h"
#include "datamanager/DataManager.h"

class Receipt;
class CurrencyConverter;
class BankAccount;

class AccountTransaction : public Transaction
{
    friend class Receipt;

    BankAccount *to;

public:
    AccountTransaction(BankAccount *from, BankAccount *to, double amount, Currency currency, TransactionType type, DataManager *dataManager);
    void execute();
};

#endif