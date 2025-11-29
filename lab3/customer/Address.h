#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
private:
    std::string country;
    std::string region;
    std::string city;
    std::string street;
    std::string building;
    std::string apartment;
    std::string postalCode;

public:
    Address() = default;
    Address(const std::string &country,
            const std::string &region,
            const std::string &city,
            const std::string &street,
            const std::string &building,
            const std::string &apartment = "",
            const std::string &postal = "")
        : country(country), region(region), city(city),
          street(street), building(building), apartment(apartment), postalCode(postal) {}

    std::string getCountryCode() const { return country; }
    std::string getRegion() const { return region; }
    std::string getCity() const { return city; }
    std::string getFullStreetAddress() const
    {
        std::string addr = street;
        if (!building.empty())
            addr += ", " + building;
        if (!apartment.empty())
            addr += ", кв. " + apartment;
        return addr;
    }
    std::string getPostalCode() const { return postalCode; }
};

#endif