#include "Credit.h"
#include "getter/TimeGetter.h"
#include "exception/Exception.h"

Credit::Credit(double creditSum, Currency currency, double interestRate, Customer *owner,
               int monthCount, bool earlyRepayment, const std::string &creditAndAccountName, DataManager *dataManager)
    : creditSum(creditSum), currency(currency), interestRate(interestRate), initialMonthCount(monthCount), earlyRepayment(earlyRepayment),
      interestDebt(0), totalPaidAmount(0), account(nullptr), repaid(false), dataManager(dataManager), lastActivityDay(TimeGetter::getTodayMidnight())
{
    if (monthCount < 2)
        throw ExceptionTimeError("Кредит выдается минимум на 2 месяца");
    dataManager->generatorID.generateID(id);
    creditTakenTime = TimeGetter::getTime();
    creditStart = TimeGetter::getDayInNextMonth(25);
    dataManager->addCredit(this);
    account = new CreditAccount(this, currency, creditAndAccountName, owner, dataManager);
    dataManager->addAccount(account);
    if (!owner)
        throw Exception("У кредита должен быть владелец");
    this->owner = owner;
    owner->credits.push_back(this);

    creditPlannedEnd = TimeGetter::getSameDayInFewMonth(--monthCount); // первый месяц кредит не платится поэтому отнимаю 1 месяц

    monthlyPaymentAmount = creditSum / monthCount;

    nextPaymentLimitTime = TimeGetter::getNextDayNextMonth(creditStart);

    remainingMonthlyAmountToPay = monthlyPaymentAmount;

    totalPaidInterest = 0;
    CreditPayment *newcrp = new CreditPayment(this, dataManager);
    creditPayments.push_back(newcrp);
    dataManager->addCredit(this);
}


std::string Credit::getID() const
{
    return id;
}

double Credit::getMonthlyPaymentAmount()
{
    return monthlyPaymentAmount;
}

double Credit::getInterestDebt()
{
    calculateInterest();
    return interestDebt;
}

void Credit::calculateInterest()
{
    time_t today = TimeGetter::getTodayMidnight();
    if (today == this->lastActivityDay)
        return;
    double seconds = std::difftime(today, lastActivityDay);
    double days = seconds / (60 * 60 * 24);
    interestDebt += (creditSum - totalPaidAmount) * (interestRate / 100.0) * (days / 365.0);
    lastActivityDay = today;
}

void Credit::addNextPayment()
{
    CreditPayment *newcrp = new CreditPayment(this, dataManager);
    creditPayments.push_back(newcrp);
}

double Credit::getCurrentDebt()
{
    return getInterestDebt() + getCurrentDebtWithoutInterest();
}

double Credit::getCurrentDebtWithoutInterest()
{
    return remainingMonthlyAmountToPay;
}

void Credit::deposit(double amount)
{
    if (amount <= 0)
        throw ExceptionIncorrectAmount("Сумма неположительна");
    if (!earlyRepayment && amount != getCurrentDebt())
        throw ExceptionIncorrectAmount("Этот кредит нельзя погашать заранее");
    calculateInterest();
    if (creditSum - totalPaidAmount + interestDebt < amount)
    {
        throw ExceptionIncorrectAmount("Введена сумма больше долга");
    }
    totalPaidAmount += amount;
    while (amount != 0)
    {
        if (amount >= remainingMonthlyAmountToPay + interestDebt)
        {
            amount -= remainingMonthlyAmountToPay + interestDebt;
            totalPaidAmount += interestDebt;
            interestDebt = 0;
            remainingMonthlyAmountToPay = 0;
            updateNextPaymentLimitTime();

            if (nextPaymentLimitTime > creditPlannedEnd)
            {
                closeCredit(); // кредит закрыт
                return;
            }
            remainingMonthlyAmountToPay = monthlyPaymentAmount;
        }
        else
        {
            amount -= interestDebt;
            interestDebt = 0;
            remainingMonthlyAmountToPay -= amount;
            amount = 0;
            if (remainingMonthlyAmountToPay == 0)
            {
                updateNextPaymentLimitTime();
            }
        }
    }
    addNextPayment();
}

void Credit::closeCredit()
{
    creditRealEnd = TimeGetter::getTime();
    repaid = true;
}

void Credit::updateNextPaymentLimitTime()
{
    time_t now = TimeGetter::getTime();
    time_t newNextPaymentLimitTime = TimeGetter::getSameDayNextMonth(nextPaymentLimitTime);
    if (now > nextPaymentLimitTime)
    {
        if (now > newNextPaymentLimitTime)
        {
            totalDelayInDays += TimeGetter::getDiffInSeconds(newNextPaymentLimitTime, nextPaymentLimitTime);
        }
        else
        {
            totalDelayInDays += TimeGetter::getDiffInSeconds(now, nextPaymentLimitTime);
        }
    }
    nextPaymentLimitTime = newNextPaymentLimitTime;
}

double Credit::getCurrentDelayInDays()
{
    time_t now = TimeGetter::getTime();
    if (now > nextPaymentLimitTime)
        return TimeGetter::getDiffInSeconds(now, nextPaymentLimitTime);
    else
        return 0;
}

bool Credit::checkDelayExistance()
{
    return getCurrentDelayInDays() == 0;
}

double Credit::getCurrentTotalDelayInDays()
{
    time_t now = TimeGetter::getTime();
    if (now > nextPaymentLimitTime)
        return totalDelayInDays + TimeGetter::getDiffInSeconds(now, nextPaymentLimitTime);
    else
        return totalDelayInDays;
}

double Credit::getTotalPaidAmount() { return totalPaidAmount; }

double Credit::getTotalPaidInterest() { return totalPaidInterest; }

bool Credit::thisMonthIsPaid()
{
    return TimeGetter::getDayThisMonth(26) != nextPaymentLimitTime;
}

BankAccount *Credit::getAccount() { return account; }

bool Credit::isRepaid()
{
    return repaid;
}

CreditPayment *Credit::getPayment()
{
    return creditPayments.back();
}