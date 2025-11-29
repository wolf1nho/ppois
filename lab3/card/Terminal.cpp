#include "Terminal.h"
#include "../getter/TimeGetter.h"
#include "../exception/Exception.h"
#include "../account/AccountTransaction.h"

Terminal::Terminal(BankAccount *to, DataManager *dataManager)
    : to(to), dataManager(dataManager)
{
}

void Terminal::setAmount(double amount, Currency currency)
{
    updateWaitingCardState();
    if (waitingCard)
        throw ExceptionTimeError("Уже ожидается оплата");
    this->amount = amount;
    this->currency = currency;
    if (!waitingCard)
    {
        setWaitingCardState();
    }
}

void Terminal::setWaitingCardState()
{
    if (waitingCard || TimeGetter::getTime() > waitingLimitTime)
    {
        waitingCard = false;
        waitingLimitTime = 0;
    }
    if (waitingCard)
        throw ExceptionTimeError("Уже ожидается оплата");
    waitingCard = true;
    waitingLimitTime = TimeGetter::waitOneMinute();
}

void Terminal::updateWaitingCardState()
{
    if (waitingCard || TimeGetter::getTime() > waitingLimitTime)
    {
        waitingCard = false;
        waitingLimitTime = 0;
    }
}

bool Terminal::pay(Card &card)
{
    AccountTransaction *transaction = new AccountTransaction(card.account, to, amount, to->getCurrency(), TransactionType::PAYMENT, dataManager);
    transaction->execute();
    if (card.hasCashback)
        card.cashback->addCashbackAmount(dataManager->getConverter()->convert(currency, card.account->getCurrency(), amount));
    return transaction->getStatus() == TransactionStatus::SUCCEED;
}