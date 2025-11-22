#ifndef SCALES_H
#define SCALES_H
#include <string>
#include <cmath>

#include "../Human/human.h"

class Scales
{
private:
    std::string brand;
    std::string model;
    double max_weight;    // максимальный вес в кг
    double precision;     // точность в граммах
    bool electronic;      // электронные или механические
    bool has_backlight;   // наличие подсветки
    bool auto_off;        // автоотключение
    bool battery_powered; // питание от батареек
    bool usb_chargeable;  // возможность зарядки по USB
    double platform_size; // размер платформы в см квадрратных
    bool is_valid_precision();

public:
    Scales(const std::string &brand, const std::string &model,
           double max_weight, double precision,
           bool electronic, bool has_backlight,
           bool auto_off, bool battery_powered,
           bool usb_chargeable, double platform_size);
    double get_weight(Human &human);
};

#endif