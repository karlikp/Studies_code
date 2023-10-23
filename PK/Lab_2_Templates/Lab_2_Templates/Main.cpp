#include "Functions.h"

int main()
{
#if 0
	/*std::cout << "Multiplication is equel: " << multi(2.5, 5.3)
		<< "\nAddition is equel: " << sum(3.6, 13) << std::endl;*/
#endif

	/*std::cout << "Dla typow int: " << min(2, 4) << '\n'
		<< "Dla typow double: " << min(2.5, 4.5) << '\n'
		<< "Dla typow char: " << min('a', 'b') << '\n';*/

	Array<int, 8> arr;

	for (int i = 0; i < arr.size(); i++)
	{
		int j = 2 * i ;
		arr.at(i) = j;
	}
}