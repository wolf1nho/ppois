#include "VerificationService.h"
#include <regex>
#include <iostream>

bool VerificationService::verifyCustomer(Customer &customer)
{
    bool passportOK = validatePassport(customer);
    bool emailOK = validateEmail(customer);
    bool phoneOK = validatePnoneNumber(customer);

    if (passportOK && emailOK && phoneOK)
    {
        customer.setVerified(true);
        return true;
    }
    else
    {
        customer.setVerified(false);
        return false;
    }
}

bool VerificationService::validatePassport(Customer &customer)
{
    std::regex passportPattern("[A-Z]{2}[0-9]{7}");
    return std::regex_match(customer.passportNumber, passportPattern);
}

bool VerificationService::validateEmail(Customer &customer)
{
    std::regex emailPattern("^[a-zA-Z0-9]([a-zA-Z0-9\\.]{0,28}[a-zA-Z0-9])?@gmail\\.com$");
    return std::regex_match(customer.email, emailPattern);
}

bool VerificationService::validatePnoneNumber(Customer &customer)
{
    std::regex PhonePattern("^(\\+375|80)\\s?\\(?(25|29|33|44|17)\\)?\\s?\\d{3}\\s?\\-?\\d{2}\\s?\\-?\\d{2}$");
    return std::regex_match(customer.phoneNumber, PhonePattern);
}
