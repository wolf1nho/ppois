#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Matrix
{
private:
    int m; // строки
    int n; // столбцы
    double **mat;

    bool IsLowerTriangular() const;

    bool IsUpperTriangular() const;
    bool DiagonalIsTheSame() const;
    bool IsSymmetric() const;
    bool IsDiag() const;
    bool IsEmpty() const;
    bool IsPositive() const;
    bool IsPositive(int m, int n) const;
    bool IsLess(int m, int n) const;
    Matrix Minor(int row, int col) const;

public:
    Matrix();
    Matrix(int m, int n);
    Matrix(const Matrix &other);
    ~Matrix();
    void Create();
    void Create(int m, int n);
    void CreateFromScratch();
    void SetElements();
    void Delete();
    void View() const;
    void ReadFromFile(string filename);
    void CheckType();
    void SetM(int m);
    void SetN(int n);
    bool IsSquare() const;
    Matrix &Transposition();
    Matrix Submatrix(int m, int n);
    Matrix &operator=(const Matrix &other);
    bool operator==(const Matrix &other) const;
    bool operator!=(const Matrix &other) const;
    Matrix operator+(const Matrix &other) const;
    Matrix &operator+=(const Matrix &other);
    Matrix operator-(const Matrix &other) const;
    Matrix &operator-=(const Matrix &other);
    Matrix operator+(double num) const;
    Matrix &operator+=(double num);
    Matrix operator-(double num) const;
    Matrix &operator-=(double num);
    Matrix operator*(double num) const;
    Matrix &operator*=(double num);
    Matrix operator/(double num) const;
    Matrix &operator/=(double num);
    Matrix operator*(const Matrix &other) const;
    Matrix operator^(int exp) const;
    Matrix &operator^=(int exp);
    double Determinant() const;
    double Norm() const; // норма фробениуса
    friend ostream &operator<<(ostream &os, const Matrix &output);
    friend istream &operator>>(istream &is, Matrix &input);
};

istream &operator>>(istream &is, Matrix &input);
ostream &operator<<(ostream &os, const Matrix &output);