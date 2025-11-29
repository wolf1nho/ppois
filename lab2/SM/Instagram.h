#ifndef INSTAGRAM_H
#define INSTAGRAM_H
#include "SM.h"

#include <string>

class Instagram : public SM
{
    unsigned stories_count;
    std::string bio;

public:
    Instagram(const std::string profile_name, const std::string username, const unsigned followers_count, const unsigned post_count, const unsigned stories_count, const std::string bio);
};

#endif