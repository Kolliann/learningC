#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <random>

void PrintContainer(const std::vector<double>& container);
void PrintContainer(const std::array<int, 100>& container);
void FindMinMaxValue(const std::vector<double>& container);
void RemoveMultiples(std::vector<double>& container, double value);

    int main()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(-25, 25);
        std::array<int, 100> array = {0};
        std::vector<double> dynamicArray;

        for (int &i: array) {
            i = distrib(gen);
        }

        PrintContainer(array);

        for (int i: array) {
            if (i % 2 == 0) {
                dynamicArray.push_back(static_cast<double>(i));
            }
        }

        PrintContainer(dynamicArray);

        //Логика замены элементов. Пробегаемся только до половины так как дальше нет смысла считать
        for (int i = 0; i < dynamicArray.size() / 2; ++i) {
            if (dynamicArray[(dynamicArray.size() - 1) - i] != 0) {
                double tmp = dynamicArray[i];
                dynamicArray[i] = std::fmod(dynamicArray[i], dynamicArray[(dynamicArray.size() - 1) - i]);
                if (tmp != 0)
                    dynamicArray[(dynamicArray.size() - 1) - i] = std::fmod(dynamicArray[(dynamicArray.size() - 1) - i],
                                                                            tmp);
            }
        }

        RemoveMultiples(dynamicArray, 4.0);

        PrintContainer(dynamicArray);

        FindMinMaxValue(dynamicArray);

        return 0;
    }

    // ********************************************************************************************
    // PrintContainer
    //
    // Выводит переданный вектор в консоль.
    // ********************************************************************************************
    void PrintContainer(const std::vector<double>& container)
    {
        for (auto &item: container) {
         std::cout << item << " ";
        }
        std::cout << '\n';
    }

    // ********************************************************************************************
    // PrintContainer
    //
    // Выводит переданный массив в консоль(пока захардкожено 100).
    // ********************************************************************************************
    void PrintContainer(const std::array<int, 100>& container)
    {
        for (auto &item: container) {
            std::cout << item << " ";
        }
        std::cout << '\n';
    }

    // ********************************************************************************************
    // FindMinMaxValue
    //
    // Поиск минимального и максимального числа
    // ********************************************************************************************
    void FindMinMaxValue(const std::vector<double>& container)
    {
        const auto [min, max] = std::minmax_element(begin(container), end(container));
        std::cout << "min = " << *min << ", max = " << *max << '\n';
    }

    // ********************************************************************************************
    // RemoveValue
    //
    // Удаляем из массива все картные 4 числа
    // ********************************************************************************************
    void RemoveMultiples(std::vector<double>& container, double value)
    {
       for (auto i = container.begin(); i != container.end(); ++i) {
           if (std::fmod(*i, value) == 0) {
               container.erase(i);
               i--;
           }
       }
    }
