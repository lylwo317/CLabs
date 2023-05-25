//
// Created by kevin on 2021/8/11.
//
#include <atomic>
#include <cassert>
#include <string>
#include <thread>
std::atomic<int> x { 0 }; // global variable
std::atomic<int> y { 0 }; // global variable
std::atomic<bool> ready { false };
int r1 = 0;
int r2 = 0;
int data = 0;
void producer()
{
    int a = 0;
    int b = 230;
    int c = 30;
    y++;
    r1 = y.load(std::memory_order_relaxed); // A
    x.store(r1, std::memory_order_relaxed); // B
}
void consumer()
{
    int a = 0;
    int b = 230;
    int c = 30;
    r2 = x.load(std::memory_order_relaxed); // C
    y.store(42, std::memory_order_relaxed); // D
}
void plusplus()
{
    int a = 6;
    x.load(std::memory_order_relaxed);
    int b = 7;
    int c = 8;
    int d = 9;
    // x.fetch_add(1, std::memory_order_relaxed);
}
int main()
{
    while (true) {
        x = 0;
        y = 0;
        r1 = 0;
        r2 = 0;
        std::thread t1(producer);
        std::thread t2(consumer);
        std::thread t3(plusplus);
        t1.join();
        t2.join();
        t3.join();
        if (r1 == 42 && r2 == 42) {
            break;
        }
    }
    return 0;
}