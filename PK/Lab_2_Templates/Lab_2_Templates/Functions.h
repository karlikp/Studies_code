#pragma once

#include <iostream>

/*	Szablony funkcji - funkcje generyczne
	generyczny - dotycz�cy ca�ego zbioru os�b, rzeczy, zjawisk po��czonych wsp�lnymi cechami */

#if 0

template <class T>
T - typ generyczny;

Pod zmienn� T b�dzie m�g� by� podstawiony dowolny typ danych w czasie
wykonywania porgramu;

#endif


template<class T>   //typename = class			
T multi(T a, T b)
{
	return a*b;
}

// je�eli tworzysz dwa klasy typ�w to musisz ich u�y� w argumencie nast�puj�cej funkcji

template<class T, class R>
T sum(T a, R b)
{
	return a + b;
}


