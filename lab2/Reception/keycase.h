#ifndef KEYCASE_H
#define KEYCASE_H
#include <vector>
#include "../Human/receptionist.h"
#include "passkey.h"
// #include "subscription.h"

class Subscription;
class PassKey;

class KeyCase
{
    friend class Receptionist;

    std::vector<std::pair<PassKey, Subscription *>> passkeys;

public:
    void add(PassKey passkey);
    bool is_empty();
};

#endif