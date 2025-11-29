#ifndef CASHBACK_H
#define CASHBACK_H

#include <ctime>

#include "Card.h"

class Card;

class Cashback
{
    Card *card;
    double rate;
    double amount;
    time_t endTimeToTakeCash;

public:
    Cashback(double rate, Card *card);
    void TakeCash();
    double getAmount();
    void addCashbackAmount(double Amount);
    void updateAmount(); // проверяет не просрочено ли получение кешбека
};

#endif