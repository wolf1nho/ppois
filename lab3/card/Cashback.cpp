#include "Cashback.h"
#include "getter/TimeGetter.h"

Cashback::Cashback(double rate, Card *card) : rate(rate), amount(0), card(card)
{
    endTimeToTakeCash = TimeGetter::getDayInNextMonth(1);
}

void Cashback::updateAmount()
{
    if (TimeGetter::getTime() > endTimeToTakeCash)
    {
        endTimeToTakeCash = TimeGetter::getSameDayNextMonth(endTimeToTakeCash);
        amount = 0;
    }
}

double Cashback::getAmount()
{
    updateAmount();
    return amount;
}

void Cashback::TakeCash()
{
    updateAmount();
    if (amount == 0)
        return;

    card->account->deposit(amount);
    amount = 0;
}

void Cashback::addCashbackAmount(double amount)
{
    updateAmount();
    this->amount += amount * rate / 100;
}