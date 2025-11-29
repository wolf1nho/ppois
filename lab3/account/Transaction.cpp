#include "Transaction.h"
#include "../getter/TimeGetter.h"
#include "../exception/Exception.h"
#include "../datamanager/DataManager.h"

Transaction::Transaction(BankAccount *from, double amount, Currency currency, TransactionType type, DataManager *dataManager)
    : from(from), amount(amount), type(type), dataManager(dataManager),
      status(TransactionStatus::PENDING), currency(currency)
{
    transactionTime = 0;
    dataManager->addTransaction(this);
    dataManager->generatorID.generateID(id);
}

std::string Transaction::getID() const
{
    return id;
}

void Transaction::setAmount(double amount, Currency currency)
{
    if (amount <= 0)
        throw ExceptionIncorrectAmount("Сумма платежа меньше 0");
    this->amount = amount;
    this->currency = currency;
}

TransactionStatus Transaction::getStatus()
{
    return status;
}

void Transaction::execute() {}