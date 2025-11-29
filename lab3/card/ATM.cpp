#include "ATM.h"
#include "../exception/Exception.h"
#include "../account/AccountTransaction.h"
#include "../datamanager/DataManager.h"

ATM::ATM(ATMState state, DataManager *dataManager)
    : state(state), dataManager(dataManager)
{
    card = nullptr;
    failedPinInput = 0;
    authenticated = false;
    storage = ATMStorage();
}

void ATM::insertCard(Card &customerCard)
{
    if (state != ATMState::IDLE)
        throw ExceptionATMError("Невозможно вставить карту");
    card = &customerCard;
    if (card->status == CardStatus::BLOCKED)
        throw ExceptionCardBlockError("Карта заблокирована, необходимо завести новую");
    if (card->status == CardStatus::FROZEN)
        throw ExceptionCardFreezeError("Карта заморожена");
    if (card->status == CardStatus::EXPIRED)
        throw ExceptionExpirationDateError("Срок годности истек");
    if (card->account->isFrozen())
        throw ExceptionFrozenAccount("Счет заморожен");
    state = ATMState::CARDINSERTED;
}

void ATM::ejectCard()
{
    if (state != ATMState::CARDINSERTED && state != ATMState::AUTHENTICATED)
        throw ExceptionATMError("Карта не вставлена");
    card = nullptr;
    state = ATMState::IDLE;
    failedPinInput = 0;
}

void ATM::enterPin(int pin)
{
    if (state != ATMState::CARDINSERTED && state != ATMState::AUTHENTICATED)
        if (state == ATMState::MAINTANANCE)
            throw ExceptionATMError("ATM в режиме обслуживания");
        else
            throw ExceptionATMError("Чтобы ввести PIN, необходимо вставить карту");

    if (!card->verifyPin(pin))
    {
        if (++failedPinInput == 3)
        {
            card->freeze();
            throw ExceptionPinError("Пароль введен неверно 3 раза подряд. Карта заморожена");
        }
        throw ExceptionPinError("Пароль введен неверно");
    }
    state = ATMState::AUTHENTICATED;
    authenticated = true;
}

void ATM::reenterPin(int pin)
{
    if (!card->verifyPin(pin))
    {
        if (++failedPinInput == 3)
        {
            card->freeze();
            throw ExceptionPinError("Пароль введен неверно 3 раза подряд. Карта заморожена");
        }
        throw ExceptionPinError("Пароль введен неверно");
    }
    authenticated = true;
}

void ATM::transfer(double amount, Currency currency, BankAccount *to, int pin, TransactionType type)
{
    if (card->account->getType() == AccountType::Credit)
        throw ExceptionIncorrectAccountType("Указан кредитный счет");
    authenticated = false;
    reenterPin(pin);
    AccountTransaction *transaction = new AccountTransaction(card->account, to, amount, currency, type, dataManager);
    transaction->execute();
}

double ATM::getBalance()
{
    return card->account->getBalance();
}

void ATM::deposit(std::vector<Money> sum)
{
    Currency cur = card->account->getCurrency();
    double amount = 0;
    for (int i = 0; i < sum.size(); i++)
    {
        amount += dataManager->getConverter()->convert(sum[i].getCurrency(), cur, sum[i].getAmount());
    }
    storage.bringMoney(sum);
    card->account->deposit(amount);
    if (card->status == CardStatus::NOTACTIVATED)
        card->activate();
}

void ATM::creditPayment(double amount, Currency currency, Credit *credit, int pin)
{
    authenticated = false;
    reenterPin(pin);
    credit->creditPayments.back()->setFromAccount(card->account);
    credit->creditPayments.back()->setAmount(amount, currency);
    credit->creditPayments.back()->execute();
}

std::vector<Money> ATM::withdraw(double amount, Currency currency)
{
    if (!card->account->withdraw(dataManager->getConverter()->convert(currency, card->account->currency, amount)))
        throw ExceptionIncorrectAmount("Недостаточно средств");
    std::vector<Money> sumToAdd;
    std::map<Nominal, int> nominals = storage.getNominals(currency);

    for (auto it = nominals.rbegin(); it != nominals.rend(); ++it)
    {
        if (amount == 0)
            break;
        Nominal nominal = it->first;
        int &value = it->second;
        while (amount >= (double)nominal && amount > 0 && value != 0)
        {
            amount -= (double)nominal;
            value--;
            sumToAdd.emplace_back(nominal, currency);
        }
    }
    if (amount != 0)
    {
        storage.bringMoney(sumToAdd);
        throw ExceptionATMError("Невозможно выдать данную сумму");
    }
    return sumToAdd;
}