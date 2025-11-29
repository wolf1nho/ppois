#include "Customer.h"
#include <regex>
#include "VerificationService.h"
#include "exception/Exception.h"
#include "account/CurrentAccount.h"
#include "account/SavingsAccount.h"

Customer::Customer(const std::string &firstName,
                   const std::string &lastName,
                   const std::string &passport,
                   const std::string &phone,
                   const std::string &email,
                   const std::string &address,
                   DataManager *dataManager)
    : firstName(firstName),
      lastName(lastName),
      passportNumber(passport),
      phoneNumber(phone),
      email(email),
      address(address),
      isVerified(VerificationService::verifyCustomer(*this)),
      dataManager(dataManager)
{
    dataManager->generatorID.generateID(id);
    dataManager->addCustomer(this);
}

Customer::~Customer()
{
    for (auto *cr : credits)
    {
        delete cr;
    }
    credits.clear();
    for (auto *acc : accounts)
    {
        delete acc;
    }
    accounts.clear();
}

std::string Customer::getID() const { return id; }
std::string Customer::getFullName() const { return firstName + " " + lastName; }
std::string Customer::getPassportNumber() const { return passportNumber; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getAddress() const { return address; }
bool Customer::getVerificationStatus() const { return isVerified; }

void Customer::setPhoneNumber(const std::string &newPhone) { phoneNumber = newPhone; }
void Customer::setEmail(const std::string &newEmail) { email = newEmail; }
void Customer::setAddress(const std::string &newAddress) { address = newAddress; }
void Customer::setVerified(bool status) { isVerified = status; }

void Customer::verify() { VerificationService::verifyCustomer(*this); }

void Customer::takeCreditAndCreditCard(double creditSum, Currency currency, double interestRate, int monthCount, bool earlyRepayment,
                                       PaymentSystem system, const std::string &creditAndAccountName, const std::string &cardName)
{
    if (!credits.empty() && !credits.back()->isRepaid())
        throw Exception("Уже есть кредит");
    Credit *cr = new Credit(creditSum, currency, interestRate, this,
                            monthCount, earlyRepayment, creditAndAccountName, dataManager);
    cards.push_back(Card(credits.back()->getAccount(), system, CardType::CREDIT, cardName));
}

void Customer::addNewCard(BankAccount *account, PaymentSystem system, CardType type, const std::string &cardName)
{
    if (account->getType() == AccountType::Credit)
        throw Exception("");
    cards.push_back(Card(account, system, type, cardName));
}

void Customer::addCurrentAccountAndCardWithOverdraft(double balance, Currency currency, double overdraftLimit, double interestRate,
                                                     int maxOverdraftDuration, PaymentSystem system, CardType type,
                                                     const std::string &accountName, const std::string &cardName)
{
    CurrentAccount *ca = new CurrentAccount(balance, currency, accountName, overdraftLimit, interestRate, maxOverdraftDuration, this, dataManager);
    cards.push_back(Card(accounts.back(), system, type, cardName));
}

void Customer::addCurrentAccountAndCard(double balance, Currency currency, PaymentSystem system, CardType type, const std::string &accountName, const std::string &cardName)
{
    CurrentAccount *ca = new CurrentAccount(balance, currency, accountName, this, dataManager);
    cards.push_back(Card(accounts.back(), system, type, cardName));
}

void Customer::addRevocableSavingsAccount(double balance, Currency currency, double rate, double minimalBalance, const std::string &accountName)
{
    SavingsAccount *sa = new SavingsAccount(balance, currency, accountName, rate, minimalBalance, this, dataManager);
}

void Customer::addSavingsAccount(double balance, Currency currency, double rate, const std::string &accountName)
{
    SavingsAccount *sa = new SavingsAccount(balance, currency, accountName, rate, this, dataManager);
}

Credit *Customer::getCredit()
{
    if (credits.empty())
        throw Exception("нет кредита");
    return credits.back();
}

Card &Customer::getCard(const std::string &cardName)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getCardName() == cardName)
            return cards[i];
    }
    throw Exception("Карты с таким названием нет");
}

Wallet &Customer::getWallet()
{
    return wallet;
}

BankAccount *Customer::getAccount(const std::string &accountName)
{
    for (int i = 0; i < accounts.size(); i++)
        if (accounts[i]->getAccountName() == accountName)
            return accounts[i];
    throw Exception("Счета с таким названием нет");
}
