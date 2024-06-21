#include <functional>

#pragma once

void zad_1();

double moja_funkcja(double x);

double calka(std::function<double(double)> f, double a, double b, double dx);

double calka_rownolegle(size_t n_watkow, std::function<double(double)> f, double a, double b, double dx);

double checking_time(std::function<void()> f);

void zad_2();

double cantor(double amount, std::string dest_currency);