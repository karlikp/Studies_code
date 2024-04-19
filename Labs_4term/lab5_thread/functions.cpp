#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>
#include <cmath>
#include <functional>
#include <iomanip>

#include "functions.h"

void zad_1()
{
    constexpr size_t thread_number = 8;
    constexpr double A = 1.0;
    constexpr double B = 100.0;
    constexpr double dx = 1e-6;

    const double single_thread = checking_time([] {
        std::cout << "Na jednym watku: " << calka(moja_funkcja, A, B, dx) << "\n";
        });
    std::cout << "Czas: " << single_thread << "s\n\n";

    const double multi_thread = checking_time([] {
        std::cout << "Na " << thread_number << " watkach: " << calka_rownolegle(thread_number, moja_funkcja, A, B, dx) << "\n";
        });
    std::cout << "Czas: " << multi_thread << "s\n";

    std::cout << "Poprawa czasu: " << single_thread / multi_thread << "x\n";
}

double moja_funkcja(double x)
{
    return std::sqrt(x);
}

double calka(std::function<double(double)> f, double a, double b, double dx)
{
    double sign = 1.0;

    if (a > b)
    {
        std::swap(a, b);
        sign = -1.0;
    }

    double result = 0.0;
    for (double x = a; x < b; x += dx)
    {
        result += f(x) * dx;
    }

    return result * sign;
}

double calka_rownolegle(size_t thread_number, std::function<double(double)> f, double a, double b, double dx = 1e-12)
{
    
    std::vector<std::future<double>> sub_results;

    for (size_t i = 0; i < thread_number; i++)
    {
        const double chain = std::abs(b - a) / thread_number;

        const double a_i = a + i*chain;
        const double b_i = a_i + chain;

        sub_results.push_back(std::async(std::launch::async, [=] {
            return calka(f, a_i, b_i, dx);
        }));
    }

    double result = 0.0;
    for (auto& sub_result : sub_results)
    {
        result += sub_result.get();
    }

    return result;
}

double checking_time(std::function<void()> f)
{
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(stop - start).count();
}

void zad_2()
{
    double amount;
    std::cout << "\nPodaj kwote w PLN, ktora chcesz zamienic na inna walute: ";
    std::cin >> amount;

    std::string dest_currency;
    do {
        std::cout << "\n\nWybierz walute docelowa, wpisz EUR lub USD: ";
        std::cin >> dest_currency;
    } while (not(dest_currency == "EUR" or dest_currency == "USD"));

    std::packaged_task<double(double, std::string)> task(cantor);
    std::future<double> result = task.get_future();
    std::thread t(std::move(task), amount, dest_currency);
    t.join();
    std::cout << "\nMozesz uzyskac " << result.get() << " " << dest_currency << "\n";
}

double cantor(double amount, std::string dest_currency)
{
    float result_amount;
    std::cout << std::fixed << std::setprecision(2);
    if (dest_currency == "EUR")
        result_amount = amount * 0.23;
    else
        result_amount = amount * 0.25;
    return result_amount;
}