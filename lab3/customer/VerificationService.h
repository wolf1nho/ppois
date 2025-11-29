#ifndef CUSTOMER_VERIFICATION_SERVICE_H
#define CUSTOMER_VERIFICATION_SERVICE_H
#include "Customer.h"

class VerificationService
{
public:
    static bool verifyCustomer(Customer &customer);
    static bool validatePassport(Customer &customer);
    static bool validateEmail(Customer &customer);
    static bool validatePnoneNumber(Customer &customer);
};

#endif
