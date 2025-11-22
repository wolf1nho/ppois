#include "Matrix.h"

bool Matrix::IsLowerTriangular() const
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::IsUpperTriangular() const
{
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (mat[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::DiagonalIsTheSame() const
{
    for (int i = 1; i < m && i < n; i++)
    {
        if (mat[i][i] != mat[i - 1][i - 1])
        {
            return false;
        }
    }
    return true;
}

bool Matrix::IsSymmetric() const
{
    if (m != n)
        return false;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::IsDiag() const
{
    return IsUpperTriangular() && IsLowerTriangular();
}

bool Matrix::IsEmpty() const
{
    return mat == nullptr;
}

bool Matrix::IsPositive() const
{
    return m > 0 && n > 0;
}

bool Matrix::IsPositive(int m, int n) const
{
    return m > 0 && n > 0;
}

bool Matrix::IsLess(int m, int n) const
{
    return this->m > m || this->n > n;
}

Matrix Matrix::Minor(int row, int col) const
{
    Matrix minor(m - 1, n - 1);
    int minor_i = 0;
    for (int i = 0; i < m; i++)
    {
        if (i == row)
            continue;
        int minor_j = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == col)
                continue;
            minor.mat[minor_i][minor_j] = mat[i][j];
            minor_j++;
        }
        minor_i++;
    }
    return minor;
}

Matrix::Matrix()
{
    mat = nullptr;
    m = 0;
    n = 0;
}

Matrix::Matrix(int m, int n)
{
    if (IsPositive(m, n))
    {
        this->m = m;
        this->n = n;
        mat = new double *[m];
        for (int i = 0; i < m; i++)
        {
            mat[i] = new double[n];
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;
        }
    }
    else
    {
        this->mat = nullptr;
        this->m = 0;
        this->n = 0;
    }
}

Matrix::Matrix(const Matrix &other)
{
    if (other.IsEmpty())
    {
        mat = nullptr;
        m = 0;
        n = 0;
    }
    else
    {
        m = other.m;
        n = other.n;
        mat = new double *[m];
        for (int i = 0; i < m; i++)
        {
            mat[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
}

Matrix::~Matrix()
{
    Delete();
}

void Matrix::Create()
{
    if (IsEmpty() && IsPositive(m, n))
    {
        mat = new double *[m];
        for (int i = 0; i < m; i++)
        {
            mat[i] = new double[n];
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;
        }
    }
}

void Matrix::Create(int m, int n)
{
    if (IsEmpty() && IsPositive(m, n))
    {
        this->m = m;
        this->n = n;
        mat = new double *[m];
        for (int i = 0; i < m; i++)
        {
            mat[i] = new double[n];
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;
        }
    }
}

void Matrix::CreateFromScratch()
{
    if (!IsEmpty())
        Delete();
    cout << "Введите количество строк матрицы:\n";
    cin >> m;
    cout << "Введите количество столбцов матрицы:\n";
    cin >> n;
    if (IsPositive() && IsEmpty())
    {
        Create();
        cout << "Введите элементы матрицы:\n";
        SetElements();
    }
}

void Matrix::SetElements()
{
    if (IsEmpty())
        return;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void Matrix::Delete()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < m; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
        mat = nullptr;
        m = 0;
        n = 0;
    }
}

void Matrix::View() const
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Matrix::ReadFromFile(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Файл не открыт!!!\n";
        return;
    }
    else
    {
        if (!(file >> m >> n))
            throw runtime_error("Недостаточно данных для записи из файла");
        Delete();
        Create(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!(file >> mat[i][j]))
                    throw runtime_error("Недостаточно данных для записи из файла");
            }
        }
        file.close();
    }
}

void Matrix::CheckType()
{
    if (IsEmpty())
    {
        cout << "Матрица пустая";
        return;
    }
    if (n == m)
    {
        cout << "Квадратная\n";
        if (IsDiag())
        {
            cout << "Симметричная\n";
            if (DiagonalIsTheSame())
            {
                if (mat[0][0] == 1)
                    cout << "Единичная\n";
                else if (mat[0][0] == 0)
                    cout << "Нулевая\n";
                else
                    cout << "Диагональная\n";
            }
            else
                cout << "Диагональная\n";
        }
        else
        {
            if (IsUpperTriangular())
                cout << "Верхняя треугольная\n";
            else if (IsLowerTriangular())
            {
                cout << "Нижняя треугольная\n";
            }
            if (IsSymmetric())
            {
                cout << "Симметричная\n";
            }
        }
    }
}

void Matrix::SetM(int m)
{
    if (this->m == 0 && IsEmpty())
    {
        if (m < 0)
            throw invalid_argument("Размер матрицы не может быть отрицательным!!!\n");
        this->m = m;
    }
    else
        throw runtime_error("Невозможно поменять значение, так как матрица не пустая!!!\n");
}

void Matrix::SetN(int n)
{
    if (this->n == 0 && IsEmpty())
    {
        if (n < 0)
            throw invalid_argument("Размер матрицы не может быть отрицательным!!!\n");
        this->n = n;
    }
    else
        throw runtime_error("Невозможно поменять значение, так как матрица не пустая!!!\n");
}

bool Matrix::IsSquare() const
{
    return m == n;
}

Matrix &Matrix::Transposition()
{
    if (!IsSquare())
        throw invalid_argument("Матрица не является квадратной!!!");
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    return *this;
}

Matrix Matrix::Submatrix(int m, int n)
{
    if (!IsLess(m, n) || !IsPositive(m, n))
    {
        return *this; // скопируется через конструктор копирования(не знал поэтому не работал метод)
    }
    Matrix sub(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sub.mat[i][j] = this->mat[i][j];
        }
    }
    return sub;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        Delete();
        Create(other.m, other.n);
        for (int i = 0; i < other.m; i++)
        {
            for (int j = 0; j < other.n; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix &other) const
{
    if (this->m == other.m && this->n == other.n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (this->mat[i][j] != other.mat[i][j])
                    return false;
            }
        }
    }
    else
        return false;
    return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
    if (this->m == other.m && this->n == other.n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (this->mat[i][j] != other.mat[i][j])
                    return true;
            }
        }
    }
    else
        return true;
    return false;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (this->m != other.m || this->n != other.n)
        throw invalid_argument("Сложение матриц разных размеров невозможно!!!\n");
    Matrix sum(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            sum.mat[i][j] = this->mat[i][j] + other.mat[i][j];
    return sum;
}

