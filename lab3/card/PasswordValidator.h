#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <string>
class PasswordValidator
{
    static bool validatePassword(std::string &password)
    {
        if (password.length() < 8)
            return false;

        bool hasDigit = false;
        bool hasLower = false;
        bool hasUpper = false;
        bool hasSpecial = false;

        for (char c : password)
        {
            if (std::isdigit(static_cast<unsigned char>(c)))
            {
                hasDigit = true;
            }
            else if (std::islower(static_cast<unsigned char>(c)))
            {
                hasLower = true;
            }
            else if (std::isupper(static_cast<unsigned char>(c)))
            {
                hasUpper = true;
            }
            else if (std::isprint(static_cast<unsigned char>(c)))
            {
                hasSpecial = true;
            }
        }

        return hasDigit && hasLower && hasUpper && hasSpecial;
    }
};

#endif