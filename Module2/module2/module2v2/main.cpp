#include "MathAlgoritm.h"

//*******************************************************************************
//
//����� ����� � ��������� (� ������ ������ ������ ������� �������(only header))
//*******************************************************************************
int main() {

	double a, b;

	std::cout << "Enter the first value = ";
	std::cin >> a;

	std::cout << "Enter the second value = ";
	std::cin >> b;

	std::cout << "Answer = ";

	linearEquation(a, b);

	return 0;
}

