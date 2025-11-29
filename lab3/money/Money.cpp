#include "Money.h"

Money::Money(Nominal nominal, Currency currency)
    : nominal(nominal), currency(currency) {}

double Money::getAmount() const { return static_cast<double>(nominal); }
Currency Money::getCurrency() const { return currency; }
Nominal Money::getNominal() const { return nominal; }
bool Money::operator==(const Money &other) const { return nominal == other.nominal && currency == other.currency; }