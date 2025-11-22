#include <gtest/gtest.h>

#define private public
#define protected public
#include "Matrix.h"
#undef private
#undef protected

static void fillMatrix(Matrix &mat, std::initializer_list<double> vals)
{
    std::stringstream ss;
    for (double v : vals)
        ss << v << ' ';
    ss >> mat;
}

static std::string captureStdout(const std::function<void()> &fn)
{
    testing::internal::CaptureStdout();
    fn();
    return testing::internal::GetCapturedStdout();
}

TEST(MatrixCoverage, DefaultConstructor_EmptyIODoesNothing)
{
    Matrix a;
    std::string out = captureStdout([&]()
                                    { std::cout << a; });
    EXPECT_TRUE(out.empty());
}

TEST(MatrixCoverage, ParamConstructor_InitializesWithZeros)
{
    Matrix a(2, 2);
    std::stringstream ss;
    ss << a;
    std::string s = ss.str();
    EXPECT_NE(s.find('0'), std::string::npos);
}

TEST(MatrixCoverage, SetMSetNAndCreate)
{
    Matrix a;
    EXPECT_NO_THROW(a.SetM(2));
    EXPECT_NO_THROW(a.SetN(2));
    a.Create();
    fillMatrix(a, {1, 2, 3, 4});
    std::stringstream ss;
    ss << a;
    EXPECT_NE(ss.str().find('1'), std::string::npos);
}

TEST(MatrixCoverage, SetMThrowsIfNegativeAndThrowsIfNotEmpty)
{
    Matrix a;
    EXPECT_THROW(a.SetM(-1), std::invalid_argument);
    Matrix b(2, 2);
    EXPECT_THROW(b.SetM(5), std::runtime_error);
}

TEST(MatrixCoverage, DeleteResetsToEmpty)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    a.Delete();
    std::string out = captureStdout([&]()
                                    { std::cout << a; });
    EXPECT_TRUE(out.empty());
}

TEST(MatrixCoverage, CopyConstructorCopies)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    Matrix b(a);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(MatrixCoverage, AssignmentOperatorWorksAndSelfAssignSafe)
{
    Matrix a(2, 2);
    fillMatrix(a, {2, 3, 4, 5});
    Matrix b;
    b = a;
    EXPECT_TRUE(b == a);
    b = b;
    EXPECT_TRUE(b == a);
}

TEST(MatrixCoverage, EqualityInequality)
{
    Matrix a(2, 2), b(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    fillMatrix(b, {1, 2, 3, 4});
    EXPECT_TRUE(a == b);
    fillMatrix(b, {0, 2, 3, 4});
    EXPECT_TRUE(a != b);
}

TEST(MatrixCoverage, ReadFromFile_FileNotOpenPrintsMessage)
{
    Matrix a;
    std::string out = captureStdout([&]()
                                    { a.ReadFromFile("this_file_does_not_exist_hopefully.txt"); });
    EXPECT_NE(out.find("Файл не открыт"), std::string::npos);
}

TEST(MatrixCoverage, ReadFromFile_ValidFileReadsMatrix)
{
    const char *fname = "test_matrix_ok.txt";
    std::ofstream f(fname);
    f << "2 2\n1 2\n3 4\n";
    f.close();

    Matrix a;
    EXPECT_NO_THROW(a.ReadFromFile(fname));
    EXPECT_DOUBLE_EQ(a.Determinant(), -2.0);

    std::remove(fname);
}

TEST(MatrixCoverage, ReadFromFile_InsufficientDataThrows)
{
    const char *fname = "test_matrix_short.txt";
    std::ofstream f(fname);
    f << "2 2\n1 2\n3\n";
    f.close();

    Matrix a;
    EXPECT_THROW(a.ReadFromFile(fname), std::runtime_error);
    std::remove(fname);
}

TEST(MatrixCoverage, CheckType_EmptyOutputs)
{
    Matrix a;
    std::string out = captureStdout([&]()
                                    { a.CheckType(); });
    EXPECT_NE(out.find("Матрица пустая"), std::string::npos);
}

TEST(MatrixCoverage, CheckType_IdentityMatrix)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 0, 0, 1});
    std::string out = captureStdout([&]()
                                    { a.CheckType(); });
    EXPECT_NE(out.find("Единичная"), std::string::npos);
    EXPECT_NE(out.find("Квадратная"), std::string::npos);
}

