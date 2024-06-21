#include <iostream>


// Zmienna globalna, któr¹ bêdziemy inkrementowaæ
std::atomic<int> counter = 0;

// Funkcja, któr¹ wykonuje ka¿dy w¹tek
void incrementCounter() {
    for (int i = 0; i < 100; ++i) {
        // Blokada mutexu zapewniaj¹ca atomow¹ operacjê inkrementacji
        counter++;
    }
}

int main() {
    // Tablica przechowuj¹ca w¹tki
    std::thread threads[100];

    // Tworzenie i uruchamianie 100 w¹tków
    for (int i = 0; i < 100; ++i) {
        threads[i] = std::thread(incrementCounter);
    }

    // Oczekiwanie na zakoñczenie wszystkich w¹tków
    for (int i = 0; i < 100; ++i) {
        threads[i].join();
    }

    // Wyœwietlenie wartoœci zmiennej counter po inkrementacjach
    std::cout << "Wartoœæ zmiennej counter po inkrementacjach: " << counter << std::endl;

    return 0;
}