#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:

    double x;//x
    double y;//y
    double z;//z

public:

    Vector() {
        this->x = 1;
        this->y = 0;
        this->z = 0;
    }

    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector(const Vector& other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }

    double GetX () const {
        return x;
    }
    double GetY () const {
        return y ;
    }
    double GetZ () const {
        return z;
    }

    void GetCoordinates() const {
        cout << "<" << x << ";" << y << ";" << z << ">\n";
    }

    double GetLength () const {
        return sqrt(x * x + y * y + z * z);
    }

    bool operator == (const Vector& other) const {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

    bool operator != (const Vector& other) const {
        return this->x != other.x || this->y != other.y || this->z != other.z;
    }

    bool operator > (Vector& other) const {
        return this->GetLength() > other.GetLength();
    }

    bool operator < (Vector& other) const {
        return this->GetLength() < other.GetLength();
    }

    bool operator <= (Vector& other) const {
        return this->GetLength() <= other.GetLength();
    }

    bool operator >= (Vector& other) const {
        return this->GetLength() >= other.GetLength();
    }

    Vector& operator = (const Vector& other){
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        return *this;
    }

    Vector& operator += (const Vector& other) {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector& operator -= (const Vector& other) {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Vector operator / (double num) {
        if (num == 0)
            throw invalid_argument("Деление на ноль невозможно!!!\n");
        Vector temp;
        temp.x = this->x / num;
        temp.y = this->y / num;
        temp.z = this->z / num;
        return temp;
    }

    Vector& operator /= (double num) {
        if (num == 0)
            throw invalid_argument("Деление на ноль невозможно!!!\n");
        this->x /= num;
        this->y /= num;
        this->z /= num;
        return *this;
    }

    Vector operator + (const Vector& other) {
        Vector temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        temp.z = this->z + other.z;
        return temp;
    }

    Vector operator - (const Vector& other) {
        Vector temp;
        temp.x = this->x - other.x;
        temp.y = this->y - other.y;
        temp.z = this->z - other.z;
        return temp;
    }

    Vector& operator *= (double num) {
        this->x *= num;
        this->y *= num;
        this->z *= num;
        return *this;
    }

    double operator * (const Vector& temp) {
        return this->x * temp.x + this->y * temp.y + this->z * temp.z;
    }

    Vector operator * (double num) {
        Vector temp;
        temp.x = this->x * num;
        temp.y = this->y * num;
        temp.z = this->z * num;
        return temp;
    }

    Vector operator % (const Vector& other) {
        Vector temp;
        temp.x = this->y * other.z - this->z * other.y;
        temp.y = this->z * other.x - this->x * other.z;
        temp.z = this->x * other.y - this->y * other.x;
        return temp;
    }

    double operator ^ (const Vector temp) {
        if (this->GetLength() == 0 || temp.GetLength() == 0) 
            throw runtime_error("Деление на ноль невозможно!!!\n");
        double cos = (*this) * temp / (this->GetLength() * temp.GetLength());
        return cos;
    }

    Vector& operator++ () {
        this->x++;
        this->y++;
        this->z++;
        return *this;
    }

    Vector& operator++ (int num) {
        Vector temp(*this);
        this->x++;
        this->y++;
        this->z++;
        return temp;
    }

    Vector& operator-- () {
        this->x--;
        this->y--;
        this->z--;
        return *this;
    }

    Vector& operator-- (int num) {
        Vector temp(*this);
        this->x--;
        this->y--;
        this->z--;
        return temp;
    }

    friend ostream& operator << (ostream& os, const Vector& temp);
    friend istream& operator >> (istream& is, Vector& temp);
};

ostream& operator << (ostream& os, const Vector& temp) {
    os << temp.x << " " << temp.y << " " << temp.z;
    return os;
}

istream& operator >> (istream& is, Vector& temp) {
    is >> temp.x >> temp.y >> temp.z;
    return is;
}

//double Cos(Vector& temp1, Vector& temp2) {
//    return temp1 * temp2 / (temp1.GetLength() * temp2.GetLength());
//}

int main()
{
    setlocale(LC_ALL, "ru");
    Vector a, b;
    cout << "Введите координаты вектора a: ";
    cin >> a;
    cout << "Введите координаты вектора b: "; 
    cin >> b;
    int choice;
    do {
        cout << "\nВыберите операцию:\n"
            << "1. Изменить координаты вектора a\n"
            << "2. Изменить координаты вектора b\n"
            << "3. Вывод координат векторов\n"
            << "4. Длина векторов\n"
            << "5. Сумма векторов\n"
            << "6. Разность векторов\n"
            << "7. Скалярное произведение векторов\n"
            << "8. Произведение вектора на число\n"
            << "9. Деление вектора на число\n"
            << "10. Векторное произведение\n"
            << "11. Косинус угла между векторами\n"
            << "12. Сравнение векторов\n"
            << "13. Выход из программы\n"
            << "Введите номер операции: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> a;
            break;
        case 2:
            cin >> b;
            break;
        case 3:
            cout << "a = " << a << "\n";
            cout << "b = " << b << "\n";
            break;
        case 4:
            cout << "|a| = " << a.GetLength() << "\n|b| = " << b.GetLength() << "\n";
            break;
        case 5:
            cout << "a + b = " << a + b << "\n";
            break;
        case 6:
            cout << "a - b = " << a - b << "\n";
            break;
        case 7:
            cout << "a * b = " << (a * b) << "\n";
            break;
        case 8: {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a * " << num << " = " << (a * num) << "\n";
            break;
        }
        case 9: {
            try {
                double num;
                cout << "Введите число: ";
                cin >> num;
                cout << "a / " << num << " = " << (a / num) << "\n";
            }
            catch (const exception& e) {
                cout << e.what();
            }
            break;
        }
        case 10: 
            cout << "[a; b] = " << (a % b) << "\n";
            break;
        case 11:
            try {
                cout << "cos(a^b) = " << (a ^ b) << "\n";
            }
            catch (const exception& e) {
                cout << e.what();
            }
            break;
        case 12:
            cout << "Сравнение длин:\n";
            cout << "a > b ? " << (a > b ? "Да" : "Нет") << "\n";
            cout << "a < b ? " << (a < b ? "Да" : "Нет") << "\n";
            cout << "a >= b ? " << (a >= b ? "Да" : "Нет") << "\n";
            cout << "a <= b ? " << (a <= b ? "Да" : "Нет") << "\n";
            cout << "a == b ? " << (a == b ? "Да" : "Нет") << "\n";
            cout << "a != b ? " << (a != b ? "Да" : "Нет") << "\n";
            break;
        case 13:
            cout << "Выход из программы..." << "\n";
            break;
        default:
            cout << "Некорректный ввод номера операции!!!" << "\n";
        }
    } while (choice != 13);
    return 0;
}

//int main()
//{
//    Vector a(1, 2, 3);
//    Vector b(2, 3, 4);
//    double num;
//    cin >> num;
//    Vector c = a * num;
//    b++;
//    c.GetCoordinates();
//    a.GetCoordinates();
//    b.GetCoordinates();
//}