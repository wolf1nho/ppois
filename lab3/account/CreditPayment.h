#ifndef CREDIT_PAYMENT_H
#define CREDIT_PAYMENT_H

#include <ctime>

#include "Credit.h"
#include "CreditAccount.h"
#include "../customer/Customer.h"
#include "Transaction.h"

class Credit;
class CreditAccount;
class Receipt;
// class Transaction;

class CreditPayment : public Transaction
{
    friend class Credit;
    friend class Receipt;

    Credit *credit;

public:
    CreditPayment(Credit *credit, DataManager *dataManager);
    void setFromAccount(BankAccount *account);
    void execute() override;
};

#endif