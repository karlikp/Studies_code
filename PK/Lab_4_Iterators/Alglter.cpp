#include "Alglter.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

Alglter::Alglter(vector<int> TEST_VALUE) : test_value(TEST_VALUE)
{
	this->test_value = TEST_VALUE;
}

void Alglter::zad_2()
{
	cout << "Zad 2\n";
	auto iter = test_value.begin();
	iter += 25;
	cout << "Wypisanie elementu na 25 pozycji pierwszym sposobem: " << *iter << '\n';

	iter = test_value.begin();
	iter = next(iter, 25);
	cout << "Wypisanie elementu na 25 pozycji drugim sposobem: " << *iter << "\n\n";
}

void Alglter::zad_3()
{
	cout << "Zad 3\n";

	auto min = min_element(test_value.begin(), test_value.end());
	auto index_min = distance(test_value.begin(), min);
	auto max = max_element(test_value.begin(), test_value.end());
	auto index_max = distance(test_value.begin(), max);

	cout << "Maksymalny element: " << *max << '\n';
	cout << "Pozycja wystapienia w tablicy: " << index_max << '\n';
	cout << "Minimalny element: " << *min << "\n";
	cout << "Pozycja wystapienia w tablicy: " << index_min << "\n\n";
}

void Alglter::zad_4()
{
	cout << "Zad 4\n";

	int amount = count(test_value.begin(), test_value.end(), 33);

	cout << "Ilosc wystapien liczby 33: " << amount << "\n\n";
}

void Alglter::zad_5()
{
	cout << "Zad 5\n";

	auto expected = find(test_value.begin(), test_value.end(), 91);
	auto index = distance(test_value.begin(), expected);
	cout << "Pierwszy raz liczba 91 w tablicy wystepuje na pozycji: " << index << "\n\n";
}

void Alglter::zad_6()
{
	cout << "Zad 6\n";

	auto sum = accumulate(test_value.begin() + 20, test_value.begin() + 51, 0);
	cout << "Suma elementow wynosi: " << sum << "\n\n";
}

void Alglter::zad_7()
{
	cout << "Zad 7\n";
	cout << "Wektor posortowany rosnaco:\n";
	sort(test_value.begin(), test_value.end());

	for (const auto& el : test_value)
		cout << el << ' ';
	cout << "\n\n";

}

void Alglter::zad_8()
{
	cout << "Zad 8\n";
	cout << "Wektor posortowany rosnaco z usunietymi duplikatami:\n";
	sort(test_value.begin(), test_value.end());

	auto iter = unique(test_value.begin(), test_value.end());
	test_value.erase(iter, test_value.end());

	for (const auto& el : test_value)
		cout << el << ' ';

	cout << "\n\n";
}

void Alglter::zad_9()
{
	cout << "Zad 9\n";

	bool answer = binary_search(test_value.begin(), test_value.end(), 44);

	if (answer)
		cout << "liczba 44 istnieje";
	else
		cout << "liczba 44 nie istnieje";

	cout << "\n";
}
