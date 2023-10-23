#pragma once

#include <iostream>

#if 0
/*	Szablony funkcji - funkcje generyczne
	generyczny - dotycz�cy ca�ego zbioru os�b, rzeczy, zjawisk po��czonych wsp�lnymi cechami */



Ca�y kod szablonu powinien by� umieszczony w jednym pliku nag��wkowym

template <class T>
T - typ generyczny;

Pod zmienn� T b�dzie m�g� by� podstawiony dowolny typ danych w czasie
wykonywania porgramu;





template<class T>   //typename = class			
T multi(T a, T b)
{
	return a*b;
}

//redundantny - funkcjonalnie niepotrzebny

// je�eli tworzysz dwa klasy typ�w to musisz ich u�y� w argumencie nast�puj�cej funkcji

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



//explicit - s�owo kluczowe zastrzegaj�ce niejawne konwersje

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
