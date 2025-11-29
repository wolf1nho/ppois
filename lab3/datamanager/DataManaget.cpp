#include "DataManager.h"

DataManager::DataManager(CurrencyConverter *converter)
    : converter(converter) {}

void DataManager::addCredit(Credit *credit)
{
    credits[credit->getID()] = credit;
}

void DataManager::addCustomer(Customer *customer)
{
    customers[customer->getID()] = customer;
}
void DataManager::addTransaction(Transaction *transaction)
{
    transactions[transaction->getID()] = transaction;
}

void DataManager::addAccount(BankAccount *BankAccount)
{
    accounts[BankAccount->getID()] = BankAccount;
}

DataManager::~DataManager()
{
    for (auto &[id, transaction] : transactions)
    {
        delete transaction;
    }
    transactions.clear();
}

CurrencyConverter *DataManager::getConverter()
{
    return converter;
}
