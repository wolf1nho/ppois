#include "AccountTransaction.h"
#include "../getter/TimeGetter.h"
#include "../exception/Exception.h"
#include "BankAccount.h"
#include "CurrencyConverter.h"
#include "../datamanager/DataManager.h"

AccountTransaction::AccountTransaction(BankAccount *from, BankAccount *to, double amount, Currency currency, TransactionType type, DataManager *dataManager)
    : to(to), Transaction(from, amount, currency, type, dataManager) {}

void AccountTransaction::execute()
{
    if (to->getType() == AccountType::Credit)
        throw Exception("Используйте CreditPayment");
    transactionTime = TimeGetter::getTime();

    if (from->withdraw(dataManager->getConverter()->convert(currency, from->getCurrency(), amount)))
        to->deposit(dataManager->getConverter()->convert(currency, to->getCurrency(), amount));
}