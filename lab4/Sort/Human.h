#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
protected:
    std::string name;
    unsigned age;
    unsigned height;

public:
    Human(const std::string &name, unsigned age, unsigned height)
        : name(name), age(age), height(height) {}
    std::string getName() { return name; };
    unsigned getAge() { return age; };
    unsigned getHeight() { return height; };
    bool operator==(const Human &other) { return height == other.height; };
    bool operator!=(const Human &other) { return height != other.height; };
    bool operator>(const Human &other) { return height > other.height; };
    bool operator<(const Human &other) { return height < other.height; };
    bool operator>=(const Human &other) { return height >= other.height; };
    bool operator<=(const Human &other) { return height <= other.height; };
};

#endif
