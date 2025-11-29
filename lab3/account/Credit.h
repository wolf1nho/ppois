#ifndef CREDIT_H
#define CREDIT_H

#include <vector>
#include <ctime>
#include <string>

#include "CreditPayment.h"
#include "datamanager/DataManager.h"
#include "Currency.h"

class CreditAccount;
class Customer;
class CreditPayment;
class ATM;
class DataManager;
class BankAccount;
class InternetBanking;

class Credit
{
    friend class CreditAccount;
    friend class CreditPayment;
    friend class ATM;
    friend class InternetBanking;

    std::string id;
    double creditSum;
    double interestRate;
    time_t creditTakenTime;
    time_t creditStart;
    time_t creditPlannedEnd;
    time_t creditRealEnd;
    int initialMonthCount;
    time_t lastActivityDay;
    time_t nextPaymentLimitTime;
    CreditAccount *account;
    bool earlyRepayment;
    double monthlyPaymentAmount;
    double remainingMonthlyAmountToPay;
    double interestDebt;
    double totalPaidAmount;
    double totalPaidInterest;
    int totalDelayInDays;
    Customer *owner;
    std::vector<CreditPayment *> creditPayments;
    bool repaid;
    DataManager *dataManager;
    Currency currency;

    void closeCredit();
    void closeMonth();

public:
    Credit(double creditSum, Currency currency, double interestRate, Customer *owner,
           int monthCount, bool earlyRepayment, const std::string &creditAndAccountName, DataManager *dataManager);
    // ~Credit();
    std::string getID() const;
    BankAccount *getAccount();
    double getCurrentDebt();
    double getCurrentDebtWithoutInterest();
    double getMonthlyPaymentAmount();
    double getInterestDebt();
    double getCurrentDelayInDays();
    double getCurrentTotalDelayInDays();
    double getTotalPaidAmount();
    double getTotalPaidInterest();

    void calculateMonthlyPaymentAmount();
    void calculateInterest();

    bool thisMonthIsPaid();

    bool checkDelayExistance();

    void updateNextPaymentLimitTime();

    void deposit(double amount);

    void addNextPayment();

    bool isRepaid();

    CreditPayment *getPayment();
};

#endif