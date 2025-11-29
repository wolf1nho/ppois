#include "CreditPayment.h"
#include "exception/Exception.h"

CreditPayment::CreditPayment(Credit *credit, DataManager *dataManager)
    : credit(credit), Transaction(nullptr, 0, credit->currency, TransactionType::PAYMENT, dataManager)
{
}

void CreditPayment::setFromAccount(BankAccount *account)
{
    if (account == credit->account)
        throw ExceptionIncorrectAccount("Нельзя оплачивать кредит этим же кредитом");
    from = account;
}

void CreditPayment::execute()
{
    if (from->withdraw(dataManager->getConverter()->convert(currency, from->getCurrency(), amount)))
    {
        credit->deposit(dataManager->getConverter()->convert(currency, credit->currency, amount));
        status = TransactionStatus::SUCCEED;
    }
    else
    {
        status = TransactionStatus::FAILED;
    }
    transactionTime = TimeGetter::getTime();
}
