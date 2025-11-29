#include "CardNumGen.h"
#include <random>

#include "../exception/Exception.h"

int CardNumGen::randInt(int min, int max)
{
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int CardNumGen::luhnCheckDigit(const std::string &numberWithoutCheck) // Алгоритм Луна
{
    int sum = 0;
    bool doubleDigit = true;

    for (int i = numberWithoutCheck.size() - 1; i >= 0; i--)
    {
        int digit = numberWithoutCheck[i] - '0';
        if (doubleDigit)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (10 - (sum % 10)) % 10;
}

std::string CardNumGen::generateCardNumber(std::string &cardNum, PaymentSystem ps)
{

    if (ps == PaymentSystem ::Visa)
    {
        cardNum = "4";
        for (int i = 0; i < 14; i++)
            cardNum += std::to_string(randInt(0, 9));
    }
    else if (ps == PaymentSystem::Mastercard)
    {
        if (randInt(0, 1) == 0)
        {
            cardNum = std::to_string(randInt(51, 55));
        }
        else
        {
            cardNum = std::to_string(randInt(2221, 2720));
        }
        while (cardNum.size() < 15)
            cardNum += std::to_string(randInt(0, 9));
    }
    else if (ps == PaymentSystem::Mir)
    {
        cardNum = "220100";
        while ((int)cardNum.size() < 15)
        {
            cardNum += std::to_string(randInt(0, 9));
        }
    }
    else if (ps == PaymentSystem::Belcard)
    {
        cardNum = "911239";
        while ((int)cardNum.size() < 15)
        {
            cardNum += std::to_string(randInt(0, 9));
        }
    }
    else
    {
        throw Exception("Неверная платежная система");
    }

    cardNum += std::to_string(luhnCheckDigit(cardNum));
    return cardNum;
}
