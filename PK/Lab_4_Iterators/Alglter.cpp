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
	auto iter = test_value.begin();
	iter += 25;
	cout << "Pierwsze podejœcie: " << *iter << endl;

	iter = test_value.begin();
	iter = next(iter, 25);
	cout << "Drugie podejœcie: " << *iter << endl;
}

void Alglter::zad_3()
{
	auto min = min_element(test_value.begin(), test_value.end());
	auto max = max_element(test_value.begin(), test_value.end());

	cout << "Maksymalny element: " << *max;






}
