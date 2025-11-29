#ifndef GENERATORID_H
#define GENERATORID_H

#include <string>
#include <unordered_set>

constexpr int IDLenght = 5;
constexpr int maxAttemptsCount = 100000;

class GeneratorID
{
    std::unordered_set<std::string> listOfID{};
public:
    GeneratorID() = default;

    void generateID(std::string &id);

    bool checkIDExistance(const std::string &id) const;


};

#endif