#ifndef EXPIRATIONDATE_H
#define EXPIRATIONDATE_H

#include <ctime>
#include <string>

#include "getter/TimeGetter.h"

class ExpirationDate
{
    int month;
    int year;
    time_t expiry;

public:
    ExpirationDate(time_t expiry);
    int getMonth();
    int getYear();
    std::string getExpirationDate();
};

#endif