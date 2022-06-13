#include "MathCalcLib.h"

double Sum(const std::vector<double>& array)
{
	return array[0] + array[1];
}

double Difference(const std::vector<double>& array)
{
	return array[0] + array[1];
}

double Multiplication(const std::vector<double>& array)
{
	return array[0] * array[1];
}

double Division(const std::vector<double>& array)
{
	if (array[1] == 0) {

		std::cout << "cannot be divided by 0" << std::endl;
		return 0;
	}

	return array[0] / array[1];
}

double Exponentiation(const std::vector<double>& array)
{
	return pow(array[0], array[1]);
}

double NumberSquare(const std::vector<double>& array)
{
	return pow(array[0], 2);
}

double PartOfNumber(const std::vector<double>& array)
{
	return 1.0 / array[0];
}

double ABS(const std::vector<double>& array)
{
	return abs(array[0]);
}

double Exp(const std::vector<double>& array)
{
	return exp(array[0]);
}

double Mod(const std::vector<double>& array)
{
	return static_cast<int>(array[0]) % static_cast<int>(array[1]);
}

double Sqrt(const std::vector<double>& array)
{
	return sqrt(array[0]);
}

double Factorial(const std::vector<double>& array)
{
	if (array[0] < 0) {
	
		return 0;
	}

	if (array[0] == 0) {

		return 1;
	}
	else {

		std::vector<double> newArray = { array[0] - 1 };

		return array[0] * Factorial(newArray);
	}

}

double TenToThePowerOfx(const std::vector<double>& array)
{
	return pow(10, static_cast<int>(array[0]));
}

double Log(const std::vector<double>& array)
{
	return log10(array[0]);
}

double Ln(const std::vector<double>& array)
{
	return log(array[0]);
}

double Revers(const std::vector<double>& array)
{
	return array[0] * -1.0;
}
