#include <iostream>

#include "UnikatowyWsk.cpp"

class Zasob
{
    UnikatowyWsk<int> table;
    int size = 5;
public:

    Zasob()
    {
        std::cout << "Konstrukcja" << std::endl;
        table = new int [size];
    }

    ~Zasob()
    {
        std::cout << "Destrukcja" << std::endl;
        
    }
};


