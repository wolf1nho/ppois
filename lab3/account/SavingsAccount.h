#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <ctime>

#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
private:
    double interestRate;   // процент годовых
    bool revocable;        // отзывный и безотзывный
    double minimalBalance; // сумма которую нельзя забрать в отзывном счете(если 0, то можно забрать все деньги)
    time_t lastInterestCharge;
    // ежедневная капитализация, ежемесечная
    // проценты начисляются на увеличенную сумму

public:
    SavingsAccount(double balance, Currency currency, const std::string &accountName, double rate, double minimalBalance, Customer *owner, DataManager *dataManager);
    SavingsAccount(double balance, Currency currency, const std::string &accountName, double rate, Customer *owner, DataManager *dataManager);
    void applyDailyInterest();
    bool withdraw(double amount) override;
};

#endif
// если на балансе 0, то можно прописать деструктор и обнулить ссылку у владельца.