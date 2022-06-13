#include <iostream>
#include <vector>
#include "MathCalcLib.h"

int GetOperationNumber();
void AvailableOperations();
std::vector<double> EnterArguments(int);
char ContinuationOfTheCalculation();
bool IsSecondArgumentRequired(int);

int main() {

	char chSymbol = ' ';
	bool twoVariablesFlag = false;
	
	std::cout << "let's start? y/n" << std::endl;
	std::cin >> chSymbol;

	while ( chSymbol == 'y' )
	{
		AvailableOperations();

		switch (GetOperationNumber())
		{

		case 1:
			std::cout << "Answer " << Sum(EnterArguments(1)) << std::endl;
			break;
		case 2:
			std::cout << "Answer " << Difference(EnterArguments(2)) << std::endl;
			break;
		case 3:
			std::cout << "Answer " << Multiplication(EnterArguments(3)) << std::endl;
			break;
		case 4:
			std::cout << "Answer " << Division(EnterArguments(4)) << std::endl;
			break;
		case 5:
			std::cout << "Answer " << Exponentiation(EnterArguments(5)) << std::endl;
			break;
		case 6:
			std::cout << "Answer " << NumberSquare(EnterArguments(6)) << std::endl;
			break;
		case 7:
			std::cout << "Answer " << PartOfNumber(EnterArguments(7)) << std::endl;
			break;
		case 8:
			std::cout << "Answer " << ABS(EnterArguments(8)) << std::endl;
			break;
		case 9:
			std::cout << "Answer " << Exp(EnterArguments(9)) << std::endl;
			break;
		case 10:
			std::cout << "Answer " << Mod(EnterArguments(10)) << std::endl;
			break;
		case 11:
			std::cout << "Answer " << Sqrt(EnterArguments(11)) << std::endl;
			break;
		case 12:
			std::cout << "Answer " << Factorial(EnterArguments(12)) << std::endl;
			break;
		case 13:
			std::cout << "Answer " << TenToThePowerOfx(EnterArguments(13)) << std::endl;
			break;
		case 14:
			std::cout << "Answer " << Log(EnterArguments(14)) << std::endl;
			break;
		case 15:
			std::cout << "Answer " << Ln(EnterArguments(15)) << std::endl;
			break;
		case 16:
			std::cout << "Answer " << Revers(EnterArguments(16)) << std::endl;
			break;
		default:
			std::cout << "Something went wrong " << std::endl; 
			break;
		}

		chSymbol = ContinuationOfTheCalculation();
	}

	return 0;
}

int GetOperationNumber() {

	unsigned operationNumber = 0;
	std::cout << "Enter operation number " << std::endl;
	std::cin >> operationNumber;

	while (operationNumber > 16 || operationNumber < 1)
	{
		std::cout << "Invalid operation number. Try again: " << std::endl;
		std::cin >> operationNumber;
	}

	return operationNumber;

}

void AvailableOperations() {

	std::cout << "Select operation number" << std::endl;
	std::cout << "1)A+B" << std::endl;
	std::cout << "2)A-B" << std::endl;
	std::cout << "3)A*B" << std::endl;
	std::cout << "4)A/B" << std::endl;
	std::cout << "5)x^y" << std::endl;
	std::cout << "6)x^2" << std::endl;
	std::cout << "7)1/x" << std::endl;
	std::cout << "8)|x|" << std::endl;
	std::cout << "9)exp" << std::endl;
	std::cout << "10)mod" << std::endl;
	std::cout << "11)sqrt(x)" << std::endl;
	std::cout << "12)n!" << std::endl;
	std::cout << "13)10^x" << std::endl;
	std::cout << "14)log" << std::endl;
	std::cout << "15)ln" << std::endl;
	std::cout << "16)+/-" << std::endl;

}

std::vector<double> EnterArguments(int operationNumber) {

	std::vector<double> array;
	double a;

	std::cout << "Enter value a = " << std::endl;
	std::cin >> a;
	array.push_back(a);

	if (IsSecondArgumentRequired(operationNumber)) {
		double b;

		std::cout << "Enter value b = " << std::endl;
		std::cin >> b;
		array.push_back(b);
	}

	return array;
}

char ContinuationOfTheCalculation() {
	char answer = ' ';
	std::cout << "Want to count more? y/n" << std::endl;
	std::cin >> answer;
	return answer;
}

bool IsSecondArgumentRequired(int operation)
{
	if (operation <= 5 || operation == 10)
		return true;

	return false;
}

