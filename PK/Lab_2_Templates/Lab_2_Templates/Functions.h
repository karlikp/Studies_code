#pragma once

#include <iostream>

/*	Szablony funkcji - funkcje generyczne
	generyczny - dotycz¹cy ca³ego zbioru osób, rzeczy, zjawisk po³¹czonych wspólnymi cechami */

#if 0

template <class T>
T - typ generyczny;

Pod zmienn¹ T bêdzie móg³ byæ podstawiony dowolny typ danych w czasie
wykonywania porgramu;

#endif


template<class T>   //typename = class			
T multi(T a, T b)
{
	return a*b;
}

// je¿eli tworzysz dwa klasy typów to musisz ich u¿yæ w argumencie nastêpuj¹cej funkcji

template<class T, class R>
T sum(T a, R b)
{
	return a + b;
}


