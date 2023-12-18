#include "Ustawienia.h"
#include <stdexcept>

using namespace std;

Ustawienia& Ustawienia::Instance()
{
	static Ustawienia instance;
	return instance;
}

void Ustawienia::zapiszOpcje(const std::string& nazwa, int opcja)
{
	settings.insert({ nazwa, opcja });
}

int Ustawienia::sprawdzOpcje(const std::string& nazwa)
{
	try
	{
		if (not settings.contains(nazwa))  // od wersji C++ 20
			throw std::out_of_range("out_of_range");
	}

	catch (std::exception& e)
	{
		available = false;
		cout << e.what() << '\n';
	}

	if(available)
	return settings.at(nazwa);

	return 0;
}

