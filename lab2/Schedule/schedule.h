#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "../Human/administrator.h"
#include <string>
#include "../Exception/exception.h"

class Schedule
{
    friend class Administrator;

    unsigned open_time;
    unsigned close_time;

public:
    Schedule();
    Schedule(unsigned open_time, unsigned close_time);
    unsigned get_open_time();
    unsigned get_close_time();
};

#endif