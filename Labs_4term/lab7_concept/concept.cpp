#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <concepts>
#include <iterator>

// Zad1
template<typename T>
concept Iterable = requires(T t) {
    { std::begin(t) } -> std::input_iterator;
    { std::end(t) } -> std::input_iterator;
};

template<Iterable Container>
auto find_max(const Container& container) {
    return *std::max_element(std::begin(container), std::end(container));
}

template<Iterable Container>
auto find_min(const Container& container) {
    return *std::min_element(std::begin(container), std::end(container));
}


void zad1(){
    
    std::cout << "Zad 1" << std::endl;

    std::vector<int> vector1 = { 13, 59, 3, 92, 57, 1, 0 };
    std::list<double> lista1 = { 2.31, 25.5, 43.3, 11.1, 2, 9};

    std::cout << "Max in vector: " << find_max(vector1) << std::endl;
    std::cout << "Max in list: " << find_max(lista1) << std::endl;
    std::cout << "Min in vector: " << find_min(vector1) << std::endl;
    std::cout << "Min in list: " << find_min(lista1) << std::endl;
    std::cout << std::endl << std::endl;
}

//Zad2
template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
bool primeNumber(T num) {
    if (num <= 1) return false;
    for (T i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

void zad2() {
    std::cout << "Zad 2" << std::endl;

    std::cout << "Is the number 4 prime? \nanswer: " << std::boolalpha << primeNumber(4) << std::endl;
    std::cout << "Is the number 7 prime? \nanswer: " << std::boolalpha << primeNumber(7) << std::endl;
    std::cout << std::endl << std::endl;
}

//Zad3
template<typename T>
concept CzyMaSize = requires(T t) {
    { t.size() } -> std::convertible_to<std::size_t>;
};

class Vector {
public:
    std::vector<int> data;

    Vector(std::initializer_list<int> init) : data(init) {}

    std::size_t size() const {
        return data.size();
    }
};

class Lista {
public:
    std::list<int> data;

    Lista(std::initializer_list<int> init) : data(init) {}

    std::size_t size() const {
        return data.size();
    }
};

template<CzyMaSize T, CzyMaSize U>
bool compareSize(const T& a, const U& b) {
    return a.size() == b.size();
}


void zad3() {
    std::cout << "Zad 3" << std::endl;

    Vector vectorZad3 = { 1, 2, 3, 4, 5 };
    Lista listaZad3 = { 10, 20, 30, 40, 50 };
    std::cout << "Are the compared objects equal in size? \nanswer: " << std::boolalpha << compareSize(vectorZad3, listaZad3) << std::endl;
    std::cout << std::endl << std::endl;
}


int main() {

    zad1();
    zad2();
    zad3();

    return 0;
}
