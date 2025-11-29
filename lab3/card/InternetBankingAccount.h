#ifndef INTERNETBANKING_H
#define INTERNETBANKING_H

#include <vector>
#include <string>

#include "../card/Card.h"
#include "../datamanager/DataManager.h"

class Credit;
class BankAccount;

class InternetBanking
{
    std::string profileName;
    std::string password;
    bool verificated;
    std::vector<Card *> cards;
    Card *currentCard;
    DataManager *dataManager;

public:
    InternetBanking(const std::string &password, Customer *customer, DataManager *dataManager);
    bool cardIsAdded(Card &card) const;
    void addCard(Card &card);
    void setCurrent(Card &card);
    void transfer(double amount, Currency currency, BankAccount *to, TransactionType type);
    double getBalance();
    void creditPayment(double amount, Currency currency, Credit *credit);
    void login(const std::string &password);
    void logout();
    std::string getProfileName();
    void addCashbackFunction(double rate);
    double getCashbackAmount();
    void TakeCashback();
};

#endif

// сделать в чеке выписку о погашении месячного платежа