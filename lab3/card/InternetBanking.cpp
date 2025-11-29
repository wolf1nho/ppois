#include "InternetBanking.h"
#include <algorithm>
#include "../exception/Exception.h"
#include "../account/AccountTransaction.h"
#include "../account/CreditPayment.h"

InternetBanking::InternetBanking(const std::string &password, Customer *customer, DataManager *dataManager)
    : password(password), profileName(customer->getFullName()), dataManager(dataManager),
      currentCard(nullptr), verificated(false) {}

void InternetBanking::login(const std::string &password)
{
    verificated = (password == this->password);
}

void InternetBanking::logout()
{
    verificated = false;
}

std::string InternetBanking::getProfileName()
{
    return profileName;
}

bool InternetBanking::cardIsAdded(Card &card) const
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    return std::find(cards.begin(), cards.end(), &card) != cards.end();
}

void InternetBanking ::addCard(Card &card)
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (!cardIsAdded(card))
        cards.push_back(&card);
    if (cards.size() == 1)
        setCurrent(card);
}

void InternetBanking::setCurrent(Card &card)
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cardIsAdded(card))
        currentCard = &card;
    else
        throw ExceptionInternetBankingError("Карта не добавлена");
}

double InternetBanking::getBalance()
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    return currentCard->account->getBalance();
}

void InternetBanking::transfer(double amount, Currency currency, BankAccount *to, TransactionType type)
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    AccountTransaction *transaction = new AccountTransaction(currentCard->account, to, amount, currency, type, dataManager);
    transaction->execute();
}

void InternetBanking::creditPayment(double amount, Currency currency, Credit *credit)
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    credit->creditPayments.back()->setFromAccount(currentCard->account);
    credit->creditPayments.back()->setAmount(amount, currency);
    credit->creditPayments.back()->execute();
}

void InternetBanking::addCashbackFunction(double rate)
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    if (currentCard->hasCashback)
        throw Exception("");
    currentCard->hasCashback = true;
    currentCard->cashback = new Cashback(rate, currentCard);
}

double InternetBanking::getCashbackAmount()
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    if (!currentCard->cashback)
        throw Exception("");
    return currentCard->cashback->getAmount();
}

void InternetBanking::TakeCashback()
{
    if (!verificated)
        throw ExceptionVerificationError("Вы не вошли в аккаунт");
    if (cards.empty())
        throw Exception("");
    if (!currentCard->cashback)
        throw Exception("");
    return currentCard->cashback->TakeCash();
}

// поплнение счета