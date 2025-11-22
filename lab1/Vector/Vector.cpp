#include "Vector.h"

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Vector &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

double Vector::GetX() const
{
    return x;
}
double Vector::GetY() const
{
    return y;
}
double Vector::GetZ() const
{
    return z;
}
void Vector::Set(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
void Vector::SetX(double x)
{
    this->x = x;
}
void Vector::SetY(double y)
{
    this->y = y;
}
void Vector::SetZ(double z)
{
    this->z = z;
}

double Vector::GetLength() const
{
    return sqrt(x * x + y * y + z * z);
}

bool Vector::operator==(const Vector &other) const
{
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector::operator!=(const Vector &other) const
{
    return this->x != other.x || this->y != other.y || this->z != other.z;
}

bool Vector::operator>(Vector &other) const
{
    return this->GetLength() > other.GetLength();
}

bool Vector::operator<(Vector &other) const
{
    return this->GetLength() < other.GetLength();
}

bool Vector::operator<=(Vector &other) const
{
    return this->GetLength() <= other.GetLength();
}

bool Vector::operator>=(Vector &other) const
{
    return this->GetLength() >= other.GetLength();
}

Vector &Vector::operator=(const Vector &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}

Vector &Vector::operator+=(const Vector &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

Vector &Vector::operator-=(const Vector &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

Vector Vector::operator/(double num)
{
    if (num == 0)
        throw std::domain_error("Деление на ноль невозможно!!!\n");
    return Vector(this->x / num, this->y / num, this->z / num);
}

Vector &Vector::operator/=(double num)
{
    if (num == 0)
        throw std::domain_error("Деление на ноль невозможно!!!\n");
    this->x /= num;
    this->y /= num;
    this->z /= num;
    return *this;
}

Vector Vector::operator+(const Vector &other)
{
    return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector Vector::operator-(const Vector &other)
{
    return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector &Vector::operator*=(double num)
{
    this->x *= num;
    this->y *= num;
    this->z *= num;
    return *this;
}

double Vector::operator*(const Vector &other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector Vector::operator*(double num)
{
    return Vector(this->x * num, this->y * num, this->z * num);
}

Vector Vector::operator%(const Vector &other)
{
    return Vector(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
}

double Vector::operator^(const Vector &other)
{
    if (this->GetLength() == 0 || other.GetLength() == 0)
        throw std::domain_error("Деление на ноль невозможно!!!\n");
    return (*this) * other / (this->GetLength() * other.GetLength());
}

Vector &Vector::operator++()
{
    this->x++;
    this->y++;
    this->z++;
    return *this;
}

Vector &Vector::operator--()
{
    this->x--;
    this->y--;
    this->z--;
    return *this;
}

Vector Vector::operator++(int num)
{
    Vector temp = *this;
    ++(*this);
    return temp;
}

Vector Vector::operator--(int num)
{
    Vector temp = *this;
    --(*this);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Vector &output)
{
    os << output.x << " " << output.y << " " << output.z;
    return os;
}

std::istream &operator>>(std::istream &is, Vector &input)
{
    is >> input.x >> input.y >> input.z;
    return is;
}

Vector operator*(double num, Vector &vec)
{
    return Vector(num * vec.x, num * vec.y, num * vec.z);
}