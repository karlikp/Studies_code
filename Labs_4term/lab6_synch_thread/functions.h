#include <thread>
#include <mutex>
#include <condition_variable>

#pragma once

void incrementCounter(std::atomic<int>* counter);

void zad_1();

void zad_2();

void message_1(std::mutex* mtx, std::condition_variable* cv, int* counter);

void message_2(std::mutex* lock, std::condition_variable* cv, int* counter);

void message_3(int* counter);