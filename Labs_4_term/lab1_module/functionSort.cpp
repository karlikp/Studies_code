#include <iostream>

#include"functionSort.h"

void functionSortTable(int tab[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (tab[j - 1] > tab[j])
				std::swap(tab[j - 1], tab[j]);
}

void functionCoutTable(int tab[], int n)
{
	for (int i = 0; i < n; i++) 
	{ std::cout << '[' << tab[i] << ']'; }
}