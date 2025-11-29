#include "Room.h"
#include "Exception/Exception.h"

Room::Room(const double area) : area(area), cleaned(true)
{
    if (area <= 0)
        throw ExceptionIncorrectArea("Площадь не может быть отрицательной либо быть равной 0");
}
Room::Room(const double area, const bool cleaned) : area(area), cleaned(cleaned)
{
    if (area <= 0)
        throw ExceptionIncorrectArea("Площадь не может быть отрицательной либо быть равной 0");
}

bool Room::is_cleaned()
{
    return cleaned;
}
