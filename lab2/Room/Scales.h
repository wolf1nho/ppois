#ifndef SCALES_H
#define SCALES_H
#include <string>
#include <cmath>

#include "Human/Human.h"

class Scales
{
private:
    std::string brand;
    std::string model;
    double max_weight;
    double precision;
    bool electronic;
    bool has_backlight;
    bool auto_off;
    bool battery_powered;
    bool usb_chargeable;
    double platform_size;
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