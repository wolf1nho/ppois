#include "exception.h"
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

ExceptionNotEnoughMoney::ExceptionNotEnoughMoney(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectOpenAndCloseTime::ExceptionIncorrectOpenAndCloseTime(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectTimeValue::ExceptionIncorrectTimeValue(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectPackaging::ExceptionIncorrectPackaging(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectArea::ExceptionIncorrectArea(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectHeight::ExceptionIncorrectHeight(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectWeight::ExceptionIncorrectWeight(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectGender::ExceptionIncorrectGender(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectVolume::ExceptionIncorrectVolume(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectMoney::ExceptionIncorrectMoney(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectNumOfSessions::ExceptionIncorrectNumOfSessions(const char *msg) : Exception(msg)
{
}

ExceptionSubscriptionError::ExceptionSubscriptionError(const char *msg) : Exception(msg)
{
}

ExceptionPasskeyError::ExceptionPasskeyError(const char *msg) : Exception(msg)
{
}

ExceptionPersonalTrainerError::ExceptionPersonalTrainerError(const char *msg) : Exception(msg)
{
}

ExceptionHumidityError::ExceptionHumidityError(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectPrecision::ExceptionIncorrectPrecision(const char *msg) : Exception(msg)
{
}

ExceptionIncorrectPrice::ExceptionIncorrectPrice(const char *msg) : Exception(msg)
{
}