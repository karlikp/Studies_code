#include "Array.h"
#include <stdexcept>
#include <cstdlib>  // std::srand(), std::rand()
#include <ctime> 
using namespace std;

Array::Array(int SIZE)
{
	size = SIZE;
	table = new int[size];

	srand(time(nullptr));

	for (int i = 0; i < size; i++)
		table[i] = rand() % 10;
}

Array::~Array()
{
	delete[] table;
}

void Array::show_element(int index)
{
	try
	{
		if (index >= size)
			throw runtime_error("out_of_range - destrukcja tablicy");
	}

	catch (std::exception& e)
	{
		if (tab_exist)
		{
			cout << e.what() << '\n';
			tab_exist = false;
		}
	}
	if (tab_exist)
	cout << "Element o indeksie [" << index << "] = " << table[index] << '\n';		
}

int Array::get_element(int index)
{
	try
	{
		if (index >= size)
			throw runtime_error("out_of_range - destrukcja tablicy");
	}

	catch (std::exception& e)
	{
		if (tab_exist)
		{
			cout << e.what() << '\n';
			tab_exist = false;
		}
	}

	if (tab_exist)
		return table[index];

}