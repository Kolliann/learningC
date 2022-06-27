#include <iostream>
#include "Matrix.h"

Matrix::Matrix(const int row, const int column): _row(row), _column(column)
{
    matrixVector.resize(row * column);
}

Matrix::Matrix(const int row, const int column, int value) : _row(row), _column(column)
{
    matrixVector.resize(row * column, value);
}

bool Matrix::operator==(const Matrix& rhs) const {
    return _column == rhs._column && _row == rhs._row && std::equal(matrixVector.begin(), matrixVector.end(), rhs.matrixVector.begin(), rhs.matrixVector.end());
}
bool Matrix::operator!=(const Matrix& rhs) const {
    return !(*this == rhs);
}

int& Matrix::operator()(int firstValue, int secondValue)
{
    return matrixVector[_column * firstValue + secondValue];
}

Matrix Matrix::operator+(const Matrix& m) const
{
    if (_column != m._column || _row != m._row) {
        std::cout << "Invalid operation" << "\n";
    }
    Matrix result(_column, _row);
    std::transform(matrixVector.begin(), matrixVector.end(), m.matrixVector.begin(), result.matrixVector.begin(), std::plus<>());
    return result;
}

Matrix Matrix::operator+(int value) const
{
    Matrix tmpVector(_column, _row, value);
    Matrix result(_column, _row);
    std::transform(matrixVector.begin(), matrixVector.end(), tmpVector.matrixVector.begin(), result.matrixVector.begin(), std::plus<>());
    return result;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    if (_column != m._column || _row != m._row) {
        std::cout << "Invalid operation" << "\n";
    }
    std::transform(matrixVector.begin(), matrixVector.end(), m.matrixVector.begin(), matrixVector.begin(), std::plus<>());
    return *this;
}

Matrix& Matrix::operator+=(int value)
{
    Matrix tmpVector(_column, _row, value);
    std::transform(matrixVector.begin(), matrixVector.end(), tmpVector.matrixVector.begin(), matrixVector.begin(), std::plus<>());
    return *this;
}

Matrix Matrix::operator-(const Matrix& m) const
{
    if (_column != m._column || _row != m._row) {
        std::cout << "Invalid operation" << "\n";
    }
    Matrix result(_column, _row);
    std::transform(matrixVector.begin(), matrixVector.end(), m.matrixVector.begin(), result.matrixVector.begin(), std::minus<>());
    return result;
}

Matrix Matrix::operator-(int value) const
{
    Matrix tmpVector(_column, _row, value);
    Matrix result(_column, _row);
    std::transform(matrixVector.begin(), matrixVector.end(), tmpVector.matrixVector.begin(), result.matrixVector.begin(), std::minus<>());
    return result;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
    if (_column != m._column || _row != m._row) {
        std::cout << "Invalid operation" << "\n";
    }
    std::transform(matrixVector.begin(), matrixVector.end(), m.matrixVector.begin(), matrixVector.begin(), std::minus<>());
    return *this;
}

Matrix& Matrix::operator-=(int value)
{
    Matrix tmpVector(_column, _row, value);
    std::transform(matrixVector.begin(), matrixVector.end(), tmpVector.matrixVector.begin(), matrixVector.begin(), std::minus<>());
    return *this;
}

Matrix Matrix::operator*(int value)
{
    Matrix tmpVector(_column, _row);
    tmpVector.matrixVector = matrixVector;
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            tmpVector.matrixVector[i * _column + j] = tmpVector.matrixVector[i * _column + j] * value;
        }
    }
    return tmpVector;
}

Matrix& Matrix::operator*=(int value)
{
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            matrixVector[i * _column + j] = matrixVector[i * _column + j] * value;
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& m)
{
    Matrix tmpVector(_row, m._column);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            for (int k = 0; k < m._column; ++k) {
                tmpVector.matrixVector[i * _column + j] += matrixVector[i * _column + k] * m.matrixVector[k * _column + j];
            }
        }
    }
    return tmpVector;
}

Matrix& Matrix::operator*=(const Matrix& m)
{
    Matrix tmpVector(_row, m._column);
    tmpVector.matrixVector = matrixVector;
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            for (int k = 0; k < m._column; ++k) {
                matrixVector[i * _column + j] += tmpVector.matrixVector[i * _column + k] * m.matrixVector[k * _column + j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator++()
{
    for (int& item : this->matrixVector) 
    {
        item+=1;
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix matrix = (*this);
    ++(*this);

    return matrix;
}

Matrix& Matrix::operator--()
{
    for (int& item : this->matrixVector)
    {
        item -= 1;
    }
    return *this;
}

Matrix Matrix::operator--(int)
{
    Matrix matrix = (*this);
    --(*this);

    return matrix;
}

std::istream& operator>>(std::istream& input, Matrix& m)
{
    for (int i = 0; i < m._row; i++)
        for (int j = 0; j < m._column; j++)
            input >> m.matrixVector[i * m._column + j];
    return input;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
 {
    for (int i = 0; i < m._row; ++i) {
        for (int j = 0; j < m._column; ++j) {
            out << m.matrixVector[i * m._column + j] << " ";
        }
        out << "\n";
    }
    return out;
}
