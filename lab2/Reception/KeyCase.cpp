#include "KeyCase.h"

void KeyCase::add(PassKey passkey)
{
    passkeys.push_back({passkey, nullptr});
}

bool KeyCase::is_empty()
{
    if (passkeys.size() == 0)
        return true;
    else
        return false;
}
