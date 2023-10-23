#pragma once

#include <iostream>

#if 0
/*	Szablony funkcji - funkcje generyczne
	generyczny - dotycz¹cy ca³ego zbioru osób, rzeczy, zjawisk po³¹czonych wspólnymi cechami */



Ca³y kod szablonu powinien byæ umieszczony w jednym pliku nag³ówkowym

template <class T>
T - typ generyczny;

Pod zmienn¹ T bêdzie móg³ byæ podstawiony dowolny typ danych w czasie
wykonywania porgramu;





template<class T>   //typename = class			
T multi(T a, T b)
{
	return a*b;
}

//redundantny - funkcjonalnie niepotrzebny

// je¿eli tworzysz dwa klasy typów to musisz ich u¿yæ w argumencie nastêpuj¹cej funkcji

template<class T, class R>
T sum(T a, R b)
{
	return a + b;
}

template <typename T>
bool is_greater(T a, T b)
{
	return a > b;
}

template <typename T>
void f(T)
{
	static int i = 0;
	std::cout << ++i;
}



//explicit - s³owo kluczowe zastrzegaj¹ce niejawne konwersje

#endif

//Laboratorium

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

	~Array()
	{
		delete[] data;
	};

	&at(size_t n)
	{
		return data[n];
	}

	size_t size() 
	{
		return N;
	}
};
