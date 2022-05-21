
#include <iostream>

//****************************************************************************
//
//Метод решения линейного уравнения
//****************************************************************************
void linearEquation(double a, double b) {

	if (a == 0 && b == 0)
	{
		std::cout << "any number";
	}
	else if (a == 0 && b != 0)
	{
		std::cout << "the equation has no roots";
	}
	else {
		std::cout << -1 * (b / a);
	}
}