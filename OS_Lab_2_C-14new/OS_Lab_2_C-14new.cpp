#include <iostream>
#include <thread>
#include <vector>
#include "Header.h"

/*
Написать программу для консольного процесса,
который состоит из трех потоков: main, min_max и average
*/

constexpr int MyPrecision = 3;

int main()
{
    std::cout << std::fixed;
    std::cout.precision(MyPrecision);
    int Size;

    std::cout << "Enter number of elements: ";
    std::cin >> Size;
    std::vector<double> Array(Size, static_cast<double>(0));
    std::pair<double, double> minmax;
    double average;

    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < Size; i++)
    {
        std::cout << "element " << i << ": ";
        int elem;
        std::cin >> elem;
        Array[i] = static_cast<double>(elem);
    }

    std::thread ThreadMinMax(Laboratory_2::Min_Max, std::ref(Array), std::ref(minmax));
    ThreadMinMax.join();

    std::thread ThreadAverage(Laboratory_2::Average, std::ref(Array), std::ref(average));
    ThreadAverage.join();

    std::cout << "Array with all min/max elements to average:" << std::endl;

    Laboratory_2::Change_Array(Array, minmax, average);

    return 0;
}