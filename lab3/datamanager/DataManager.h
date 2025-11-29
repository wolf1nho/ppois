#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
#include <vector>
#include <unordered_map>
#include <stdexcept>

#include "generator/GeneratorID.h"
#include "account/Transaction.h"
#include "account/Credit.h"
#include "customer/Customer.h"
#include "card/ATM.h"
#include "card/Card.h"
#include "account/BankAccount.h"
#include "card/Terminal.h"
#include "account/CurrencyConverter.h"

class Credit;
class Customer;
class Card;
class Transaction;
class BankAccount;
class BankSafeBox;

class DataManager
{
    GeneratorID generatorID;
    CurrencyConverter *converter;

    std::unordered_map<std::string, Transaction *> transactions;

    std::unordered_map<std::string, Credit *> credits;

    std::unordered_map<std::string, Customer *> customers;

    std::unordered_map<std::string, BankAccount *> accounts;

public:
    friend class Customer;
    friend class Credit;
    friend class Transaction;
    friend class BankAccount;
    friend class BankSafeBox;
    void addCredit(Credit *credit);
    void addCustomer(Customer *customer);
    void addTransaction(Transaction *transaction);
    void addAccount(BankAccount *BankAccount);
    CurrencyConverter *getConverter();
    DataManager(CurrencyConverter *converter);
    ~DataManager();
};

#endif