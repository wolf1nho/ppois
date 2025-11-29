#ifndef GETTER_H
#define GETTER_H

#include <string>

#include "../account/Currency.h"
#include "../account/Transaction.h"

class Getter
{
public:
    static std::string getCurrency(Currency cur);
    static std::string getTransactionType(TransactionType type);
};

#endif