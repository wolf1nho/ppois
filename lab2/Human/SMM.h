#ifndef SMM_H
#define SMM_H
#include "Employee.h"
#include "SM/Instagram.h"
#include "SM/TikTok.h"

class TikTok;
class Instagram;

class SMM : public Employee
{
    TikTok *tiktok;
    Instagram *insta;
    unsigned total_followers;

public:
    SMM(std::string name,
        unsigned age,
        char gender,
        std::string date_of_birth,
        bool can_link_passkey_and_locker,
        PassKey *passkey,
        bool sub_is_taken,
        double money,
        double weight,
        unsigned height,
        unsigned work_experience,
        double salary,
        std::string phone_number,
        const std::string profile_name,
        const std::string username,
        const unsigned followers_count_tiktok,
        const unsigned followers_count_insta,
        const unsigned post_count,
        const unsigned likes_count,
        const unsigned repost_count,
        const unsigned stories_count,
        const std::string bio);
    ~SMM();
    void make_post();
    void check_followers();
    unsigned get_total_followers();
};

#endif