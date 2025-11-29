#include "SMM.h"

SMM::SMM(std::string name, unsigned age,
         char gender, std::string date_of_birth,
         bool can_link_passkey_and_locker, PassKey *passkey,
         bool sub_is_taken, double money,
         double weight, unsigned height, unsigned work_experience, double salary,
         std::string phone_number, const std::string profile_name, const std::string username,
         const unsigned followers_count_tiktok, const unsigned followers_count_insta,
         const unsigned post_count, const unsigned likes_count,
         const unsigned repost_count, const unsigned stories_count, const std::string bio)
    : Employee(name, age, gender, date_of_birth, can_link_passkey_and_locker, passkey, sub_is_taken,
               money, weight, height, work_experience, salary, phone_number)
{
    insta = new Instagram(profile_name, username, followers_count_insta, post_count, stories_count, bio);
    tiktok = new TikTok(profile_name, username, followers_count_tiktok, post_count, likes_count, repost_count);
    total_followers = followers_count_insta + followers_count_tiktok;
}

void SMM::make_post()
{
    if (tiktok)
        tiktok->post_count++;
    if (insta)
        insta->post_count++;
}

void SMM::check_followers()
{
    total_followers = 0;
    if (tiktok)
        total_followers += tiktok->followers_count;
    if (insta)
        total_followers += insta->followers_count;
}

unsigned SMM::get_total_followers()
{
    return total_followers;
}

SMM::~SMM()
{
    delete tiktok;
    delete insta;
}
