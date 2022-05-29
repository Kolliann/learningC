#include <iostream>
#include <vector>
#include <MathCalcLib.h>

int GetOperationNumber();
void AvailableOperations();
std::vector<double> GetValue(bool flag);
char ContinuationOfTheCalculation();


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
			std::cout << "Answer " << Sum(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 2:
			std::cout << "Answer " << Difference(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 3:
			std::cout << "Answer " << Multiplication(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 4:
			std::cout << "Answer " << Division(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 5:
			std::cout << "Answer " << Exponentiation(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 6:
			std::cout << "Answer " << NumberSquare(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 7:
			std::cout << "Answer " << PartOfNumber(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 8:
			std::cout << "Answer " << ABS(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 9:
			std::cout << "Answer " << Exp(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 10:
			std::cout << "Answer " << Mod(GetValue(true)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 11:
			std::cout << "Answer " << Sqrt(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 12:
			std::cout << "Answer " << Factorial(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 13:
			std::cout << "Answer " << TenToThePowerOfx(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 14:
			std::cout << "Answer " << Log(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 15:
			std::cout << "Answer " << Ln(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		case 16:
			std::cout << "Answer " << Revers(GetValue(false)) << std::endl;
			chSymbol = ContinuationOfTheCalculation();
			break;
		default:
			std::cout << "Something went wrong " << std::endl; 
			chSymbol = ContinuationOfTheCalculation();
			break;
		}
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

std::vector<double> GetValue(bool flag) {

	std::vector<double> array;
	double a;

	std::cout << "Enter value a = " << std::endl;
	std::cin >> a;
	array.push_back(a);


	if (flag) {
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

