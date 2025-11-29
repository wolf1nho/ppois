#ifndef BANK_SAFE_BOX_H
#define BANK_SAFE_BOX_H

#include <ctime>
#include <string>

#include "../datamanager/DataManager.h"

class Customer;

enum class BoxStatus
{
    AVAILABLE,
    RENTED,
    BLOCKED
};

class BankSafeBox
{
    std::string id;
    Customer *tenant;
    BoxStatus status;
    double pricePerDay;
    std::string password;
    time_t startRentTime;

public:
    BankSafeBox(double price, DataManager *dataManager);
    bool isAvailable() const;
    bool isRented() const;
    BoxStatus getStatus() const;
    std::string getID() const;
    void rent(Customer &customer);
    void free();
    void block();
    void unblock();
    std::string getRenterName() const;
    double getPricePerDay() const;
    double getPriceForRent();
    int getRentDurationDays() const;
};

#endif
