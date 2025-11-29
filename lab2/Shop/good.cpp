#include "good.h"
#include "../Exception/exception.h"

Good::Good(const double price)
    : price(price)
{
    if (price <= 0)
        throw ExceptionIncorrectPrice("Неположительная стоимость");
}

double Good::get_price() const { return price; }