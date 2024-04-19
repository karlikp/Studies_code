#include "Template.h"
#include "Queue.h"

int main()
{


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

	Queue<int> cyfry;
	cyfry.wloz(1);
	cyfry.wloz(4);
	cyfry.wloz(7);
	cyfry.drukuj();


	Queue<std::string> wyrazy;
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
