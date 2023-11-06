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
	}

	T& at(size_t n)
	{
		return data[n];
	}

	size_t size() 
	{
		return N;
	}
};

template <typename T>
class Kolejka
{
	T tab[10];
	int zajetosc = 0; //liczba elementow aktualnie znajdujacych sie w kolejce
	bool pelna;			//przechowuje informacje czy kolejka jest pe�na
	int indeks_ostatniego = -1;
	int indeks_pierwszego = 0;

public:

	Kolejka() = default;
	~Kolejka() = default;

	bool czyPelna()
	{
		if (zajetosc <= 9)
			return false;
		else
			return true;
	}

	bool czyPusta()
	{
		if (zajetosc == 0)
			return true;
		else
			return false;
	}
	void wloz(T ostatni)
	{	
		if (zajetosc == 10)
		{
			std::cout << "Tablica jest pe�na, nie mo�na zapisa� elementu";
			return;
		}
		else
		{
			zajetosc++;
			if (indeks_ostatniego == 9)
			{
				indeks_ostatniego = 0;
			}
			else
				indeks_ostatniego++;

			tab[indeks_ostatniego] = ostatni;
			
		}
	}

	T wez()
	{
		if (zajetosc == 0)
		{
			std::cout << "Tablica jest pusta, nie mo�na wziac elementu";
			return " ";
		}
		else
		{
			zajetosc--;

			T  pierwszy = tab[indeks_pierwszego];

			if (indeks_pierwszego == 9)
				indeks_pierwszego = 0;
			
			else
				indeks_pierwszego++;

			return pierwszy;
		}
	}

	int ile_elem()
	{
		return zajetosc;
	}

	void drukuj()
	{
		std::cout << "Zawartosc tablicy: " << '\n';
		int temp = indeks_pierwszego; //tymczasowy pierwszy element

		for (int i = 0; i < zajetosc; i++)
		{
			std::cout << "[" << tab[temp] <<"], ";
			if (temp == 9)
				temp = 0;
			else
				temp++;
		}
		std::cout << '\n';
	}
};
