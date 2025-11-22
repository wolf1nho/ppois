#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector
{
private:
    double x;
    double y;
    double z;

public:
    Vector();
    Vector(double x, double y, double z);
    Vector(const Vector &other);
    double GetX() const;
    double GetY() const;
    double GetZ() const;
    void Set(double x, double y, double z);
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    double GetLength() const;
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;
    bool operator>(Vector &other) const;
    bool operator<(Vector &other) const;
    bool operator<=(Vector &other) const;
    bool operator>=(Vector &other) const;
    Vector &operator=(const Vector &other);
    Vector &operator+=(const Vector &other);
    Vector &operator-=(const Vector &other);
    Vector &operator*=(double num);
    Vector &operator/=(double num);
    Vector operator+(const Vector &other);
    Vector operator-(const Vector &other);
    Vector operator*(double num);
    Vector operator/(double num);
    double operator*(const Vector &other); // скалярное произведение
    Vector operator%(const Vector &other); // векторное произведение
    double operator^(const Vector &other);
    Vector &operator++();
    Vector &operator--();
    Vector operator++(int);
    Vector operator--(int);
    friend std::ostream &operator<<(std::ostream &os, const Vector &output);
    friend std::istream &operator>>(std::istream &is, Vector &input);
    friend Vector operator*(double num, Vector &vector);
};

std::ostream &operator<<(std::ostream &os, const Vector &output);
std::istream &operator>>(std::istream &is, Vector &input);
Vector operator*(double num, Vector &vector);

#endif