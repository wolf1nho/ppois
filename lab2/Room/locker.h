#ifndef LOCKER_H
#define LOCKER_H
#include "../Reception/passkey.h"
#include "../Mirror/mirror.h"

class PassKey;
class DressingRoom;

class Locker
{
    friend class PassKey;
    friend class DressingRoom;

    unsigned num;
    bool locked;
    bool linked;
    PassKey *passkey;
    char gender;          // female = f; male = m;
    unsigned capacity;    // вместимость в литрах
    bool damaged;         // поврежден ли
    bool has_ventilation; // есть ли вентиляция
    bool has_mirror;      // есть ли зеркало на дверце
    std::string material; // материал: "metal", "plastic", "wood"
    std::string color;    // цвет шкафчика
    Mirror mirror;

public:
    Locker(const char gender, const unsigned num);
    Locker(PassKey *passkey, const unsigned num, char gender, unsigned capacity, bool is_damaged,
           bool has_ventilation, bool has_mirror, std::string material, std::string color);
    bool is_damaged();
    std::string get_color();
    std::string get_material();
    bool get_has_mirror();
    bool get_has_ventilation();
    bool get_capacity();

    bool is_locked();
    bool is_opened();
    void link(PassKey *passkey);
    void unlink();
};

#endif