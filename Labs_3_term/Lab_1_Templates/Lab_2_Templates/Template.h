#pragma once

#include <iostream>

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T, size_t N>
class Array
{
	T* data = new T[N];

public:

	Array() = default;
	~Array() {delete[] data;}

	T& at(size_t n) {return data[n];}
	size_t size() {return N;}
};

