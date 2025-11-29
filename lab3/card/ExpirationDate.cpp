#include "ExpirationDate.h"

ExpirationDate::ExpirationDate(time_t expiry)
    : expiry(expiry), month(TimeGetter::getMonth(expiry)), year(TimeGetter::getYear(expiry)) {}

int ExpirationDate::getMonth()
{
    return month;
}

int ExpirationDate ::getYear()
{
    return year;
}

std::string ExpirationDate::getExpirationDate()
{
    return std::to_string(month) + '/' + std::to_string(year);
}