#include <gtest/gtest.h>
#include "Room/Scales.h"
#include "Exception/Exception.h"
#include <cmath>

TEST(ScalesTest, ValidPrecisionInitialization)
{
    EXPECT_NO_THROW({
        Scales scales("Tanita", "T-200", 200.0, 0.01,
                      true, true, true, true, false, 30.5);
    });
}

TEST(ScalesTest, InvalidPrecisionThrows)
{
    EXPECT_THROW({ Scales scales("Philips", "P-100", 180.0, 0.03,
                                 true, false, false, true, false, 25.0); }, ExceptionIncorrectPrecision);
}

TEST(ScalesTest, GetWeight)
{
    Scales scales("Beurer", "B-300", 150.0, 0.1,
                  true, true, true, true, true, 35.0);
    Human h("Mark", 25, 'm', "2000-05-05", true, nullptr, false, 100.0, 72.5, 180);

    EXPECT_DOUBLE_EQ(scales.get_weight(h), 72.5);
}

TEST(ScalesTest, PrecisionOneIsValid)
{
    EXPECT_NO_THROW({
        Scales scales("Omron", "O-50", 200.0, 1.0,
                      false, false, false, false, false, 40.0);
    });
}
