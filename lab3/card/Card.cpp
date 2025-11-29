#include "Card.h"
#include "account/Credit.h"
#include "exception/Exception.h"
#include "PinGen.h"
#include "CardNumGen.h"

Card::Card(BankAccount *account, PaymentSystem paymentSystem, CardType type, const std::string &cardName)
    : account(account), hasCashback(false), cashback(nullptr), ownerName(account->owner->getFullName()),
      pinIsShowed(false), status(CardStatus::NOTACTIVATED), type(type),
      pin(PinGen::genPin(4)), expiry(ExpirationDate(TimeGetter::getExpirationDate(3))),
      paymentSystem(paymentSystem), cardName(cardName)
{
    for (int i = 0; i < account->owner->cards.size(); i++)
        if (account->owner->cards[i].getCardName() == cardName)
            throw Exception("уже есть карта с таким именем");
    CardNumGen::generateCardNumber(cardNum, paymentSystem);
    if (type == CardType::CREDIT && account->type != AccountType::Credit)
        throw Exception("Кредитная карта выдается только при приобретении кредита");
    if (account->type == AccountType::Savings)
        throw Exception("Карта для сберегательного счета не выдается");
}

Card::~Card()
{
    if (cashback)
        delete cashback;
}

std::string Card::getCardName()
{
    return cardName;
}

int Card::showPin()
{
    if (pinIsShowed)
        throw ExceptionPinError("Пинкод уже был сообщен");
    else
    {
        pinIsShowed = true;
        return pin;
    }
}

bool Card::verifyPin(int pin)
{
    return pin == this->pin;
}

void Card::activate()
{
    if (status == CardStatus::NOTACTIVATED)
        status = CardStatus::ACTIVE;
    else
        throw ExceptionCardActivationError("Карта уже активирована");
}

void Card::freeze()
{
    if (status == CardStatus::ACTIVE)
        status = CardStatus::FROZEN;
    else
        throw ExceptionCardFreezeError("Заморозить можно только активную карту");
}

void Card::unfreeze()
{
    if (status == CardStatus::FROZEN)
        status = CardStatus::ACTIVE;
    else
        throw ExceptionCardFreezeError("Раморозить можно только замороженную карту");
}

void Card::block()
{
    if (status == CardStatus::ACTIVE)
        status = CardStatus::BLOCKED;
    else
        throw ExceptionCardFreezeError("Заблокировать можно только активную карту");
}

std::string Card::getCardNum()
{
    return cardNum;
}

ExpirationDate Card::getExpirationDate()
{
    return expiry;
}
