#ifndef TIMEGETTER_H
#define TIMEGETTER_H

#include <ctime>
#include <string>

class TimeGetter
{
public:
    static time_t getTime();
    static time_t getTodayMidnight();
    static time_t getMidnight(time_t day);
    static int getMonthDayCount(time_t day);
    static time_t getNextMonthDaysCount(time_t day);
    static time_t getSameDayNextMonth(time_t time);
    static time_t getNextDayNextMonth(time_t time);
    static time_t getNextDayMidnight();
    static time_t getDayThisMonth(int count);
    static time_t getDayInNextMonth(int count);
    static time_t getExpirationDate(int month, int year);
    static time_t getExpirationDate(int durationInYears);
    static int getThisYear();
    static int getThisMonth();
    static int getYear(time_t time);
    static int getMonth(time_t time);
    static time_t getSameDayInFewMonth(int months);
    static time_t getSameDaypreviousMonth();
    static double getDiffInSeconds(time_t time1, time_t time2);
    static time_t waitOneMinute();
    static std::string getStr(time_t time);
};

#endif
