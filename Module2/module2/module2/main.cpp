#include <iostream>

//�������� �������
void linearEquation( double, double );

//****************************************************************************
//
//����� ����� � ��������� (� ������ ������ ������ ������� �������)
//****************************************************************************
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


//****************************************************************************
//
//����� ������� ��������� ���������
//****************************************************************************
void linearEquation( double a, double b ) {

	if ( a == 0 && b == 0 ) 
	{
		std::cout << "any number";
	}
	else if ( a == 0 && b != 0 ) 
	{
		std::cout << "the equation has no roots";
	}
	else {
		std::cout << -1 * (b / a);
	}
}