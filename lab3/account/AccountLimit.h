#ifndef ACCOUNTLIMIT_H
#define ACCOUNTLIMIT_H

class AccountLimit
{
    double maxAmount;
    double currentUsage;

public:
    AccountLimit(double maxAmount);
    bool canPerform(const double amount) const;

    void addUsage(const double amount);

    void reset();
};

#endif