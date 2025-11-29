#ifndef OVERDRAFT_H
#define OVERDRAFT_H

#include <ctime>

class CurrentAccount;

class Overdraft
{
    CurrentAccount *account;
    double overdraftLimit;
    double interestRate;
    time_t overdraftStart;
    time_t lastCheck;
    bool inOverdraft;
    double interestDebt;
    int overdraftDuration;
    int maxOverdraftDuration;

    void updateOverdraftDuration();

public:
    Overdraft(CurrentAccount *account, double overdraftLimit, double interestRate, int maxOverdraftDuration);

    void deposit(double amount);
    bool withdraw(double amount);
    void calculateInterest();
    int getOverdraftDuration();
    void checkOverdraftDuration();
};

#endif