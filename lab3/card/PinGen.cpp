#include "PinGen.h"
#include <cmath>

int PinGen::randInt(int min, int max)
{
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int PinGen::genPin(int lenght)
{
    int i = pow(10, lenght - 1);
    int pin = i * randInt(1, 9);
    while (i != 1)
    {
        i /= 10;
        pin += i * randInt(0, 9);
    }
    return pin;
}