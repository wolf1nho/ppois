#ifndef TERMINAL_H
#define TERMINAL_H

#include "../account/BankAccount.h"
#include "../account/CurrencyConverter.h"
#include "Card.h"
#include "../account/Currency.h"

class Card;

class Terminal
{
    BankAccount *to;
    double amount;
    Currency currency;
    bool waitingCard;
    time_t waitingLimitTime;
    DataManager *dataManager;

public:
    Terminal(BankAccount *to, DataManager *dataManager);
    bool pay(Card &card);
    void setAmount(double amount, Currency currency);
    void setWaitingCardState();
    void updateWaitingCardState();
};

#endif