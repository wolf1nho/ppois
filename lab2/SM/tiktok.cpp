#include "tiktok.h"

TikTok::TikTok(const std::string profile_name, const std::string username, const unsigned followers_count, const unsigned post_count, const unsigned likes_count, const unsigned repost_count)
    : SM(profile_name, username, followers_count, "TikTok", post_count), likes_count(likes_count), repost_count(repost_count) {}