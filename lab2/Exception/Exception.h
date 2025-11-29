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

class ExceptionNotEnoughMoney final : public Exception
{
public:
    explicit ExceptionNotEnoughMoney(const char *msg);
};

class ExceptionIncorrectOpenAndCloseTime final : public Exception
{
public:
    explicit ExceptionIncorrectOpenAndCloseTime(const char *msg);
};

class ExceptionIncorrectTimeValue final : public Exception
{
public:
    explicit ExceptionIncorrectTimeValue(const char *msg);
};

class ExceptionIncorrectPackaging : public Exception
{
public:
    explicit ExceptionIncorrectPackaging(const char *msg);
};

class ExceptionIncorrectArea final : public Exception
{
public:
    explicit ExceptionIncorrectArea(const char *msg);
};

class ExceptionIncorrectHeight final : public Exception
{
public:
    explicit ExceptionIncorrectHeight(const char *msg);
};

class ExceptionIncorrectWeight final : public Exception
{
public:
    explicit ExceptionIncorrectWeight(const char *msg);
};

class ExceptionIncorrectGender final : public Exception
{
public:
    explicit ExceptionIncorrectGender(const char *msg);
};

class ExceptionIncorrectVolume final : public Exception
{
public:
    explicit ExceptionIncorrectVolume(const char *msg);
};

class ExceptionIncorrectMoney final : public Exception
{
public:
    explicit ExceptionIncorrectMoney(const char *msg);
};

class ExceptionIncorrectNumOfSessions final : public Exception
{
public:
    explicit ExceptionIncorrectNumOfSessions(const char *msg);
};

class ExceptionSubscriptionError final : public Exception
{
public:
    explicit ExceptionSubscriptionError(const char *msg);
};

class ExceptionPasskeyError final : public Exception
{
public:
    explicit ExceptionPasskeyError(const char *msg);
};

class ExceptionPersonalTrainerError final : public Exception
{
public:
    explicit ExceptionPersonalTrainerError(const char *msg);
};

class ExceptionHumidityError final : public Exception
{
public:
    explicit ExceptionHumidityError(const char *msg);
};

class ExceptionIncorrectPrecision final : public Exception
{
public:
    explicit ExceptionIncorrectPrecision(const char *msg);
};

class ExceptionIncorrectPrice final : public Exception
{
public:
    explicit ExceptionIncorrectPrice(const char *msg);
};

#endif
