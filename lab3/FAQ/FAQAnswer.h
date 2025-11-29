#ifndef FAQANSWER_H
#define FAQANSWER_H

#include "FAQ.h"
#include "exception/Exception.h"

#include <string>

class FAQ;

class FAQAnswer
{
    friend class FAQ;

    std::string message;
    FAQ *question;

public:
    FAQAnswer(FAQ *question, const std::string &message);
    ~FAQAnswer();
    std::string getQuestion();
    std::string getMessage() { return message; }
};

#endif