Matrix &Matrix::operator+=(const Matrix &other)
{
    if (this->m != other.m || this->n != other.n)
        throw invalid_argument("Сложение матриц разных размеров невозможно!!!\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            this->mat[i][j] += other.mat[i][j];
    return *this;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (this->m != other.m || this->n != other.n)
        throw invalid_argument("Разность матриц разных размеров невозможно!!!\n");
    Matrix dif(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            dif.mat[i][j] = this->mat[i][j] - other.mat[i][j];
    return dif;
}

Matrix &Matrix::operator-=(const Matrix &other)
{
    if (this->m != other.m || this->n != other.n)
        throw invalid_argument("Разность матриц разных размеров невозможно!!!\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            this->mat[i][j] -= other.mat[i][j];
    return *this;
}

Matrix Matrix::operator+(double num) const
{
    if (m != n)
        throw invalid_argument("Сложение с числом возможно только для квадратной матрицы!!!\n");
    Matrix sum(*this);
    for (int i = 0; i < m; i++)
        sum.mat[i][i] += num;
    return sum;
}

Matrix &Matrix::operator+=(double num)
{
    if (m != n)
        throw invalid_argument("Сложение с числом возможно только для квадратной матрицы!!!\n");
    for (int i = 0; i < m; i++)
        this->mat[i][i] += num;
    return *this;
}

Matrix Matrix::operator-(double num) const
{
    if (m != n)
        throw invalid_argument("Разность с числом возможна только для квадратной матрицы!!!\n");
    Matrix dif(*this);
    for (int i = 0; i < m; i++)
        dif.mat[i][i] -= num;
    return dif;
}

Matrix &Matrix::operator-=(double num)
{
    if (m != n)
        throw runtime_error("Разность с числом возможна только для квадратной матрицы!!!\n");
    for (int i = 0; i < m; i++)
        this->mat[i][i] -= num;
    return *this;
}

Matrix Matrix::operator*(double num) const
{
    Matrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            temp.mat[i][j] = this->mat[i][j] * num;
    return temp;
}

Matrix &Matrix::operator*=(double num)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            this->mat[i][j] *= num;
    return *this;
}

Matrix Matrix::operator/(double num) const
{
    if (num == 0)
        throw domain_error("Деление на ноль невозможно!!!\n");
    Matrix div(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            div.mat[i][j] = this->mat[i][j] / num;
    return div;
}

Matrix &Matrix::operator/=(double num)
{
    if (num == 0)
        throw domain_error("Деление на ноль невозможно!!!\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            this->mat[i][j] /= num;
    return *this;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (this->n != other.m)
        throw invalid_argument("Умножение матриц возможно, только если кол-во столбцов первой матрицы равно кол-ву строк второй матрицы!!!\n");
    Matrix comp(this->m, other.n);
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < other.n; j++)
        {
            for (int k = 0; k < this->n; k++)
                comp.mat[i][j] += this->mat[i][k] * other.mat[k][j];
        }
    }
    return comp;
}

Matrix Matrix::operator^(int exp) const
{
    if (m != n)
        throw invalid_argument("Матрица не является квадратной!!!\n");
    Matrix copiedmat = *this;
    for (int i = 1; i < exp; i++)
        copiedmat = copiedmat * *this;
    return copiedmat;
}

Matrix &Matrix::operator^=(int exp)
{
    if (m != n)
        throw invalid_argument("Матрица не является квадратной!!!\n");
    Matrix copiedmat = *this;
    for (int i = 1; i < exp; i++)
        *this = *this * copiedmat;
    return *this;
}

double Matrix::Determinant() const
{
    if (m != n)
        throw invalid_argument("Матрица не является квадратной!!!\n");
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    double det = 0;
    int sign = 1;
    for (int j = 0; j < m; j++)
    {
        Matrix minor = Minor(0, j);
        det += sign * mat[0][j] * minor.Determinant();
        sign *= -1;
    }
    return det;
}

double Matrix::Norm() const
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += mat[i][j] * mat[i][j];
        }
    }
    return sqrt(sum);
} // норма фробениуса

istream &operator>>(istream &is, Matrix &input)
{
    if (input.IsEmpty())
        return is;
    for (int i = 0; i < input.m; i++)
    {
        for (int j = 0; j < input.n; j++)
        {
            is >> input.mat[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &output)
{
    if (output.IsEmpty())
        return os;
    for (int i = 0; i < output.m; i++)
    {
        for (int j = 0; j < output.n; j++)
        {
            os << output.mat[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
