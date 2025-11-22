#include <gtest/gtest.h>
#include "../Vector.h"
// #include <sstream>

TEST(VectorTest, DefaultConstructor)
{
    Vector v;
    EXPECT_DOUBLE_EQ(v.GetX(), 0);
    EXPECT_DOUBLE_EQ(v.GetY(), 0);
    EXPECT_DOUBLE_EQ(v.GetZ(), 0);
}

TEST(VectorTest, ParameterConstructor)
{
    Vector v(3.5, -2.1, 4.0);
    EXPECT_DOUBLE_EQ(v.GetX(), 3.5);
    EXPECT_DOUBLE_EQ(v.GetY(), -2.1);
    EXPECT_DOUBLE_EQ(v.GetZ(), 4.0);
}

TEST(VectorTest, CopyConstructor)
{
    Vector a(1, 2, 3);
    Vector b(a);
    EXPECT_TRUE(a == b);
}

TEST(VectorTest, AssignmentOperator)
{
    Vector a(1, 2, 3);
    Vector b;

    b = a; // проверяем оператор присваивания

    // Проверяем, что координаты совпадают
    EXPECT_DOUBLE_EQ(b.GetX(), 1);
    EXPECT_DOUBLE_EQ(b.GetY(), 2);
    EXPECT_DOUBLE_EQ(b.GetZ(), 3);

    // Проверяем самоприсваивание
    a = a;
    EXPECT_DOUBLE_EQ(a.GetX(), 1);
    EXPECT_DOUBLE_EQ(a.GetY(), 2);
    EXPECT_DOUBLE_EQ(a.GetZ(), 3);

    // Проверяем, что изменения в b не влияют на a
    b.SetX(10);
    EXPECT_DOUBLE_EQ(a.GetX(), 1);
    EXPECT_DOUBLE_EQ(b.GetX(), 10);
}

TEST(VectorTest, Setters)
{
    Vector v; // допустим, конструктор по умолчанию

    // Проверяем SetX
    v.SetX(10.5);
    EXPECT_DOUBLE_EQ(v.GetX(), 10.5);

    // Проверяем SetY
    v.SetY(-3.2);
    EXPECT_DOUBLE_EQ(v.GetY(), -3.2);

    // Проверяем SetZ
    v.SetZ(7.7);
    EXPECT_DOUBLE_EQ(v.GetZ(), 7.7);

    // Проверяем SetCoordinates (все сразу)
    v.Set(1.1, 2.2, 3.3);
    EXPECT_DOUBLE_EQ(v.GetX(), 1.1);
    EXPECT_DOUBLE_EQ(v.GetY(), 2.2);
    EXPECT_DOUBLE_EQ(v.GetZ(), 3.3);

    // Проверка, что отдельные сеттеры после SetCoordinates тоже работают
    v.SetX(4.4);
    v.SetY(5.5);
    v.SetZ(6.6);
    EXPECT_DOUBLE_EQ(v.GetX(), 4.4);
    EXPECT_DOUBLE_EQ(v.GetY(), 5.5);
    EXPECT_DOUBLE_EQ(v.GetZ(), 6.6);
}

TEST(VectorTest, EqualityOperators)
{
    Vector a(1, 2, 3);
    Vector b(1, 2, 3);
    Vector c(0, 0, 0);
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a != c);
}

TEST(VectorTest, ArithmeticAddition)
{
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    Vector sum = a + b;
    EXPECT_TRUE(sum == Vector(5, 7, 9));

    a += b;
    EXPECT_TRUE(a == Vector(5, 7, 9));
}

TEST(VectorTest, ArithmeticSubtraction)
{
    Vector a(4, 5, 6);
    Vector b(1, 2, 3);
    Vector diff = a - b;
    EXPECT_TRUE(diff == Vector(3, 3, 3));

    a -= b;
    EXPECT_TRUE(a == Vector(3, 3, 3));
}

TEST(VectorTest, ScalarMultiplication)
{
    Vector a(1, -2, 3);
    Vector b = a * 2;
    Vector c = 2 * a;
    EXPECT_TRUE(b == Vector(2, -4, 6));
    EXPECT_TRUE(b == c);
    a *= -1;
    EXPECT_TRUE(a == Vector(-1, 2, -3));
}

TEST(VectorTest, ScalarDivision)
{
    Vector a(4, 8, 12);
    Vector b = a / 4;
    EXPECT_TRUE(b == Vector(1, 2, 3));

    a /= 2;
    EXPECT_TRUE(a == Vector(2, 4, 6));
}

TEST(VectorTest, DivisionByZeroThrows)
{
    Vector a(1, 2, 3);
    EXPECT_THROW(a / 0, std::domain_error);
    EXPECT_THROW(a /= 0, std::domain_error);
}

TEST(VectorTest, DotProduct)
{
    Vector a(1, 2, 3);
    Vector b(4, -5, 6);
    EXPECT_DOUBLE_EQ(a * b, 12);
}

TEST(VectorTest, CrossProduct)
{
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    Vector c = a % b;
    EXPECT_TRUE(c == Vector(-3, 6, -3));
}

TEST(VectorTest, AngleOperator)
{
    Vector a(1, 0, 0);
    Vector b(0, 1, 0);
    double cosValue = a ^ b;
    EXPECT_NEAR(cosValue, 0.0, 1e-9);
}

TEST(VectorTest, AngleWithZeroVectorThrows)
{
    Vector a(0, 0, 0);
    Vector b(1, 0, 0);
    EXPECT_THROW(a ^ b, std::domain_error);
}

TEST(VectorTest, IncrementDecrement)
{
    Vector a(1, 2, 3);
    ++a;
    EXPECT_TRUE(a == Vector(2, 3, 4));

    a--;
    EXPECT_TRUE(a == Vector(1, 2, 3));

    Vector b = a++;
    EXPECT_TRUE(b == Vector(1, 2, 3));
    EXPECT_TRUE(a == Vector(2, 3, 4));

    Vector c = a--;
    EXPECT_TRUE(c == Vector(2, 3, 4));
    EXPECT_TRUE(a == Vector(1, 2, 3));
}

TEST(VectorTest, ComparisonOperators)
{
    Vector a(1, 0, 0);
    Vector b(2, 0, 0);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b >= a);
}

TEST(VectorTest, StreamOperators)
{
    Vector v(1.1, 2.2, 3.3);
    std::ostringstream os;
    os << v;
    EXPECT_EQ(os.str(), "1.1 2.2 3.3");

    std::istringstream is("4.4 5.5 6.6");
    is >> v;
    EXPECT_TRUE(v == Vector(4.4, 5.5, 6.6));
}

TEST(VectorTest, LengthComputation)
{
    Vector v(3, 4, 0);
    EXPECT_DOUBLE_EQ(v.GetLength(), 5.0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
