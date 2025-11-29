#include "SM.h"

SM::SM(const std::string &profile_name, const std::string username, const unsigned followers_count, const std::string SM_name, const unsigned post_count)
    : profile_name(profile_name), username(username), followers_count(followers_count), SM_name(SM_name), post_count(post_count) {}

std::string SM::get_profile_name() const { return profile_name; }
std::string SM::get_username() const { return username; }
unsigned SM::get_followers_count() const { return followers_count; }
std::string SM::get_SM_name() const { return SM_name; }
