#include "FAQ.h"
#include "exception/Exception.h"

FAQ::FAQ(const std::string &message)
    : message(message), answered(false), answer(nullptr)
{
}

FAQ::~FAQ()
{
    if (answer)
        answer->question = nullptr;
}

std::string FAQ::getAnswer()
{
    if (answer)
        return answer->message;
    else
        throw Exception("");
}