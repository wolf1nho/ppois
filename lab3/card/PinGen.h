#ifndef PIN_GEN_H
#define PIN_GEN_H

#include <random>

class PinGen
{
    static int randInt(int min, int max);

public:
    static int genPin(int lenght);
};
#endif