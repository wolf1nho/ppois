#include "Vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Vector a, b;
    cout << "Введите координаты вектора a: ";
    cin >> a;
    cout << "Введите координаты вектора b: ";
    cin >> b;
    int choice;
    do
    {
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
        switch (choice)
        {
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
        case 8:
        {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a * " << num << " = " << (a * num) << "\n";
            break;
        }
        case 9:
        {
            try
            {
                double num;
                cout << "Введите число: ";
                cin >> num;
                cout << "a / " << num << " = " << (a / num) << "\n";
            }
            catch (const exception &e)
            {
                cout << e.what();
            }
            break;
        }
        case 10:
            cout << "[a; b] = " << (a % b) << "\n";
            break;
        case 11:
            try
            {
                cout << "cos(a^b) = " << (a ^ b) << "\n";
            }
            catch (const exception &e)
            {
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
