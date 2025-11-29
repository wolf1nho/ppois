#include <gtest/gtest.h>
#include "../Human/human.h"
#include "../Human/receptionist.h"

// --- Тест корректного конструктора ---
TEST(HumanTest, Constructor_ValidInput_Success)
{
    Human h("John", 30, 'm', "1995-01-01", true, nullptr, true, 100.0, 80.0, 180);

    EXPECT_EQ(h.get_name(), "John");
    EXPECT_EQ(h.get_age(), 30);
    EXPECT_EQ(h.get_gender_char(), 'm');
    EXPECT_EQ(h.get_gender(), "male");
    EXPECT_EQ(h.get_date_of_birth(), "1995-01-01");
}

// --- Неверный рост ---
TEST(HumanTest, Constructor_ThrowsOnLowHeight)
{
    EXPECT_THROW({ Human h("Bob", 25, 'm', "2000-01-01", true, nullptr, false, 100.0, 70.0, 140); }, ExceptionIncorrectHeight);
}

// --- Неверный вес ---
TEST(HumanTest, Constructor_ThrowsOnZeroWeight)
{

    EXPECT_THROW({ Human h("Bob", 25, 'm', "2000-01-01", true, nullptr, false, 100.0, 0.0, 170); }, ExceptionIncorrectWeight);
}

// --- Неверные деньги ---
TEST(HumanTest, Constructor_ThrowsOnNegativeMoney)
{
    EXPECT_THROW(Human h("Bob", 25, 'm', "2000-01-01", true, nullptr, false, -10.0, 70.0, 180), ExceptionIncorrectMoney);
}

// --- Неверный пол ---
TEST(HumanTest, Constructor_ThrowsOnIncorrectGender)
{
    EXPECT_THROW(Human h("Alex", 20, 'x', "2005-01-01", true, nullptr, false, 100.0, 70.0, 180), ExceptionIncorrectGender);
}

// --- Сеттеры / геттеры ---
TEST(HumanTest, SettersAndGetters_WorkCorrectly)
{
    Human h("Jane", 28, 'f', "1997-02-02", true, nullptr, false, 50.0, 60.0, 165);

    EXPECT_EQ(h.get_gender(), "female");

    h.set_name("Alice");
    h.set_age(29);
    h.set_gender('m');
    h.set_date_of_birth("1996-03-03");
    h.set_weight(70.5);
    h.set_height(175);

    EXPECT_EQ(h.get_name(), "Alice");
    EXPECT_EQ(h.get_age(), 29);
    EXPECT_EQ(h.get_gender(), "male");
    EXPECT_EQ(h.get_date_of_birth(), "1996-03-03");
}

// --- Проверка пола ---
TEST(HumanTest, GenderCheckFunctions)
{
    Human h1("Mark", 25, 'm', "2000-05-05", true, nullptr, false, 100.0, 70.0, 180);
    Human h2("Lily", 25, 'f', "2000-05-05", true, nullptr, false, 100.0, 70.0, 180);

    EXPECT_TRUE(h1.is_male());
    EXPECT_FALSE(h1.is_female());
    EXPECT_FALSE(h2.is_male());
    EXPECT_TRUE(h2.is_female());
}

TEST(HumanTest, GetMoney)
{
    Human h("Mark", 25, 'm', "2000-05-05", true, nullptr, false, 100.0, 70.0, 180);
    EXPECT_DOUBLE_EQ(h.get_money(), 100);
}

TEST(HumanSubscriptionTest, GetSubscriptionValues_Normal)
{
    Fitness fitness(5, 10, 10, 10, 10, 10, 10, 10);
    Receptionist r("John", 30, 'm', "1995-01-01", true, nullptr, false,
                   400, 80.0, 180, 5, 3000, "+222222",
                   nullptr, nullptr, nullptr);
    Human h("John", 30, 'm', "1995-01-01", true, nullptr, false, 100.0, 80.0, 180);
    r.create_client_sub(h, 10, 90, &fitness, nullptr, nullptr, nullptr, nullptr);

    EXPECT_EQ(h.get_remaining_sessions(), "10");
    EXPECT_EQ(h.get_remaining_days(), "90");
    EXPECT_EQ(h.get_validality_period(), "90");
    EXPECT_EQ(h.get_initial_num_of_sessions(), "10");
}

// --- Есть абонемент: безлимитные тренировки ---
TEST(HumanSubscriptionTest, GetSubscriptionValues_Unlimited)
{
    Fitness fitness(5, 10, 10, 10, 10, 10, 10, 10);
    Receptionist r("John", 30, 'm', "1995-01-01", true, nullptr, false,
                   400, 80.0, 180, 5, 3000, "+222222",
                   nullptr, nullptr, nullptr);
    Human h("John", 30, 'm', "1995-01-01", true, nullptr, false, 100.0, 80.0, 180);
    r.create_client_sub(h, -1, 120, &fitness, nullptr, nullptr, nullptr, nullptr);

    EXPECT_EQ(h.get_remaining_sessions(), "unlimited");
    EXPECT_EQ(h.get_initial_num_of_sessions(), "unlimited");
    EXPECT_EQ(h.get_remaining_days(), "120");
    EXPECT_EQ(h.get_validality_period(), "120");
}

TEST(HumanSubscriptionTest, GetSubscriptionValues_NoSubscription_Throws)
{
    Human h("Bob", 25, 'm', "2000-01-01", true, nullptr, false, 50.0, 70.0, 175);

    EXPECT_THROW(h.get_remaining_sessions(), ExceptionSubscriptionError);
    EXPECT_THROW(h.get_remaining_days(), ExceptionSubscriptionError);
    EXPECT_THROW(h.get_validality_period(), ExceptionSubscriptionError);
    EXPECT_THROW(h.get_initial_num_of_sessions(), ExceptionSubscriptionError);
}