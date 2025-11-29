#include "Instagram.h"

Instagram::Instagram(const std::string profile_name, const std::string username, const unsigned followers_count, const unsigned post_count, const unsigned stories_count, const std::string bio)
    : SM(profile_name, username, followers_count, "Instagram", post_count), stories_count(stories_count), bio(bio) {}
