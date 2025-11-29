#ifndef SM_H
#define SM_H
#include <string>

class SMM;

class SM
{
protected:
    friend class SMM;

    std::string profile_name;
    std::string username;
    unsigned followers_count;
    unsigned post_count;
    std::string SM_name;

public:
    SM(const std::string &profile_name, const std::string username, const unsigned followers_count, const std::string SM_name, const unsigned post_count);

    std::string get_profile_name() const;
    std::string get_username() const;
    unsigned get_followers_count() const;
    std::string get_SM_name() const;
};

#endif