#include "scales.h"
#include "../Exception/exception.h"

Scales::Scales(const std::string &brand, const std::string &model,
               double max_weight, double precision,
               bool electronic, bool has_backlight,
               bool auto_off, bool battery_powered,
               bool usb_chargeable, double platform_size)
    : brand(brand), model(model), max_weight(max_weight), precision(precision),
      electronic(electronic), has_backlight(has_backlight),
      auto_off(auto_off),
      battery_powered(battery_powered), usb_chargeable(usb_chargeable),
      platform_size(platform_size)
{
    if (!is_valid_precision())
        throw ExceptionIncorrectPrecision("Неверная точность");
}

bool Scales::is_valid_precision()
{
    double log_value = std::log10(precision);
    return (log_value - int(log_value) == 0);
}

double Scales::get_weight(Human &human)
{
    return human.weight;
}