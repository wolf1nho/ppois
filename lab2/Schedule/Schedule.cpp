#include "Schedule.h"

Schedule::Schedule() : open_time(7u), close_time(23u) {}
Schedule::Schedule(unsigned open_time, unsigned close_time) : open_time(open_time), close_time(close_time)
{
    if (open_time > close_time)
    {
        throw ExceptionIncorrectOpenAndCloseTime("Время закрытия меньеш времени открытия");
    }
    if (open_time > 23 || open_time < 0 || close_time > 23 || close_time < 0)
    {
        throw ExceptionIncorrectTimeValue("В сутках 24 часа (от 0 до 23)");
    }
}

unsigned Schedule::get_open_time()
{
    return open_time;
}
unsigned Schedule::get_close_time()
{
    return close_time;
}