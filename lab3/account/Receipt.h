#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>

#include "Transaction.h"
#include "Currency.h"
#include "AccountTransaction.h"
#include "CreditPayment.h"

class Receipt
{
    std::string id;
    std::string fromID;
    std::string toID;
    double amount;
    Currency currency;
    time_t transactionTime;
    TransactionStatus status;
    TransactionType type;

public:
    Receipt(AccountTransaction &trans);
    Receipt(CreditPayment &crP);
    std::string getStr();
};

#endif