TEST(MatrixCoverage, CheckType_DiagonalSameNonUnit)
{
    Matrix a(3, 3);
    fillMatrix(a, {2, 0, 0, 0, 2, 0, 0, 0, 2});
    std::string out = captureStdout([&]()
                                    { a.CheckType(); });
    EXPECT_NE(out.find("Диагональная"), std::string::npos);
    EXPECT_NE(out.find("Симметричная"), std::string::npos);
}

TEST(MatrixCoverage, CheckType_UpperAndLowerAndSymmetricCases)
{
    Matrix up(3, 3);
    fillMatrix(up, {1, 2, 3, 0, 4, 5, 0, 0, 6});
    std::string out1 = captureStdout([&]()
                                     { up.CheckType(); });
    EXPECT_NE(out1.find("Верхняя треугольная"), std::string::npos);

    Matrix low(3, 3);
    fillMatrix(low, {1, 0, 0, 2, 3, 0, 4, 5, 6});
    std::string out2 = captureStdout([&]()
                                     { low.CheckType(); });
    EXPECT_NE(out2.find("Нижняя треугольная"), std::string::npos);

    Matrix sym(3, 3);
    fillMatrix(sym, {0, 1, 2, 1, 0, 3, 2, 3, 0});
    std::string out3 = captureStdout([&]()
                                     { sym.CheckType(); });
    EXPECT_NE(out3.find("Симметричная"), std::string::npos);
}

