#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
 

void printCorrectedTemp(const std::vector<int>& temperatures, int since, int n_displayed)
{
    std::cout << "Podaj od ktorego indeksu zaczac wyswietlac dane: ";
    int start_index = 0;
    std::cin >> start_index;

    std::cout << "Podaj maksymalna ilosc liczb do wyswietlenia: ";
    int max_numbers;
    std::cin >> max_numbers;
  
    auto reverse = std::views::reverse;
    auto delete_end_neg = std::views::drop_while([](int i) { return i <= 0; });
    auto multiply = std::views::transform([](int i) { return i * 2; });
    auto extremes = std::views::filter([](int i) { return i < -10 || i > 20; });
    auto cut = std::views::drop(start_index);
 
    int count = 0;
    for (auto i : temperatures | reverse | delete_end_neg | multiply | extremes | reverse | cut) {
        if (count >= max_numbers)
            break;
        std::cout << i << ' ';
        count++;
    }
    std::cout << '\n';

}
	

void zadanie_2()
{
	std::cout << "\n\n=== ZADANIE 2 ===\n";
	std::vector<int> data{ -10, -6, -1, -2, -3, 2, 3, 10, 7, 13, 15, 8, 19, 10, 7, 2, 0, -1, -5, -10, -20, -25 };
	printCorrectedTemp(data, 1, 10);
}