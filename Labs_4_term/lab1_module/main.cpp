#include <iostream>
#include <chrono>

#include "functionSort.h"

import BasicPlane.Figures;
import moduleSort;


void zad_1()
{
	Circle r{ {1,3}, {1,6} };

	std::cout << "Zad_1";
	std::cout << "\n Radius: " << radius(r);
	std::cout << "\n Area: " << area(r);
}

void zad_2()
{
    std::cout << "\nZad_2";

    int n = 7;
    int moduleTable[] = { 4, 1, 3, 5, 7, 8, 9 };
    int functionTable[] = { 4, 1, 3, 5, 7, 8, 9 };

    //Calculate run-time for #module solution
    auto start = std::chrono::steady_clock::now();

    std::cout << "\n Unsorted table: ";
    moduleCoutTable(moduleTable, n);
    moduleSortTable(moduleTable, n);
    std::cout << "\n Sorted table: ";
    moduleCoutTable(moduleTable, n);

    auto end = std::chrono::steady_clock::now();

    auto moduleDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\n Function run-time for module: " << moduleDuration.count() << " microseconds" << std::endl;

    //Calculate run-time for #include solution
    start = std::chrono::steady_clock::now();

    std::cout << "\n Unsorted table: ";
    functionCoutTable(functionTable, n);
    functionSortTable(functionTable, n);
    std::cout << "\n Sorted table: ";
    functionCoutTable(functionTable, n);

    end = std::chrono::steady_clock::now();

    auto functionDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\n Function run-time for include: " << functionDuration.count() << " microseconds\n";

    if (moduleDuration < functionDuration)
        std::cout << "\n Module run-time is shorter than function run-time\n";
    else if (functionDuration < moduleDuration)
        std::cout << "\n Function run-time is shorter than module run-time\n";
    else
        std::cout << "\n Module run-time is equal to the function run-time\n";

}

int main()
{
	zad_1();
    zad_2();
}