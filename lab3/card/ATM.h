#ifndef ATM_H
#define ATM_H

#include <vector>

#include "Card.h"
#include "../money/Money.h"
#include "ATMStorage.h"
#include "../account/Credit.h"

class Transaction;
class Credit;
class AccountTransaction;
class CurrencyConverter;
class DataManager;

enum class ATMState
{
    IDLE,
    CARDINSERTED,
    AUTHENTICATED,
    MAINTANANCE
};

class ATM
{
    ATMState state;
    Card *card;
    int failedPinInput;
    bool authenticated;
    ATMStorage storage;
    DataManager *dataManager;

public:
    ATM(ATMState state, DataManager *dataManager);
    void insertCard(Card &customerCard);
    void ejectCard();
    void enterPin(int pin);
    void reenterPin(int pin);
    void transfer(double amount, Currency currency, BankAccount *to, int pin, TransactionType type);
    double getBalance();
    void deposit(std::vector<Money> sum);
    void creditPayment(double amount, Currency currency, Credit *credit, int pin);

    std::vector<Money> withdraw(double amount, Currency currency);
};

#endif
