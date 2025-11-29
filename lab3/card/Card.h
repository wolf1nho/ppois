#ifndef CARD_H
#define CARD_H

#include <string>

#include "../account/BankAccount.h"

#include "ExpirationDate.h"
#include "PaymentSystem.h"
#include "../datamanager/DataManager.h"
#include "Cashback.h"

enum class CardType
{
    DEBIT,
    CREDIT,
    VIRTUAL,
};

enum class CardStatus
{
    ACTIVE,
    NOTACTIVATED,
    FROZEN,
    BLOCKED,
    EXPIRED,
};

class BankAccount;
class Cashback;
class ExpirationDate;
class InternetBanking;
class Terminal;

class Card
{
    friend class Cashback;
    friend class ATM;
    friend class InternetBanking;
    friend class Terminal;

    std::string cardName;
    bool hasCashback;
    Cashback *cashback;
    BankAccount *account;
    std::string ownerName;
    PaymentSystem paymentSystem;
    std::string cardNum;
    ExpirationDate expiry;

    int pin;
    bool pinIsShowed;
    CardStatus status;
    CardType type;

    // BankAccount *getAccount();

public:
    // Card(BankAccount *account, int durationInYears, PaymentSystem paymentSystem, CardType type, const std::string &cardName);
    Card(BankAccount *account, PaymentSystem paymentSystem, CardType type, const std::string &cardName);
    ~Card();
    std::string getCardName();
    int showPin();
    bool verifyPin(int pin);
    void activate();
    void block();
    void freeze();
    void unfreeze();
    std::string getCardNum();
    ExpirationDate getExpirationDate();
};

#endif