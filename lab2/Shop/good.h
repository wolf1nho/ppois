#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

class Good
{
protected:
    double price;

public:
    Good(const double price);
    double get_price() const;
};

#endif