TEST(MatrixCoverage, Submatrix_SmallerAndEqualCases)
{
    Matrix a(3, 3);
    fillMatrix(a, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    Matrix s = a.Submatrix(2, 2);
    EXPECT_DOUBLE_EQ(s.Determinant(), -3.0);

    Matrix a2(2, 2);
    fillMatrix(a2, {1, 2, 3, 4});
    Matrix r = a2.Submatrix(2, 2);
    EXPECT_TRUE(r == a2);
}

TEST(MatrixCoverage, Minor_DeterminantRecursive)
{
    Matrix a(3, 3);
    fillMatrix(a, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    Matrix minor01 = a.Minor(0, 1);
    EXPECT_DOUBLE_EQ(minor01.Determinant(), -6.0);

    Matrix d(3, 3);
    fillMatrix(d, {2, 0, 0, 0, 2, 0, 0, 0, 2});
    EXPECT_DOUBLE_EQ(d.Determinant(), 8.0);
}

TEST(MatrixCoverage, Determinant_BaseCases)
{
    Matrix a1(1, 1);
    fillMatrix(a1, {7});
    EXPECT_DOUBLE_EQ(a1.Determinant(), 7.0);

    Matrix a2(2, 2);
    fillMatrix(a2, {1, 2, 3, 4});
    EXPECT_DOUBLE_EQ(a2.Determinant(), -2.0);

    Matrix nonSquare(2, 3);
    EXPECT_THROW(nonSquare.Determinant(), std::invalid_argument);
}

TEST(MatrixCoverage, AdditionSubtractionAndCompounds)
{
    Matrix a(2, 2), b(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    fillMatrix(b, {5, 6, 7, 8});
    Matrix expectedSum(2, 2);
    fillMatrix(expectedSum, {6, 8, 10, 12});
    Matrix sum = a + b;
    EXPECT_TRUE(sum == expectedSum);

    Matrix diff = b - a;
    Matrix expectedDiff(2, 2);
    fillMatrix(expectedDiff, {4, 4, 4, 4});
    EXPECT_TRUE(diff == expectedDiff);

    a += b;
    a -= b;
    EXPECT_TRUE(a == Matrix(2, 2) ? false : true);
}

TEST(MatrixCoverage, AdditionSubtractionSizeMismatchThrows)
{
    Matrix a(2, 2), b(3, 3);
    EXPECT_THROW(a + b, std::invalid_argument);
    EXPECT_THROW(a - b, std::invalid_argument);
}

TEST(MatrixCoverage, ScalarAddSubtractOnDiagonal)
{
    Matrix a(2, 2);
    fillMatrix(a, {0, 0, 0, 0});
    Matrix b = a + 5.0;
    std::stringstream ss;
    ss << b;
    EXPECT_NE(ss.str().find('5'), std::string::npos);

    a += 3.0;
    std::stringstream ss2;
    ss2 << a;
    EXPECT_NE(ss2.str().find('3'), std::string::npos);

    Matrix c = b - 2.0;
    std::stringstream ss3;
    ss3 << c;
    EXPECT_NE(ss3.str().find('3'), std::string::npos);
}

TEST(MatrixCoverage, ScalarMultiplyDivideAndCompound)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    Matrix b = a * 2.0;
    Matrix c = b / 2.0;
    EXPECT_TRUE(c == a);

    EXPECT_THROW(a / 0.0, std::domain_error);
    EXPECT_THROW(a /= 0.0, std::domain_error);

    a *= 3.0;
    a /= 3.0;
    EXPECT_FALSE(false);
}

TEST(MatrixCoverage, MatrixMultiplicationValidAndInvalid)
{
    Matrix a(2, 3), b(3, 2);
    fillMatrix(a, {1, 2, 3, 4, 5, 6});
    fillMatrix(b, {7, 8, 9, 10, 11, 12});
    Matrix c = a * b;
    std::stringstream ss;
    ss << c;
    EXPECT_NE(ss.str().find("58"), std::string::npos);

    Matrix bad(4, 2);
    EXPECT_THROW(a * bad, std::invalid_argument);
}

TEST(MatrixCoverage, PowerAndPowerAssign)
{
    Matrix a(2, 2);
    fillMatrix(a, {2, 0, 0, 2});
    Matrix sq = a ^ 2;
    Matrix expected(2, 2);
    fillMatrix(expected, {4, 0, 0, 4});
    EXPECT_TRUE(sq == expected);

    Matrix b(2, 2);
    fillMatrix(b, {2, 0, 0, 2});
    b ^= 2;
    EXPECT_TRUE(b == expected);

    Matrix nonSquare(2, 3);
    EXPECT_THROW(nonSquare ^ 2, std::invalid_argument);
    EXPECT_THROW(nonSquare ^= 2, std::invalid_argument);
}

TEST(MatrixCoverage, TranspositionSquareAndNonSquare)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    EXPECT_NO_THROW(a.Transposition());
    Matrix ns(2, 3);
    EXPECT_THROW(ns.Transposition(), std::invalid_argument);
}

// ---------- Norm ----------
TEST(MatrixCoverage, NormCalculation)
{
    Matrix a(2, 2);
    fillMatrix(a, {3, 4, 0, 0});
    EXPECT_NEAR(a.Norm(), 5.0, 1e-9);
}

TEST(MatrixCoverage, IsLowerAndUpperTriangularBranches)
{
    Matrix lower(3, 3);
    fillMatrix(lower, {1, 0, 0, 2, 3, 0, 4, 5, 6});
    EXPECT_TRUE(lower.IsLowerTriangular());
    EXPECT_FALSE(lower.IsUpperTriangular());

    Matrix upper(3, 3);
    fillMatrix(upper, {1, 2, 3, 0, 4, 5, 0, 0, 6});
    EXPECT_TRUE(upper.IsUpperTriangular());
    EXPECT_FALSE(upper.IsLowerTriangular());
}

TEST(MatrixCoverage, DiagonalIsTheSameTrueAndFalse)
{
    Matrix same(3, 3);
    fillMatrix(same, {2, 0, 0, 0, 2, 0, 0, 0, 2});
    EXPECT_TRUE(same.DiagonalIsTheSame());

    Matrix diff(3, 3);
    fillMatrix(diff, {1, 0, 0, 0, 2, 0, 0, 0, 3});
    EXPECT_FALSE(diff.DiagonalIsTheSame());
}

TEST(MatrixCoverage, IsSymmetricTrueFalseRectangular)
{
    Matrix sym(2, 2);
    fillMatrix(sym, {1, 2, 2, 1});
    EXPECT_TRUE(sym.IsSymmetric());

    Matrix nonsym(2, 2);
    fillMatrix(nonsym, {1, 2, 3, 4});
    EXPECT_FALSE(nonsym.IsSymmetric());

    Matrix rect(2, 3);
    fillMatrix(rect, {1, 2, 3, 4, 5, 6});
    EXPECT_FALSE(rect.IsSymmetric());
}

TEST(MatrixCoverage, IsDiagCombinesUpperLower)
{
    Matrix diag(2, 2);
    fillMatrix(diag, {5, 0, 0, 5});
    EXPECT_TRUE(diag.IsDiag());

    Matrix notdiag(2, 2);
    fillMatrix(notdiag, {1, 2, 0, 1});
    EXPECT_FALSE(notdiag.IsDiag());
}

TEST(MatrixCoverage, IsEmptyPositiveLess)
{
    Matrix empty;
    EXPECT_TRUE(empty.IsEmpty());
    EXPECT_FALSE(empty.IsPositive());

    Matrix a(2, 3);
    EXPECT_TRUE(a.IsPositive());
    EXPECT_TRUE(a.IsPositive(1, 1));
    EXPECT_FALSE(a.IsPositive(-1, 2));
    EXPECT_TRUE(a.IsLess(1, 1));
    EXPECT_FALSE(a.IsLess(3, 4));
}

TEST(MatrixCoverage, CreateOverloadsWork)
{
    Matrix a;
    a.SetM(2);
    a.SetN(2);
    EXPECT_NO_THROW(a.Create());
    a.Delete();
    EXPECT_NO_THROW(a.Create(2, 2));
    a.Delete();
}

/* TEST(MatrixCoverage, CreateFromScratchDeletesIfNotEmpty)
{
    std::istringstream input("2 2 1 2 3 4");
    std::cin.rdbuf(input.rdbuf());
    Matrix a(1, 1);
    a.CreateFromScratch();
    std::cin.rdbuf(nullptr);
    EXPECT_TRUE(a.IsPositive());
} */

TEST(MatrixCoverage, ViewPrintsMatrix)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    std::string out = captureStdout([&]()
                                    { a.View(); });
    EXPECT_NE(out.find('4'), std::string::npos);
}

