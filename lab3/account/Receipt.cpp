#include "Receipt.h"
#include "getter/Getter.h"
#include "getter/TimeGetter.h"

Receipt::Receipt(AccountTransaction &trans)
    : id(trans.id), fromID(trans.from->getID()),
      toID(trans.to->getID()), amount(trans.amount), currency(trans.from->getCurrency()),
      transactionTime(trans.transactionTime), status(trans.status), type(trans.type)
{
}

Receipt::Receipt(CreditPayment &crP)
    : id(crP.id), fromID(crP.from->getID()),
      toID(crP.credit->getID()), amount(crP.amount), currency(crP.currency),
      transactionTime(crP.transactionTime), status(crP.status), type(crP.type)
{
}

std::string Receipt::getStr()
{
  return "Сумма: " + std::to_string(amount) + "\nВалюта: " + Getter::getCurrency(currency) +
         "\nОтправитель: " + fromID + "\nПолучатель: " + toID + "\nТип транзакции: " + Getter::getTransactionType(type) +
         "\nВремя: " + TimeGetter::getStr(transactionTime);
}