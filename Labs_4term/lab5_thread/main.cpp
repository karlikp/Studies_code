#include <iostream>

#include "functions.h"

int main()
{
    constexpr size_t thread_number = 8;
    constexpr double A = 1.0;
    constexpr double B = 100.0;
    double dx = 1e-12;

    const double single_thread = checking_time([] {
        std::cout << "Na jednym watku: " << calka(moja_funkcja, A, B, dx) << "\n";
        });
    std::cout << "Czas: " << single_thread << "s\n\n";

    const double multi_thread = checking_time([] {
        std::cout << "Na " << thread_number << " watkach: " << calka_rownolegle(thread_number, moja_funkcja, A, B, dx) << "\n";
        });
    std::cout << "Czas: " << multi_thread << "s\n";

    std::cout << "Poprawa czasu: " << single_thread / multi_thread << "x\n";

    zad_2();
}