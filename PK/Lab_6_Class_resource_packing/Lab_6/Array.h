#pragma once
#include <iostream>

class Array
{
	int size;
	int* tablica;
	int tab_exist = true;


public:
	Array(int size)
	{
	int* tablica = new int[size];
	}

	~Array()
	{
		delete[] tablica;
	}
	void show_element(int index);
	
	
};

