#include <iostream>
#include <stdexcept>

#include "functions.h"

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


