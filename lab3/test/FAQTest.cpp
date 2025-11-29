#include <gtest/gtest.h>
#include "FAQ/FAQ.h"
#include "FAQ/FAQAnswer.h"
#include "exception/Exception.h"

#include <string>

TEST(FAQTest, CreateUnansweredFAQ) {
    FAQ faq("Вопрос");
    EXPECT_EQ(faq.getMessage(), "Вопрос");
    EXPECT_FALSE(faq.isAnswered());
    EXPECT_THROW(faq.getAnswer(), Exception);
}

TEST(FAQTest, CreateAnsweredFAQ) {
    FAQ faq("Вопрос");
    FAQAnswer ans(&faq, "Ответ");

    EXPECT_TRUE(faq.isAnswered());
    EXPECT_EQ(faq.getAnswer(), "Ответ");
    EXPECT_EQ(ans.getQuestion(), "Вопрос");
    EXPECT_EQ(ans.getMessage(), "Ответ");
}

TEST(FAQAnswerTest, ConstructWithNullQuestion_Throws) {
    EXPECT_THROW({
        FAQAnswer(nullptr, "Недопустимый ответ");
    }, Exception);
}

TEST(FAQTest, FAQBecomesUnansweredAfterAnswerDestruction) {
    FAQ faq("Вопрос");

    {
        FAQAnswer ans(&faq, "Ответ");
        EXPECT_TRUE(faq.isAnswered());
    } 

    EXPECT_FALSE(faq.isAnswered());
    EXPECT_THROW(faq.getAnswer(), Exception);
}

TEST(FAQTest, FAQDestructionBeforeAnswer) {
    FAQ* faq = new FAQ("Вопрос");
    FAQAnswer ans(faq, "Ответ");

    delete faq; 

    EXPECT_THROW(ans.getQuestion(), Exception);
    EXPECT_EQ(ans.getMessage(), "Ответ");
}

TEST(FAQTest, MultipleIndependentFAQs) {
    FAQ q1("Вопрос 1"), q2("Вопрос 2");

    EXPECT_FALSE(q1.isAnswered());
    EXPECT_FALSE(q2.isAnswered());

    FAQAnswer a1(&q1, "Ответ 1");
    EXPECT_TRUE(q1.isAnswered());
    EXPECT_FALSE(q2.isAnswered());

    EXPECT_EQ(q1.getAnswer(), "Ответ 1");
    EXPECT_THROW(q2.getAnswer(), Exception);
}