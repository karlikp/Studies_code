#include <iostream>
#include <vector>
#include <algorithm>

#include "functions.h"


void zad_1(const char subpoint, std::function<int( int )> f )
{
	 std::vector<int>array = {1, 2, 3, 4, 5};

	 std::cout << subpoint << ")\n";

	 for (int i : array)
		 std::cout << "f(" << i << ") = " << f(i) << '\n';
}

void zad_2()
{
	std::vector<int>array = { 3, 5, 7, 9, 11 };
	std::cout << "Enter the number by which I should multiply all elements of the vector: ";
	int a{};
	std::cin >> a;

	int index{ 0 };
	auto lambda = [&](int x)
	{std::cout << "f(array[" << index++ << "]," << a << ") = " << x * a << '\n'; };

	std::for_each(array.begin(), array.end(), lambda);
}

void zad_3()
{
	std::vector<int>array = {17,12,31,22,2,3,11,95,3,5,13,8,71};

	std::sort(array.begin(), array.end(), [](int a, int b) {return b > a;});

	std::cout << "a) " << '\n' << "Vector elements sorted in ascending order: \n";
		for (int i : array)
			std::cout << '[' << i << ']';

	std::sort(array.begin(), array.end(), [](int a, int b) {return a > b;});

	std::cout << '\n' << "b) " << '\n' << 
		"Vector elements sorted in descending order: \n";
	for (int i : array)
		std::cout << '[' << i << ']';

	std::sort(array.begin(), array.end(), [](int a, int b)
		{return ((b > a) and (b % 2 + a % 2 == 0))        // if two are even, set ascending
		or ((b > a) and (b % 2 + a % 2 == 2))			  // if two are odd, set ascending
		or ((b % 2 == 1) and (a % 2 == 0));  });		  // If it's even and odd, put the even number at the front

	std::cout << '\n' << "c) " << '\n' << 
		"Vector elements sorted in ascending order but even ones before odd ones: \n";
	for (int i : array)
		std::cout << '[' << i << ']';

	std::cout << '\n';

}