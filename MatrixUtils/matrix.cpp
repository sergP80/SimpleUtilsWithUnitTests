#include "matrix.h"
#include <cmath>
#include <algorithm>

void matrix::Matrix::init_data()
{
    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new double[cols];
    }
}

void matrix::Matrix::check_indices(int i, int j) const
{
    if (is_empty())
    {
        throw xIndicesForEmptyMatrix();
    }

    if (i < 0 || i >= rows || j < 0 || j >= cols)
    {
        throw xIndicesOutOfRange();
    }
}

matrix::Matrix::Matrix(int rows, int cols)
    : rows(rows)
    , cols(cols)
    , data(nullptr)
{
    init_data();
}

matrix::Matrix::~Matrix()
{
    clear();
}

void matrix::Matrix::clear()
{
    if (data == nullptr)
    {
        return;
    }

    for (int i = 0; i < rows; ++i)
    {
        if (data[i] == nullptr)
        {
            continue;
        }
        delete[] data[i];
    }

    delete[] data;
    data = nullptr;
}

const bool matrix::Matrix::is_empty() const
{
    return nullptr == data;
}

double& matrix::Matrix::operator()(int i, int j)
{
    check_indices(i, j);
    return data[i][j];
}

const double& matrix::Matrix::operator()(int i, int j) const
{
    check_indices(i, j);
    return data[i][j];
}

const double& matrix::Matrix::max() const
{
    double max = data[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (data[i][j] > max)
            {
                max = data[i][j];
            }
        }
    }
    return max;
}

const double& matrix::Matrix::min() const
{
    double min = data[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (data[i][j] < min)
            {
                min = data[i][j];
            }
        }
    }
    return min;
}

const bool matrix::Matrix::is_diag() const
{
    if (rows != cols) {
        return false;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i == j)
            {
                continue;
            }

            if (std::fabs(data[i][j]) != 0)
            {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// 1. Реалізувати обчислення визначника матриці
/// https://pro-prof.com/forums/topic/gauss-determinant_cplusplus
/// 2. Написати два-три тести для цього методу
/// </summary>
/// <returns></returns>
const double& matrix::Matrix::det() const
{
    return 0;
}

/// <summary>
/// Реалізувати інверсію матриці
/// https://cpp.mazurok.com/tag/%D0%BE%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F-%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0/
/// https://www.webmath.ru/forum/index.php?topic=7944.0
/// </summary>
/// <returns></returns>
matrix::Matrix& matrix::Matrix::inverse()
{
    return *this;
}

matrix::Matrix matrix::operator+(const matrix::Matrix& m1, const matrix::Matrix& m2)
{
    int rows = std::min(m1.get_rows(), m2.get_rows());
    int cols = std::min(m1.get_cols(), m2.get_cols());
    
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result(i, j) = m1(i, j) + m2(i, j);
        }
    }
    return result;
}

bool matrix::operator==(const Matrix& m1, const Matrix& m2)
{
    if (m1.get_rows() != m2.get_rows())
    {
        return false;
    }

    if (m1.get_cols() != m2.get_cols())
    {
        return false;
    }

    for (int i = 0; i < m1.get_rows(); ++i)
    {
        for (int j = 0; j < m1.get_cols(); ++j)
        {
            if (std::fabs(m1(i, j) - m2(i, j)) > 1e-3)
            {
                return false;
            }
        }
    }
    return true;
}
