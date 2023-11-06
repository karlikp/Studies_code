#include "Functions.h"

int main()
{
#if 0
	/*std::cout << "Multiplication is equel: " << multi(2.5, 5.3)
		<< "\nAddition is equel: " << sum(3.6, 13) << std::endl;*/
#endif

	//Zad.1

	/*std::cout << "Dla typow int: " << min(2, 4) << '\n'
		<< "Dla typow double: " << min(2.5, 4.5) << '\n'
		<< "Dla typow char: " << min('a', 'b') << '\n';*/

	//Zad.2

	/*Array<int, 8> arr;

	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = i * 3;
	}
	for (int i = 0; i < arr.size(); i++)
	{ 
		std::cout << arr.at(i) << ' ';
	}*/

	//Zad.3

	Kolejka<int> cyfry;
	cyfry.wloz(1);
	cyfry.wloz(4);
	cyfry.wloz(7);
	cyfry.drukuj();


	Kolejka<std::string> wyrazy;
	wyrazy.wloz("mama");
	wyrazy.wloz("tata");
	wyrazy.wloz("brat");
	wyrazy.wloz("siostra");
	wyrazy.wloz("wujek");
	wyrazy.wloz("mama");
	wyrazy.wloz("tata");
	wyrazy.wloz("brat");
	wyrazy.wloz("siostra");
	wyrazy.wloz("wujek");

	wyrazy.wez();
	wyrazy.wez();
	wyrazy.wez();

	wyrazy.wloz("lort1");
	wyrazy.wloz("lort2");

	wyrazy.drukuj();

	wyrazy.ile_elem();
	wyrazy.czyPelna();
	




	

	
}
