#ifndef TIKTOK_H
#define TIKTOK_H
#include "sm.h"

#include <string>

class TikTok : public SM
{
    unsigned likes_count;
    unsigned repost_count;

public:
    TikTok(const std::string profile_name, const std::string username, const unsigned followers_count, const unsigned post_count, const unsigned likes_count, const unsigned repost_count);
};

#endif