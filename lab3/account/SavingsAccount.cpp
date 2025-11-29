#include "SavingsAccount.h"
#include "exception/Exception.h"
#include "getter/TimeGetter.h"
#include "Currency.h"

SavingsAccount::SavingsAccount(double balance, Currency currency, const std::string &accountName, double rate, double minimalBalance, Customer *owner, DataManager *dataManager)
    : BankAccount(AccountType::Savings, balance, currency, accountName, owner, dataManager),
      interestRate(rate), minimalBalance(minimalBalance), revocable(true), lastInterestCharge(TimeGetter::getTodayMidnight())
{
}

SavingsAccount::SavingsAccount(double balance, Currency currency, const std::string &accountName, double rate, Customer *owner, DataManager *dataManager)
    : BankAccount(AccountType::Savings, balance, currency, accountName, owner, dataManager),
      interestRate(rate), revocable(false), minimalBalance(0), lastInterestCharge(TimeGetter::getTodayMidnight())
{
}

void SavingsAccount::applyDailyInterest()
{
    time_t now = TimeGetter::getTodayMidnight();

    double seconds = std::difftime(now, lastInterestCharge);

    double days = seconds / (60 * 60 * 24);
    balance += balance * (interestRate / 100.0) * (days / 365.0);
    lastInterestCharge = now;
}

bool SavingsAccount::withdraw(double amount)
{
    if (!revocable)
        throw Exception("");

    if (amount <= 0)
        throw ExceptionIncorrectAmount("");

    if (amount <= balance && balance - amount >= minimalBalance)
    {
        balance -= amount;
        return true;
    }
    return false;
}