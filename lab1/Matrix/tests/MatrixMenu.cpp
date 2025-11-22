#include "Matrix.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Matrix a, b;

    cout << "Заполните первую матрицу:\n";
    a.CreateFromScratch();
    cout << "Заполните вторую матрицу:\n";
    b.CreateFromScratch();
    int choice;
    do
    {
        cout << "\nВыберите операцию:\n"
             << "1. Изменить матрицу а\n"
             << "2. Изменить матрицу b\n"
             << "3. Вывод координат матриц\n"
             << "4. Определить тип матриц\n"
             << "5. Сумма матриц\n"
             << "6. Разность матриц\n"
             << "7. Произведение матриц\n"
             << "8. Произведение матрицы на число\n"
             << "9. Деление матрицы на число\n"
             << "10. Возведение квадратной матрицы в степень\n"
             << "11. Вывод транспонированной матрицы\n"
             << "12. Запись матриц из файла\n"
             << "13. Определить детерминант\n"
             << "14. Определить норму\n"
             << "0. Выход из программы\n"
             << "\nВведите номер операции: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.CreateFromScratch();
            break;
        case 2:
            b.CreateFromScratch();
            break;
        case 3:
            cout << "Матрица а:\n"
                 << a;
            cout << "Матрица b:\n"
                 << b;
            break;
        case 4:
            cout << "Матрица а:\n";
            a.CheckType();
            cout << "Матрица b:\n";
            b.CheckType();
            break;
        case 5:
            cout << "a + b:\n"
                 << a + b;
            break;
        case 6:
            cout << "a - b:\n"
                 << a - b;
            break;
        case 7:
            cout << "a * b:\n"
                 << (a * b) << "\n";
            break;
        case 8:
        {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a * " << num << ":\n"
                 << (a * num);
            break;
        }
        case 9:
        {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a / " << num << ":\n"
                 << (a / num);
            break;
        }
        case 10:
            int num;
            cout << "Введите степень матрицы: ";
            cin >> num;
            cout << "a ^ " << num << ":\n"
                 << (a ^ num);
            break;
        case 11:
            cout << "Транспонированная матрица a:\n"
                 << a.Transposition();
            break;
        case 12:
        {
            string filename;
            cout << "Введите название файла для записи матрицы a:\n";
            cin >> filename;
            a.ReadFromFile(filename);
            cout << "Полученная матрица:\n"
                 << a;
            cout << "Введите название файла для записи матрицы b:\n";
            cin >> filename;
            b.ReadFromFile(filename);
            cout << "Полученная матрица:\n"
                 << b;
            break;
        }
        case 13:
            cout << "Детерминант матрицы a = " << a.Determinant() << "\n";
            break;
        case 14:
            cout << "Норма матрицы a = " << a.Norm() << "\n";
            break;
        case 0:
            cout << "Выход из программы..." << "\n";
            break;
        default:
            cout << "Некорректный ввод номера операции!!!" << "\n";
        }
    } while (choice != 0);
    return 0;
}