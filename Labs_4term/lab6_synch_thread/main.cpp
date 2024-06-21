#include <iostream>


// Zmienna globalna, kt�r� b�dziemy inkrementowa�
std::atomic<int> counter = 0;

// Funkcja, kt�r� wykonuje ka�dy w�tek
void incrementCounter() {
    for (int i = 0; i < 100; ++i) {
        // Blokada mutexu zapewniaj�ca atomow� operacj� inkrementacji
        counter++;
    }
}

int main() {
    // Tablica przechowuj�ca w�tki
    std::thread threads[100];

    // Tworzenie i uruchamianie 100 w�tk�w
    for (int i = 0; i < 100; ++i) {
        threads[i] = std::thread(incrementCounter);
    }

    // Oczekiwanie na zako�czenie wszystkich w�tk�w
    for (int i = 0; i < 100; ++i) {
        threads[i].join();
    }

    // Wy�wietlenie warto�ci zmiennej counter po inkrementacjach
    std::cout << "Warto�� zmiennej counter po inkrementacjach: " << counter << std::endl;

    return 0;
}