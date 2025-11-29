#include "TimeGetter.h"
#include "../exception/Exception.h"

time_t TimeGetter::getTime()
{
    return time(nullptr);
}

time_t TimeGetter::getTodayMidnight()
{
    std::time_t now = getTime();
    std::tm *today = std::localtime(&now);

    today->tm_hour = 0;
    today->tm_min = 0;
    today->tm_sec = 0;

    return mktime(today);
}

time_t TimeGetter::getMidnight(time_t day)
{
    std::tm *midnight = std::localtime(&day);

    midnight->tm_hour = 0;
    midnight->tm_min = 0;
    midnight->tm_sec = 0;

    return mktime(midnight);
}

int TimeGetter::getMonthDayCount(time_t day)
{
    day = getMidnight(day);
    std::tm *nextMonth = std::localtime(&day);
    nextMonth->tm_mon += 1;
    time_t nextMonthDay = mktime(nextMonth);
    double seconds = std::difftime(nextMonthDay, day);
    return seconds / (60 * 60 * 24);
}

time_t TimeGetter::getSameDayNextMonth(time_t time)
{
    int dayInMonth = getMonthDayCount(time);

    std::tm *day = std::localtime(&time);

    day->tm_hour = 0;
    day->tm_min = 0;
    day->tm_sec = 0;
    day->tm_mday += dayInMonth;

    return mktime(day);
}

time_t TimeGetter::getNextDayNextMonth(time_t time)
{
    int dayInMonth = getMonthDayCount(time);

    std::tm *day = std::localtime(&time);

    day->tm_hour = 0;
    day->tm_min = 0;
    day->tm_sec = 0;
    day->tm_mday += dayInMonth + 1;

    return mktime(day);
}

time_t TimeGetter::getNextDayMidnight()
{
    std::time_t now = getTime();
    std::tm *nextMidnight = std::localtime(&now);

    nextMidnight->tm_hour = 0;
    nextMidnight->tm_min = 0;
    nextMidnight->tm_sec = 0;
    nextMidnight->tm_mday += 1;

    return mktime(nextMidnight);
}

time_t TimeGetter::getDayInNextMonth(int count) // от 1 до 31
{
    if (count < 1)
        throw ExceptionIncorrectDayCount("В перечислении используются натуральные числа");
    std::time_t now = getTime();
    std::tm *midnight = std::localtime(&now);
    midnight->tm_hour = 0;
    midnight->tm_min = 0;
    midnight->tm_sec = 0;
    midnight->tm_mon += 1;
    midnight->tm_mday = count;

    return mktime(midnight);
}

time_t TimeGetter::getDayThisMonth(int count)
{
    if (count < 1)
        throw ExceptionIncorrectDayCount("В перечислении используются натуральные числа");
    std::time_t now = getTime();
    std::tm *midnight = std::localtime(&now);
    midnight->tm_hour = 0;
    midnight->tm_min = 0;
    midnight->tm_sec = 0;
    midnight->tm_mon += 1;
    midnight->tm_mday = -1 + count;

    return mktime(midnight);
}

time_t TimeGetter::getExpirationDate(int month, int year)
{
    struct tm custom_time;

    custom_time.tm_year = year - 1900;
    custom_time.tm_mon = month - 1;
    custom_time.tm_mday = 0;
    custom_time.tm_hour = 0;
    custom_time.tm_min = 0;
    custom_time.tm_sec = 0;

    return mktime(&custom_time);
}

time_t TimeGetter::getExpirationDate(int durationInYears)
{
    std::time_t now = getTime();
    std::tm *expiry = std::localtime(&now);

    expiry->tm_sec = 0;
    expiry->tm_min = 0;
    expiry->tm_hour = 0;
    expiry->tm_mday = 1;
    expiry->tm_mon += 1;
    expiry->tm_year += 3;

    return mktime(expiry);
}

int TimeGetter::getThisYear()
{
    time_t current_time = getTime();
    struct tm *time_info = localtime(&current_time);

    return time_info->tm_year + 1900;
}

int TimeGetter::getThisMonth()
{
    time_t current_time = getTime();
    struct tm *time_info = localtime(&current_time);

    return time_info->tm_mon + 1;
}

double TimeGetter::getDiffInSeconds(time_t time1, time_t time2)
{
    return difftime(time2, time1);
}

time_t TimeGetter::waitOneMinute()
{
    std::time_t now = getTime();
    std::tm *minute = std::localtime(&now);

    minute->tm_min++;

    return mktime(minute);
}

std::string TimeGetter::getStr(time_t time)
{
    char c[20];
    std::strftime(c, 20, "%d.%m.%Y %H:%M:%S", localtime(&time));
    std::string str = c;
    return str;
}

time_t TimeGetter::getSameDayInFewMonth(int months)
{
    if (months < 1)
        throw ExceptionIncorrectDayCount("В перечислении используются натуральные числа");
    std::time_t now = getTime();
    std::tm *midnight = std::localtime(&now);
    midnight->tm_hour = 0;
    midnight->tm_min = 0;
    midnight->tm_sec = 0;
    midnight->tm_mon += months;

    return mktime(midnight);
}

int TimeGetter::getYear(time_t time)
{

    struct tm *time_info = localtime(&time);

    return time_info->tm_year + 1900;
}
int TimeGetter::getMonth(time_t time)
{
    struct tm *time_info = localtime(&time);

    return time_info->tm_mon + 1;
}