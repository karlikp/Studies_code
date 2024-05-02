#include <iostream>

#include "functions.h"


void incrementCounter(std::atomic<int>* counter) {
    for (int i = 0; i < 100; ++i) {
        (*counter)++;
    }
}

void zad_1() {

    std::cout << "Zad_1: \n";
    std::atomic<int> counter = 0;
    std::thread threads[100];

    for (int i = 0; i < 100; ++i) {
        threads[i] = std::thread(incrementCounter, &counter);
    }

    for (int i = 0; i < 100; ++i) {
        threads[i].join();
    }

    std::cout << "Value variable counter after increment: "
        << counter << "\n\n";
}

void message_1(std::mutex *mtx, std::condition_variable *cv, int*counter) {
    
    while (true)
    {
        if (*counter == 10) {
            std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::unique_lock<std::mutex> lock(*mtx);
        (*cv).wait(lock, [&counter]() { return *counter % 2 == 0 ; });
        std::cout << "Message 1\n";
        (*counter)++;
        
        (*cv).notify_one();
       
        

    }
}

void message_2(std::mutex* mtx, std::condition_variable* cv, int* counter) {
   
    while (true)
    {
        std::unique_lock<std::mutex> lock(*mtx);

        if (*counter == 10) {
            std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
         
        (*cv).wait(lock, [&counter]() { return (*counter % 2 == 1 and (*counter) != 10); });
        std::cout << "Message 2\n";
        (*counter)++;
        (*cv).notify_one();
     
       
    }
}

void message_3(int* counter) {
    
    while (true)
    {
        if ((*counter) > 9){
            std::cout << "Write 10 messages\n";
            (*counter) = 0;
        }
    }
}

void zad_2() {
    std::cout << "Zad_2: \n";
    std::mutex mtx;
    std::condition_variable cv;
    int counter = 0;

    std::thread t1(message_1, &mtx, &cv, &counter);
    std::thread t2(message_2, &mtx, &cv, &counter);
    std::thread t3(message_3, &counter);

    t1.join();
    t2.join();
    t3.join();
}