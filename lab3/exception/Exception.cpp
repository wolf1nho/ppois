#include "Exception.h"
using namespace std;

Exception::Exception(const char *msg) : message(msg)
{
}

Exception::Exception(const Exception &other) : message(other.message)
{
}

const char *Exception::what() const noexcept
{
    return this->message.c_str();
}

ExceptionIncorrectAmount::ExceptionIncorrectAmount(const char *msg) : Exception(msg)
{
}

ExceptionFrozenAccount::ExceptionFrozenAccount(const char *msg) : Exception(msg)
{
}

ExceptionTimeError::ExceptionTimeError(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectPrice::ExceptionIncorrectPrice(const char *msg) : Exception(msg)
{
}

ExceptionSafeBoxError::ExceptionSafeBoxError(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectCreditPaymentAmount::ExceptionIncorrectCreditPaymentAmount(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectDayCount::ExceptionIncorrectDayCount(const char *msg) : Exception(msg)
{
}

ExceptionPinError::ExceptionPinError(const char *msg) : Exception(msg)
{
}

ExceptionCardActivationError::ExceptionCardActivationError(const char *msg) : Exception(msg)
{
}

ExceptionCardFreezeError::ExceptionCardFreezeError(const char *msg) : Exception(msg)
{
}

ExceptionCardBlockError::ExceptionCardBlockError(const char *msg) : Exception(msg)
{
}

ExceptionATMError::ExceptionATMError(const char *msg) : Exception(msg)
{
}

ExceptionExpirationDateError::ExceptionExpirationDateError(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectAccountType::ExceptionIncorrectAccountType(const char *msg) : Exception(msg)
{
}

ExceptionVerificationError::ExceptionVerificationError(const char *msg) : Exception(msg)
{
}

ExceptionInternetBankingError::ExceptionInternetBankingError(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectAccount::ExceptionIncorrectAccount(const char *msg) : Exception(msg)
{
}