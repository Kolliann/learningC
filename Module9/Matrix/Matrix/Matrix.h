#pragma once
#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>
#include <functional>

class Matrix
{
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);

	public:
		Matrix(const int row, const int column);
		Matrix(const int row, const int column, int value);
		bool operator==(const Matrix&) const;
		bool operator!=(const Matrix&) const; 
		int& operator()(int, int);
		Matrix operator+(const Matrix&) const;
		Matrix operator+(int) const;
		Matrix& operator+=(const Matrix&);
		Matrix& operator+=(int);
		Matrix operator-(const Matrix&) const;
		Matrix operator-(int) const;
		Matrix& operator-=(const Matrix&);
		Matrix& operator-=(int);
		Matrix operator*(int);
		Matrix& operator*=(int);
		Matrix operator*(const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator++();
		Matrix operator++(int);
		Matrix& operator--();
		Matrix operator--(int);
	
	protected:
		int _row = 0;
		int _column = 0;
		std::vector<int> matrixVector{1};
};

std::istream& operator>>(std::istream&, Matrix& );
std::ostream& operator<<(std::ostream&, const Matrix& );


