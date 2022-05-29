#include "MathCalcLib.h"

double Sum(std::vector<double> array)
{
	return array[0] + array[1];
}

double Difference(std::vector<double> array)
{
	return array[0] + array[1];
}

double Multiplication(std::vector<double> array)
{
	return array[0] * array[1];
}

double Division( std::vector<double> array )
{
	if (array[1] == 0) {

		std::cout << "cannot be divided by 0" << std::endl;
		return 0;
	}

	return array[0] / array[1];
}

double Exponentiation( std::vector<double> array )
{
	return pow(array[0], array[1]);
}

double NumberSquare( std::vector<double> array )
{
	return pow(array[0], 2);
}

double PartOfNumber( std::vector<double> array )
{
	return 1.0 / array[0];
}

double ABS( std::vector<double> array )
{
	return abs(array[0]);
}

double Exp( std::vector<double> array )
{
	return exp(array[0]);
}

double Mod( std::vector<double> array )
{
	return static_cast<int>(array[0]) % static_cast<int>(array[1]);
}

double Sqrt( std::vector<double> array )
{
	return sqrt(array[0]);
}

double Factorial( std::vector<double> array )
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

double TenToThePowerOfx( std::vector<double> array )
{
	return pow(10, static_cast<int>(array[0]));
}

double Log( std::vector<double> array )
{
	return log10(array[0]);
}

double Ln( std::vector<double> array )
{
	return log(array[0]);
}

double Revers( std::vector<double> array )
{
	return array[0] * -1.0;
}
