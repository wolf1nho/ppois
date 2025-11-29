#include "FAQAnswer.h"
#include "exception/Exception.h"

FAQAnswer::FAQAnswer(FAQ *question, const std::string &message)
    : message(message), question(question)
{
    if (!question)
        throw Exception("");
    question->answer = this;
    question->answered = true;
}

FAQAnswer::~FAQAnswer()
{
    if (question)
    {
        question->answered = false;
        question->answer = nullptr;
    }
}

std::string FAQAnswer::getQuestion()
{
    if (question)
        return question->message;
    else
        throw Exception("");
}
