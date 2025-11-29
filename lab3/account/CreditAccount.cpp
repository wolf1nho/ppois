#include "CreditAccount.h"
#include <ctime>
#include "exception/Exception.h"
#include "getter/TimeGetter.h"
#include "Credit.h"

CreditAccount::CreditAccount(Credit *credit, Currency currency, const std::string &accountName, Customer *owner, DataManager *dataManager)
    : credit(credit), BankAccount(AccountType::Credit, credit->creditSum, currency, accountName, owner, dataManager)
{
}

bool CreditAccount::withdraw(double amount)
{
    if (amount <= 0)
        throw ExceptionIncorrectAmount("");

    if (amount > balance)
        return false;

    balance -= amount;

    if (credit->creditSum != balance)
    {
        credit->calculateInterest();
    }
    return true;
}

void CreditAccount::deposit(double amount)
{
    throw ExceptionIncorrectAccountType("кредитную карту пополнить нельзя");
}
