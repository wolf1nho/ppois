#ifndef TRAINER_H
#define TRAINER_H
#include <string>
#include "employee.h"

class TikTok;
class Instagram;
class Administrator;

class Trainer : public Employee
{
protected:
    friend class Administrator;

    TikTok *tiktok;
    Instagram *insta;
    bool on_duty;

public:
    Trainer(std::string name,
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
            const std::string bio,
            const bool on_duty);
    bool is_on_duty();
};

#endif