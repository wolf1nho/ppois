#ifndef ROOM_H
#define ROOM_H

class Cleaner;

class Room
{
    friend class Cleaner;

    double area;
    bool cleaned;

public:
    Room(const double area);
    Room(const double area, const bool cleaned);
    bool is_cleaned();
};

#endif