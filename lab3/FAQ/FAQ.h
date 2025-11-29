#ifndef FAQ_H
#define FAQ_H

#include "FAQAnswer.h"

#include <string>

class FAQAnswer;

class FAQ
{
    friend class FAQAnswer;

    std::string message;
    bool answered;
    FAQAnswer *answer;

public:
    FAQ(const std::string &message);
    ~FAQ();
    std::string getAnswer();
    std::string getMessage() { return message; }
    bool isAnswered() { return answered; }
};

#endif