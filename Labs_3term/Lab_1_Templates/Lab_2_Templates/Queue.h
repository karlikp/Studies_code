#pragma once
#include "Template.h"

template <typename T>
class Queue
{
	T table[10];
	int queueLength = 0; 
	bool queueFull;			
	int lastIndex = -1;
	int firstIndex = 0;

public:

	Queue() = default;
	~Queue() = default;

	bool ifFull();
	

	bool ifEmpty()
	{
		if (queueLength == 0)
			return true;
		else
			return false;
	}
	void set(T last)
	{
		if (queueLength == 10)
		{
			std::cout << "The array is full, the item cannot be saved";
			return;
		}
		else
		{
			queueLength++;
			if (lastIndex == 9)
			{
				lastIndex = 0;
			}
			else
				lastIndex++;

			table[lastIndex] = last;

		}
	}

	T get()
	{
		if (queueLength == 0)
		{
			std::cout << "The array is empty, the element cannot be taken";
			return " ";
		}
		else
		{
			queueLength--;

			T  first = table[firstIndex];

			if (firstIndex == 9)
				firstIndex = 0;

			else
				firstIndex++;

			return first;
		}
	}

	int howMuch()
	{
		return queueLength;
	}

	void print()
	{
		std::cout << "Table contain: " << '\n';
		int temp = firstIndex; 

		for (int i = 0; i < queueLength; i++)
		{
			std::cout << "[" << table[temp] << "], ";
			if (temp == 9)
				temp = 0;
			else
				temp++;
		}
		std::cout << '\n';
	}
};


