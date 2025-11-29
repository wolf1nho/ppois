#include "GeneratorID.h"
#include <random>
#include <string>

#include "exception/Exception.h"

bool GeneratorID::checkIDExistance(const std::string &id) const
{
    return listOfID.count(id) > 0;
}

void GeneratorID::generateID(std::string &id)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0, 9);

    int count_of_attempts = 0;

    while ((id.length() < IDLenght || checkIDExistance(id)) && count_of_attempts < maxAttemptsCount)
    {
        id = "";
        for (int i = 0; i < IDLenght; i++)
        {
            id += std::to_string(dis(gen));
        }
        count_of_attempts++;
    }
    if (count_of_attempts >= maxAttemptsCount)
    {
        throw Exception("");
    }
    listOfID.emplace(id);
}