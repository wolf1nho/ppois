#ifndef CARD_NUM_GEN_H
#define CARD_NUM_GEN_H

#include <string>

#include "PaymentSystem.h"

class CardNumGen
{
    static int randInt(int min, int max);
    static int luhnCheckDigit(const std::string &numberWithoutCheck);

public:
    static std::string generateCardNumber(std::string &cardNum, PaymentSystem ps);
};

#endif