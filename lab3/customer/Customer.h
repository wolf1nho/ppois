#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "../account/BankAccount.h"
#include "../card/Card.h"
#include "../datamanager/DataManager.h"
#include "../money/Wallet.h"

class BankAccount;
class Card;
class VerificationService;
class Credit;
class DataManager;
enum class CardType;
class Contact;

class Customer
{
private:
    friend class VerificationService;
    friend class Credit;
    friend class BankAccount;
    friend class Card;
    friend class Contact;

    std::string id;
    std::string firstName;
    std::string lastName;
    std::string passportNumber;
    std::string phoneNumber;
    std::string email;
    std::string address;
    bool isVerified;
    std::vector<Credit *> credits;
    std::vector<BankAccount *> accounts;
    std::vector<Card> cards;
    DataManager *dataManager;
    Wallet wallet;

    void addCreditAccount();

public:
    Customer();
    Customer(const std::string &firstName,
             const std::string &lastName,
             const std::string &passport,
             const std::string &phone,
             const std::string &email,
             const std::string &address,
             DataManager *dataManager);

    ~Customer();
    std::string getID() const;
    std::string getFullName() const;
    std::string getPassportNumber() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getAddress() const;
    bool getVerificationStatus() const;
    void verify();
    void setPhoneNumber(const std::string &newPhone);
    void setEmail(const std::string &newEmail);
    void setAddress(const std::string &newAddress);
    void setVerified(bool status);

    void takeCreditAndCreditCard(double creditSum, Currency currency, double interestRate, int monthCount, bool earlyRepayment,
                                 PaymentSystem system, const std::string &creditAndAccountName, const std::string &cardName);

    void addNewCard(BankAccount *account, PaymentSystem system, CardType type, const std::string &cardName);
    void addCurrentAccountAndCardWithOverdraft(double balance, Currency currency, double overdraftLimit, double interestRate, int maxOverdraftDuration,
                                               PaymentSystem system, CardType type, const std::string &accountName, const std::string &cardName);
    void addCurrentAccountAndCard(double balance, Currency currency, PaymentSystem system, CardType type, const std::string &accountName, const std::string &cardName);
    void addRevocableSavingsAccount(double balance, Currency currency, double rate, double minimalBalance, const std::string &accountName);
    void addSavingsAccount(double balance, Currency currency, double rate, const std::string &accountName);

    Credit *getCredit();

    Card &getCard(const std::string &cardName);
    BankAccount *getAccount(const std::string &accountName);
    Wallet &getWallet();
};

#endif