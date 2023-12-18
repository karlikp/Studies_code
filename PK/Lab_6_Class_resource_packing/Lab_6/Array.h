#pragma once
#include <iostream>

class Array
{
	int size;
	int* table;

public:
	bool tab_exist = true;

	Array(int size);

	~Array();
	
	void show_element(int index);

	int get_element(int index);
	
	
};