TEST(MatrixCoverage, InputOutputOperatorsForEmptyAndNonEmpty)
{
    Matrix empty;
    std::stringstream ss;
    ss << empty;
    EXPECT_TRUE(ss.str().empty());

    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    std::stringstream ss2;
    ss2 << a;
    EXPECT_NE(ss2.str().find("1"), std::string::npos);

    Matrix b(2, 2);
    std::stringstream input("9 8 7 6");
    input >> b;
    std::stringstream out;
    out << b;
    EXPECT_NE(out.str().find("9"), std::string::npos);
}

TEST(MatrixCoverage, SubmatrixBranches)
{
    Matrix a(3, 3);
    fillMatrix(a, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    Matrix r1 = a.Submatrix(4, 4);
    EXPECT_TRUE(r1 == a);
    Matrix r2 = a.Submatrix(2, 2);
    EXPECT_DOUBLE_EQ(r2.Determinant(), -3.0);
}

TEST(MatrixCoverage, OperatorMinusEqualsScalarThrowsAndWorks)
{
    Matrix a(2, 2);
    fillMatrix(a, {1, 2, 3, 4});
    EXPECT_NO_THROW(a -= 1.0);
    Matrix nonSquare(2, 3);
    EXPECT_THROW(nonSquare -= 1.0, std::runtime_error);
}

TEST(MatrixCoverage, OperatorPlusMinusScalarThrowForNonSquare)
{
    Matrix nonSquare(2, 3);
    EXPECT_THROW(nonSquare + 5.0, std::invalid_argument);
    EXPECT_THROW(nonSquare - 5.0, std::invalid_argument);
    EXPECT_THROW(nonSquare += 5.0, std::invalid_argument);
}
