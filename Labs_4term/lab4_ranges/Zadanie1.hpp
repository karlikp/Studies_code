#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string_view>

struct Pracownik
{
	int id = -1;
	std::string imie;
	std::string nazwisko;
	int wiek = -1;
	int wyplata = -1;
};

std::vector<Pracownik> z1_0_wczytywanieD(std::string_view path)
{
	std::ifstream plik(path.data());

	if (!plik)
	{
		std::cerr << "Nie udalo sie otworzyc pliku\n";
		return {};
	}

	std::vector<Pracownik> pracownicy;
	std::string linia;

	std::getline(plik, linia); // Pomijamy naglowek
	while (std::getline(plik, linia))
	{
		std::istringstream iss(linia);

		Pracownik p;
		iss >> p.id >> p.imie >> p.nazwisko >> p.wiek >> p.wyplata;

		pracownicy.push_back(p);
	}

	return pracownicy;
}

bool porownaj_pracownikow(const Pracownik& a, const Pracownik& b)
{
	if (a.nazwisko != b.nazwisko)
		return a.nazwisko < b.nazwisko;
	return a.imie < b.imie;
}

void z1_1_sortowanie(std::vector<Pracownik>& pracownicy)
{
	std::ranges::sort(pracownicy, {}, &Pracownik::nazwisko);

	for (size_t i = 0; i < pracownicy.size(); ++i) {
		for (size_t j = i + 1; j < pracownicy.size(); ++j) {
			if (porownaj_pracownikow(pracownicy[j], pracownicy[i])) {
				std::swap(pracownicy[i], pracownicy[j]);
			}
		}
	}
	std::cout << "\nPosortowani pracownicy:\n";
	for (const auto& pracownik : pracownicy) {
		std::cout << pracownik.imie << " " << pracownik.nazwisko << std::endl;
	}
	std::cout << "\n";
}

void z1_2_prog(std::vector<Pracownik> const& pracownicy, int prog)
{
	int counter = std::ranges::count_if(pracownicy, [prog](Pracownik i) {return i.wyplata >= prog; });
	std::cout << "\n" << counter << " pracownikow otrzymuje wyplate niemniejsza niz " << prog << "\n";
	
}

void z1_3_nazwisko(std::vector<Pracownik> const& pracownicy, std::string const& nazwisko)
{
	auto pracIT = std::ranges::find(pracownicy, nazwisko, &Pracownik::nazwisko);

	if (pracIT == pracownicy.end())
		std::cout << "\n nie znaleziono\n";
	else
	{
		std::cout << "\nImie i nazwisko: " << pracIT->imie << " " << pracIT->nazwisko
			<< "\nNumer id: " << pracIT->id
			<< "\nWiek: " << pracIT->wiek
			<< "\nWyplata: " << pracIT->wyplata;
	}
}

void zadanie_1()
{
	std::cout << "=== ZADANIE 1 ===\n";

	std::vector<Pracownik> pracownicy = z1_0_wczytywanieD("pracownicy.txt");

	z1_1_sortowanie(pracownicy);


	std::cout << "Podaj prog wyplaty: ";
	int prog;
	std::cin >> prog;

	z1_2_prog(pracownicy, prog);


	std::cout << '\n' << "Podaj nazwisko pracownika : ";
	std::string nazwisko;
	std::cin >> nazwisko;

	z1_3_nazwisko(pracownicy, nazwisko);
}