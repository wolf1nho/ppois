#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int m; // строки
    int n; // столбцы
    double** mat;

    bool IsLowerTriangular() const {
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    bool IsUpperTriangular() const {
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (mat[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    bool DiagonalIsTheSame() const {
        for (int i = 1; i < m && i < n; i++) {
            if (mat[i][i] != mat[i - 1][i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool IsSymmetric() const {
        if (m != n) return false;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool IsDiag() const {
        return IsUpperTriangular() && IsLowerTriangular();
    }

    bool IsEmpty() const {
        return mat == nullptr;
    }

    bool IsPositive() const {
        return m > 0 && n > 0;
    }

    bool IsPositive(int m, int n) const {
        return m > 0 && n > 0;
    }

    bool IsLess(int m, int n) const {
        return this->m > m || this->n > n;
    }

    Matrix Minor(int row, int col) const {
        Matrix minor(m - 1, n - 1);
        int minor_i = 0;
        for (int i = 0;i < m;i++) {
            if (i == row)
                continue;
            int minor_j = 0;
            for (int j = 0;j < n;j++) {
                if (j == col)
                    continue;
                minor.mat[minor_i][minor_j] = mat[i][j];
                minor_j++;
            }
            minor_i++;
        }
        return minor;
    }

public:

    Matrix() {
        mat = nullptr;
        m = 0;
        n = 0;
    }

    Matrix(int m, int n) {
        if (IsPositive(m, n)) {
            this->m = m;
            this->n = n;
            mat = new double* [m];
            for (int i = 0; i < m; i++) {
                mat[i] = new double[n];
                for (int j = 0; j < n; j++)
                    mat[i][j] = 0;
            }
        }
        else {
            this->mat = nullptr;
            this->m = 0;
            this->n = 0;
        }
    }

    Matrix(const Matrix& other) {
        if (other.IsEmpty()) {
            mat = nullptr;
            m = 0;
            n = 0;
        }
        else {
            m = other.m;
            n = other.n;
            mat = new double* [m];
            for (int i = 0; i < m; i++) {
                mat[i] = new double[n];
                for (int j = 0; j < n; j++) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
    }

    ~Matrix() {
        Delete();
    }

    void Create() {
        if (IsEmpty() && IsPositive(m, n)) {
            mat = new double* [m];
            for (int i = 0; i < m; i++) {
                mat[i] = new double[n];
                for (int j = 0; j < n; j++)
                    mat[i][j] = 0;
            }
        }
    }

    void Create(int m, int n) {
        if (IsEmpty() && IsPositive(m, n)) {
            this->m = m;
            this->n = n;
            mat = new double* [m];
            for (int i = 0; i < m; i++) {
                mat[i] = new double[n];
                for (int j = 0; j < n; j++)
                    mat[i][j] = 0;
            }
        }
    }

    void CreateFromScratch() {
        if (!IsEmpty())
            Delete();
        cout << "Введите количество строк матрицы:\n";
        cin >> m;
        cout << "Введите количество столбцов матрицы:\n";
        cin >> n;
        if (IsPositive() && IsEmpty()) {
            Create();
            cout << "Введите элементы матрицы:\n";
            SetElements();
        }
    }

    void SetElements() {
        if (IsEmpty())
            return;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void Delete() {
        if (!IsEmpty()) {
            for (int i = 0; i < m; i++) {
                delete[] mat[i];
            }
            delete[] mat;
            mat = nullptr;
            m = 0;
            n = 0;
        }
    }

    void View() const {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void ReadFromFile(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Файл не открыт!!!\n";
            return;
        }
        else {
            if (!(file >> m >> n))
                throw exception();
            Delete();
            Create(m, n);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!(file >> mat[i][j]))
                        throw exception(/* "Недостаточно данных для записи из файла" */);
                }
            }
            file.close();
        }
    }

    void CheckType() {
        if (IsEmpty())
        cout << "Матрица пустая";
        else if (n == m) {
            cout << "Квадратная\n";
            if (IsDiag()) {
                cout << "Симметричная\n";
                if (DiagonalIsTheSame()) {
                    if (mat[0][0] == 1)
                        cout << "Единичная\n";
                    else if (mat[0][0] == 0)
                        cout << "Нулевая\n";
                    else cout << "Диагональная\n";
                }
                else cout << "Диагональная\n";
            }
            else {
                if (IsUpperTriangular())
                    cout << "Верхняя треугольная\n";
                else if (IsLowerTriangular()) {
                    cout << "Нижняя треугольная\n";
                }
                if (IsSymmetric()) {
                    cout << "Симметричная\n";
                }
            }
        }
    }

    void SetM(int m) {
        if (this->m == 0 && IsEmpty()) {
            if (m < 0)
                throw invalid_argument("Размер матрицы не может быть отрицательным!!!\n");
            this->m = m;
        }
        else throw exception(/*"Невозможно поменять значение, так как матрица не пустая!!!\n"*/);
    }

    void SetN(int n) {
        if (this->n == 0 && IsEmpty()) {
            if (n < 0)
                throw invalid_argument("Размер матрицы не может быть отрицательным!!!\n");
            this->n = n;
        }
        else throw exception(/*"Невозможно поменять значение, так как матрица не пустая!!!\n"*/);
    }

    bool IsSquare() const {
        return m == n;
    }

    Matrix& Transposition() {
        if (!IsSquare())
            throw invalid_argument("Матрица не является квадратной!!!");
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        return *this;
    }

    Matrix Submatrix(int m, int n) {
        if (!IsLess(m, n) || !IsPositive(m, n)) {
            cout << "Подматрица равна исходной!!!\n";
            return *this; // скопируется через конструктор копирования(не знал поэтому не работал метод)
        }
        Matrix sub(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sub.mat[i][j] = this->mat[i][j];
            }
        }
        return sub;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            Delete();
            Create(other.m, other.n);
            for (int i = 0; i < other.m; i++) {
                for (int j = 0; j < other.n; j++) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
        return *this;
    }

    bool operator == (const Matrix& other) const {
        if (this->m == other.m && this->n == other.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (this->mat[i][j] != other.mat[i][j])
                        return false;
                }
            }
        }
        else return false;
        return true;
    }

    bool operator != (const Matrix& other) const {
        if (this->m == other.m && this->n == other.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (this->mat[i][j] != other.mat[i][j])
                        return true;
                }
            }
        }
        else return true;
        return false;
    }

    Matrix operator +(const Matrix& other) const {
        if (this->m != other.m || this->n != other.n)
            throw invalid_argument("Сложение матриц разных размеров невозможно!!!\n");
        Matrix sum(m, n);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                sum.mat[i][j] = this->mat[i][j] + other.mat[i][j];
        return sum;
    }

    Matrix& operator +=(const Matrix& other) {
        if (this->m != other.m || this->n != other.n)
            throw invalid_argument("Сложение матриц разных размеров невозможно!!!\n");
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                this->mat[i][j] += other.mat[i][j];
        return *this;
    }

    Matrix operator -(const Matrix& other) const {
        if (this->m != other.m || this->n != other.n)
            throw invalid_argument("Разность матриц разных размеров невозможно!!!\n");
        Matrix dif(m, n);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                dif.mat[i][j] = this->mat[i][j] - other.mat[i][j];
        return dif;
    }

    Matrix& operator -=(const Matrix& other) {
        if (this->m != other.m || this->n != other.n)
            throw invalid_argument("Разность матриц разных размеров невозможно!!!\n");
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                this->mat[i][j] -= other.mat[i][j];
        return *this;
    }

    Matrix operator +(double num) const {
        if (m != n)
            throw invalid_argument("Сложение с числом возможно только для квадратной матрицы!!!\n");
        Matrix sum(*this);
        for (int i = 0;i < m;i++)
            sum.mat[i][i] += num;
        return sum;
    }

    Matrix& operator +=(double num) {
        if (m != n)
            throw invalid_argument("Сложение с числом возможно только для квадратной матрицы!!!\n");
        for (int i = 0;i < m;i++)
            this->mat[i][i] += num;
        return *this;
    }

    Matrix operator -(double num) const {
        if (m != n)
            throw invalid_argument("Разность с числом возможна только для квадратной матрицы!!!\n");
        Matrix dif(*this);
        for (int i = 0;i < m;i++)
            dif.mat[i][i] -= num;
        return dif;
    }

    Matrix& operator -=(double num) {
        if (m != n)
            throw runtime_error("Разность с числом возможна только для квадратной матрицы!!!\n");
        for (int i = 0;i < m;i++)
            this->mat[i][i] -= num;
        return *this;
    }

    Matrix operator *(double num) const {
        Matrix temp(m, n);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                temp.mat[i][j] = this->mat[i][j] * num;
        return temp;
    }

    Matrix& operator *=(double num) {
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                this->mat[i][j] *= num;
        return *this;
    }

    Matrix operator /(double num) const {
        if (num == 0)
            throw domain_error("Деление на ноль невозможно!!!\n");
        Matrix div(m, n);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                div.mat[i][j] = this->mat[i][j] / num;
        return div;
    }

    Matrix& operator /=(double num) {
        if (num == 0)
            throw domain_error("Деление на ноль невозможно!!!\n");
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                this->mat[i][j] /= num;
        return *this;
    }

    Matrix operator *(const Matrix& other) const {
        if (this->n != other.m)
            throw invalid_argument("Умножение матриц возможно, только если кол-во столбцов первой матрицы равно кол-ву строк второй матрицы!!!\n");
        Matrix comp(this->m, other.n);
        for (int i = 0;i < this->m;i++) {
            for (int j = 0;j < other.n;j++) {
                for (int k = 0;k < this->n;k++)
                    comp.mat[i][j] += this->mat[i][k] * other.mat[k][j];
            }
        }
        return comp;
    }

    Matrix operator ^(int exp) const {
        if (m != n)
            throw invalid_argument("Матрица не является квадратной!!!\n");
        Matrix copiedmat = *this;
        for (int i = 1;i < exp;i++)
            copiedmat = copiedmat * *this;
        return copiedmat;
    }

    Matrix& operator ^=(int exp) {
        if (m != n)
            throw invalid_argument("Матрица не является квадратной!!!\n");
        Matrix copiedmat = *this;
        for (int i = 1;i < exp;i++)
            *this = *this * copiedmat;
        return *this;
    }

    double Determinant() const {
        if (m != n)
            throw invalid_argument("Матрица не является квадратной!!!\n");
        if (n == 1)
            return mat[0][0];
        if (n == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        double det = 0;
        int sign = 1;
        for (int j = 0;j < m;j++) {
            Matrix minor = Minor(0, j);
            det += sign * mat[0][j] * minor.Determinant();
            sign *= -1;
        }
        return det;
    }

    double Norm() const {
        double sum = 0;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                sum += mat[i][j] * mat[i][j];
            }
        }
        return sqrt(sum);
    }//норма фробениуса

    friend ostream& operator << (ostream& os, const Matrix& output);
    friend istream& operator >> (istream& is, Matrix& input);
};

istream& operator >> (istream& is, Matrix& input) {
    if (input.IsEmpty())
        return is;
    for (int i = 0; i < input.m; i++) {
        for (int j = 0; j < input.n; j++) {
            is >> input.mat[i][j];
        }
    }
    return is;
}

ostream& operator << (ostream& os, const Matrix& output) {
    if (output.IsEmpty())
        return os;
    for (int i = 0; i < output.m; i++) {
        for (int j = 0; j < output.n; j++) {
            os << output.mat[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

int main() {
    setlocale(LC_ALL, "ru");
    Matrix a, b;
    cout << "Заполните первую матрицу:\n";
    a.CreateFromScratch();
    cout << "Заполните вторую матрицу:\n";
    b.CreateFromScratch();
    int choice;
    do {
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
        switch (choice) {
        case 1:
            a.CreateFromScratch();
            break;
        case 2:
            b.CreateFromScratch();
            break;
        case 3:
            cout << "Матрица а:\n" << a;
            cout << "Матрица b:\n" << b;
            break;
        case 4:
            cout << "Матрица а:\n"; a.CheckType();
            cout << "Матрица b:\n"; b.CheckType();
            break;
        case 5:
            cout << "a + b:\n" << a + b;
            break;
        case 6:
            cout << "a - b:\n" << a - b;
            break;
        case 7:
            cout << "a * b:\n" << (a * b) << "\n";
            break;
        case 8: {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a * " << num << ":\n" << (a * num);
            break;
        }
        case 9: {
            double num;
            cout << "Введите число: ";
            cin >> num;
            cout << "a / " << num << ":\n" << (a / num);
            break;
        }
        case 10:
            int num;
            cout << "Введите степень матрицы: ";
            cin >> num;
            cout << "a ^ " << num << ":\n" << (a ^ num);
            break;
        case 11:
            cout << "Транспонированная матрица a:\n" << a.Transposition();
            break;
        case 12: {
            string filename;
            cout << "Введите название файла для записи матрицы a:\n";
            cin >> filename;
            a.ReadFromFile(filename);
            cout << "Полученная матрица:\n" << a;
            cout << "Введите название файла для записи матрицы b:\n";
            cin >> filename;
            b.ReadFromFile(filename);
            cout << "Полученная матрица:\n" << b;
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
