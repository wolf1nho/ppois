#include "Trainer.h"
#include "SM/Instagram.h"
#include "SM/TikTok.h"

Trainer::Trainer(std::string name,
                 unsigned age,
                 char gender, 
                 std::string date_of_birth,
                 bool can_link_passkey_and_locker,
                 PassKey *passkey,
                 bool sub_is_taken,
                 double money,
                 double weight,
                 unsigned height, unsigned work_experience, double salary, std::string phone_number, const std::string profile_name, const std::string username,
                 const unsigned followers_count_tiktok, const unsigned followers_count_insta, const unsigned post_count, const unsigned likes_count,
                 const unsigned repost_count, const unsigned stories_count, const std::string bio, const bool on_duty)
    : Employee(name, age, gender, date_of_birth,
               can_link_passkey_and_locker, passkey, sub_is_taken,
               money, weight, height, work_experience, salary, phone_number),
      on_duty(on_duty)
{
    insta = new Instagram(profile_name, username, followers_count_insta, post_count, stories_count, bio);
    tiktok = new TikTok(profile_name, username, followers_count_tiktok, post_count, likes_count, repost_count);
}

bool Trainer::is_on_duty()
{
    return on_duty;
}