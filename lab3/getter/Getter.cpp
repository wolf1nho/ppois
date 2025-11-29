#include "Getter.h"
#include "exception/Exception.h"

std::string Getter::getCurrency(Currency cur)
{
    switch (cur)
    {
    case Currency::BYN:
        return "BYN";
    case Currency::EUR:
        return "EUR";
    case Currency::USD:
        return "USD";
    }
    throw Exception("Неверный аргумент");
}

std::string Getter::getTransactionType(TransactionType type)
{
    switch (type)
    {
    case TransactionType::PAYMENT:
        return "payment";
    case TransactionType::TRANSFER:
        return "transfer";
    case TransactionType::SALARY:
        return "salary";
    case TransactionType::TAX:
        return "tax";
    case TransactionType::RETURN:
        return "return";
    }
    throw Exception("неверный аргумент");
}