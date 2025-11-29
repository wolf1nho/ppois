#include "BankSafeBox.h"
#include "../exception/Exception.h"
#include "../getter/TimeGetter.h"
#include "../customer/Customer.h"

BankSafeBox::BankSafeBox(double price, DataManager *dataManager)
    : pricePerDay(price), status(BoxStatus::AVAILABLE), startRentTime(0), tenant(nullptr)
{
    if (price < 0)
        throw ExceptionIncorrectPrice("Цена аренды не может быть отрицательной");
    dataManager->generatorID.generateID(id);
}

bool BankSafeBox::isAvailable() const
{
    return status == BoxStatus::AVAILABLE;
}

bool BankSafeBox::isRented() const
{
    return status == BoxStatus::RENTED;
}

BoxStatus BankSafeBox::getStatus() const
{
    return status;
}

std::string BankSafeBox::getID() const
{
    return id;
}

// Аренда ячейки
void BankSafeBox::rent(Customer &customer)
{
    if (status != BoxStatus::AVAILABLE)
        throw ExceptionSafeBoxError("Ячейка недоступна для аренды");

    tenant = &customer;
    status = BoxStatus::RENTED;
    startRentTime = TimeGetter::getTodayMidnight();
}

// Освобождение ячейки
void BankSafeBox::free()
{
    if (status != BoxStatus::RENTED)
        throw ExceptionSafeBoxError("Нельзя освободить неарендованную ячейку");

    tenant = nullptr;
    startRentTime = 0;
    status = BoxStatus::AVAILABLE;
}

// Заблокировать ячейку
void BankSafeBox::block()
{
    status = BoxStatus::BLOCKED;
}

// Разблокировать
void BankSafeBox::unblock()
{
    if (status != BoxStatus::BLOCKED)
        throw ExceptionSafeBoxError("Ячейка не заблокирована");
    if (!tenant)
        status = BoxStatus::AVAILABLE;
    else
        status = BoxStatus::RENTED;
}

// Получить текущего арендатора
std::string BankSafeBox::getRenterName() const
{
    if (tenant)
        return tenant->getFullName();
    else
        throw ExceptionSafeBoxError("");
}

// Сколько стоит аренда
double BankSafeBox::getPricePerDay() const
{
    return pricePerDay;
}

double BankSafeBox::getPriceForRent()
{
    return pricePerDay * getRentDurationDays();
}

// Сколько времени арендуется (в днях)
int BankSafeBox::getRentDurationDays() const
{
    if (status != BoxStatus::RENTED)
        return 0;

    time_t now = TimeGetter::getNextDayMidnight();
    return TimeGetter::getDiffInSeconds(startRentTime, now) / (60 * 60 * 24);
};