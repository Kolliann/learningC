#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <random>

// ********************************************************************************************
// print_container
//
// Выводит переданный вектор в консоль.
// ********************************************************************************************
void print_container(const std::vector<double>& container)
{
    for (auto& item: container)
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}
// ********************************************************************************************
// print_container
//
// Выводит переданный массив в консоль(пока захардкожено 100).
// ********************************************************************************************
void print_container(const std::array<int, 100>& container)
{
    for (auto& item: container)
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

// ********************************************************************************************
// find_min_max_value
//
// Поиск минимального и максимального числа
// ********************************************************************************************
void find_min_max_value(const std::vector<double>& container){

    const auto [min, max] = std::minmax_element(begin(container), end(container));
    std::cout << "min = " << *min << ", max = " << *max << '\n';
}

// ********************************************************************************************
// remove_value
//
// Удаляем из массива все картные 4 числа
// ********************************************************************************************
void remove_value(std::vector<double>& container , double value){
    for (auto i = container.begin(); i != container.end(); ++i) {
        if (std::fmod(*i, value) == 0) {
            container.erase(i);
            i--;
        }
    }
}

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-25, 25);
    std::array<int, 100> array = {0};
    std::vector<double> dynamicArray;

    for (int & i : array){
        i = distrib(gen);
    }

    print_container(array);

    for (int i : array) {
        if ( i % 2 == 0 ){
            dynamicArray.push_back(static_cast<double>(i));
        }
    }
    print_container(dynamicArray);

    std::cout << "=====================dynamicArray.size()===================== " << dynamicArray.size() << "\n";

    std::cout << "=====================dynamicArray.center===================== " << dynamicArray.size()/2 << "\n";

    //Логика замены элементов. Пробегаемся только до половины так как дальше нет смысла считать
    for (int i = 0; i < dynamicArray.size()/2; ++i) {
        if (dynamicArray[(dynamicArray.size() - 1) - i] != 0) {
            double tmp = dynamicArray[i];
            dynamicArray[i] = std::fmod(dynamicArray[i], dynamicArray[(dynamicArray.size() - 1) - i]);
            if (tmp != 0)
                dynamicArray[(dynamicArray.size() - 1) - i] = std::fmod(dynamicArray[(dynamicArray.size() - 1) - i], tmp);
        }
    }

    remove_value( dynamicArray, 4.0 );

    print_container( dynamicArray );

    find_min_max_value( dynamicArray );

    return 0;
}
