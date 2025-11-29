#include "Overdraft.h"
#include "exception/Exception.h"
#include "CurrentAccount.h"
#include "getter/TimeGetter.h"

Overdraft::Overdraft(CurrentAccount *account, double overdraftLimit, double interestRate, int maxOverdraftDuration)
    : account(account), overdraftLimit(overdraftLimit), interestRate(interestRate), maxOverdraftDuration(maxOverdraftDuration),
      overdraftStart(0), lastCheck(0), interestDebt(0), overdraftDuration(0), inOverdraft(false) {}

void Overdraft::deposit(double amount)
{
    if (amount <= 0)
        throw ExceptionIncorrectAmount("");
    if (inOverdraft)
    {
        calculateInterest();
        account->balance -= interestDebt;
        interestDebt = 0;
    }

    account->balance += amount;

    if (account->balance >= 0)
    {
        inOverdraft = false;
        account->frozen = false;
        overdraftStart = 0;
        overdraftDuration = 0;
    }
    else if (getOverdraftDuration() > maxOverdraftDuration)
    {
        account->frozen = true;
    }
}

bool Overdraft::withdraw(double amount)
{
    checkOverdraftDuration();
    if (account->frozen)
        throw ExceptionFrozenAccount("");

    if (account->balance - amount < -overdraftLimit)
    {
        return false;
    }

    calculateInterest();

    account->balance -= amount;
    if (account->balance < 0 && !inOverdraft)
    {
        inOverdraft = true;
        overdraftStart = time(nullptr);
        lastCheck = TimeGetter::getTodayMidnight();
    }
    return true;
}

void Overdraft::calculateInterest()
{
    if (!inOverdraft)
        return;
    time_t now = TimeGetter::getTodayMidnight();

    double seconds = std::difftime(now, lastCheck);

    double days = seconds / (60 * 60 * 24);

    double interest = abs(account->balance) * (interestRate / 100.0) * (days / 365.0);
    account->balance -= interest;
    lastCheck = now;
}

void Overdraft::updateOverdraftDuration()
{
    if (!inOverdraft)
        return;

    time_t now = TimeGetter::getTodayMidnight();
    int seconds = difftime(now, overdraftStart);

    overdraftDuration = seconds / (60 * 60 * 24);
}

int Overdraft::getOverdraftDuration()
{
    updateOverdraftDuration();
    return overdraftDuration;
}

void Overdraft::checkOverdraftDuration()
{
    if (!inOverdraft)
        return;
    if (getOverdraftDuration() > maxOverdraftDuration)
        account->frozen = true;
}