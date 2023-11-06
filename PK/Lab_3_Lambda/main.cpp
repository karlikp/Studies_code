#include "functions.h"

int main()
{
	std::cout << "zad.1" << '\n';

	zad_1('a', [](int x) { return x; });
	zad_1('b', [](int x) { return x * 2 + 1; });
	zad_1('c', [](int x) { return x * x - 1; });

	std::cout << '\n' << "zad.2" << '\n';

	zad_2();

	std::cout << '\n' << "zad.3" << '\n';

	zad_3();
}