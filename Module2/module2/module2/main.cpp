#include <iostream>

//описание функции
void linearEquation( double, double );

//****************************************************************************
//
//Точка входа в программу (в данном случае первый вариант задания)
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
//Метод решения линейного уравнения
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