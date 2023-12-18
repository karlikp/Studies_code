#include <iostream>
#include <stdexcept>

#include "functions.h"
#include "Array.h"
#include "Ustawienia.h"
#include "Zasob.cpp"

using namespace std;


void zad_1()
{
    cout << "Zadanie 1\n";
    cout << "Podaj liczbe, ktora zostanie sprawdzona: ";
    int number;
    cin >> number;

    bool checking = true, condition1 = true, condition2 = true, condition3 = true;
   
    while (checking)
    {
        try
        {
            checking = check_conditions(number, condition1, condition2, condition3);
        }
        catch (std::exception& e)
        {
            cout << "Podana liczba " << e.what() << '\n';
        }

    }
    
}

bool check_conditions(int number, bool& condition1, bool& condition2, bool& condition3)
{
    
    if (number % 2 and condition1)
    {
        condition1 = false;
        throw runtime_error("jest nieparzysta");
    }

    if ((number % 7) != 0 and condition2)
    {
        condition2 = false;
        throw runtime_error("nie jest podzielna bez reszty przez 7");
    }

    if (number % 3 == 0 and condition3)
    {
        condition3 = false;
        throw runtime_error("jest podzielna bez reszty przez 3");
    }

    if (condition1)
        cout << "Podana liczba jest parzysta.\n";
        
    if (condition2)
        cout << "Podana liczba jest podzielna bez reszty przez 7. \n";

    if (condition3)
        cout << "Podana liczba nie jest podzielna bez reszty przez 3.\n";

    return false;
}

void zad_2()
{
    cout << "Zadanie 2\n";
    int size, index;
    cout << "Wpisz rozmiar tablicy: ";
    cin >> size;
    cout << "Wpisz indeks elementu tablicy, ktory zostanie sprawdzony i wypisany"
        " na dwa rozne sposoby: ";
    cin >> index;

    Array object(size);
    object.show_element(index);
    int element = object.get_element(index);

    if (object.tab_exist)
        cout << "Element o indeksie [" << index << "] = " << element << '\n';
}

void zad_3()
{
    cout << "Zadanie 3\n";

    Ustawienia& pierwszy = Ustawienia::Instance();

    string save_name, check_name;
    int save_option, check_option;
    
    cout << "Wpisz nazwe opcji do zapisania: ";
    cin >> save_name;
    cout << "Wpisz numer opcji do zapisania: ";
    cin >> save_option;

    pierwszy.zapiszOpcje(save_name, save_option);

    cout << "Wpisz nazwe opcji do sprawdzenia: ";
    cin >> check_name;
  
    check_option = pierwszy.sprawdzOpcje(check_name);

    if(pierwszy.available)
    std::cout << "Pod nazwa [" << check_name << "] zapisana jest opcja nr: "
        << check_option;

    cout << '\n';

    Zasob object;

}



