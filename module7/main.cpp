#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <random>

void PrintContainer(const std::vector<int>& container);
void PrintContainer(const std::array<int, 100>& container);
void FindMinMaxValue(const std::vector<int>& container);
void RemoveMultiples(std::vector<int>& container, int value);

    int main()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(-25, 25);
        std::array<int, 100> array = {0};
        std::vector<int> dynamicArray;

        for (int &i: array) {
            i = distrib(gen);
        }

        PrintContainer(array);

        for (int i: array) {
            if (i % 2 == 0) {
                dynamicArray.push_back(i);
            }
        }

        PrintContainer(dynamicArray);

        //Логика замены элементов. Пробегаемся только до половины так как дальше нет смысла считать
        for (int i = 0; i < dynamicArray.size() / 2; ++i) {
            int opponent = dynamicArray[(dynamicArray.size() - 1) - i];
            if ( opponent != 0) {
                double tmp = dynamicArray[i];
                dynamicArray[i] = std::fmod(dynamicArray[i], opponent);
                if (tmp != 0)
                    dynamicArray[(dynamicArray.size() - 1) - i] = std::fmod(opponent, tmp);
            }
        }

        RemoveMultiples(dynamicArray, 4);

        PrintContainer(dynamicArray);

        FindMinMaxValue(dynamicArray);

        return 0;
    }

    // ********************************************************************************************
    // PrintContainer
    //
    // Выводит переданный вектор в консоль.
    // ********************************************************************************************
    void PrintContainer(const std::vector<int>& container)
    {
        for (const int& item: container) {
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
    void FindMinMaxValue(const std::vector<int>& container)
    {
        const auto [min, max] = std::minmax_element(begin(container), end(container));
        std::cout << "min = " << *min << ", max = " << *max << '\n';
    }

    // ********************************************************************************************
    // RemoveValue
    //
    // Удаляем из массива все картные 4 числа
    // ********************************************************************************************
    void RemoveMultiples(std::vector<int>& container, int value)
    {
       for (std::vector<int>::iterator i = container.begin(); i != container.end(); ) {
           if (std::fmod(*i, value) == 0) {
              i = container.erase(i);

           }else {
               ++i;

           }
       }
    }
