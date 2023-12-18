#include "Array.h"
#include <stdexcept>

using namespace std;

void Array::show_element(int index)
{
	try
	{
		if (index >= size)
			throw runtime_error("out_of_range - destrukcja tablicy");
	}

	catch(std::exception& e)
	{
		tab_exist = false;
		Array::~Array();
	}

	cout << "Element o indeksie [" << index << "] = " << tablica[index] '\n';		
}
