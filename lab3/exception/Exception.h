#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <exception>

class Exception : public std::exception
{
private:
    std::string message;

public:
    explicit Exception(const char *msg);

    explicit Exception(const Exception &other);

    const char *what() const noexcept override;
};

class ExceptionIncorrectAmount final : public Exception
{
public:
    explicit ExceptionIncorrectAmount(const char *msg);
};

class ExceptionFrozenAccount final : public Exception
{
public:
    explicit ExceptionFrozenAccount(const char *msg);
};

class ExceptionTimeError final : public Exception
{
public:
    explicit ExceptionTimeError(const char *msg);
};

class ExceptionIncorrectPrice final : public Exception
{
public:
    explicit ExceptionIncorrectPrice(const char *msg);
};

class ExceptionSafeBoxError final : public Exception
{
public:
    explicit ExceptionSafeBoxError(const char *msg);
};

class ExceptionIncorrectCreditPaymentAmount final : public Exception
{
public:
    explicit ExceptionIncorrectCreditPaymentAmount(const char *msg);
};

class ExceptionIncorrectDayCount final : public Exception
{
public:
    explicit ExceptionIncorrectDayCount(const char *msg);
};

class ExceptionPinError final : public Exception
{
public:
    explicit ExceptionPinError(const char *msg);
};

class ExceptionCardActivationError final : public Exception
{
public:
    explicit ExceptionCardActivationError(const char *msg);
};

class ExceptionCardFreezeError final : public Exception
{
public:
    explicit ExceptionCardFreezeError(const char *msg);
};

class ExceptionCardBlockError final : public Exception
{
public:
    explicit ExceptionCardBlockError(const char *msg);
};

class ExceptionATMError final : public Exception
{
public:
    explicit ExceptionATMError(const char *msg);
};

class ExceptionExpirationDateError final : public Exception
{
public:
    explicit ExceptionExpirationDateError(const char *msg);
};

class ExceptionIncorrectAccountType final : public Exception
{
public:
    explicit ExceptionIncorrectAccountType(const char *msg);
};

class ExceptionVerificationError final : public Exception
{
public:
    explicit ExceptionVerificationError(const char *msg);
};

class ExceptionInternetBankingError final : public Exception
{
public:
    explicit ExceptionInternetBankingError(const char *msg);
};

class ExceptionIncorrectAccount final : public Exception
{
public:
    explicit ExceptionIncorrectAccount(const char *msg);
};

#endif
