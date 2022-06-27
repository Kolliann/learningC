#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix a(2, 2);
    std::cout << "enter matrix A = " << "\n";
    std::cin >> a;


    a++;
    std::cout << "------------------------" << "\n";
    std::cout << a;
    std::cout << "------------------------" << "\n";

    Matrix b(2, 2);
    std::cout << "enter matrix B = " << "\n";
    std::cin >> b;
    auto c = a == a;
    std::cout << c << "\n";

    int valueByIndex = b(0, 0);
    std::cout << valueByIndex << "\n";
    std::cout << "------------------------" << "\n";
    std::cout << a;
    std::cout << "------------------------" << "\n";
    std::cout << b;
    std::cout << "------------------------" << "\n";
    std::cout << a + b;
    std::cout << "------------------------" << "\n";
    std::cout << a + 1;
    std::cout << "------------------------" << "\n";
    std::cout << a - 1;
    std::cout << "------------------------" << "\n";
    std::cout << a * 2;
    std::cout << "------------------------" << "\n";
    std::cout << a;
    std::cout << "------------------------" << "\n";
    a *= b;
    std::cout << a;
    std::cout << "------------------------" << "\n";

    ++a;
    std::cout << a;
    std::cout << "------------------------" << "\n";
    return 0;
}