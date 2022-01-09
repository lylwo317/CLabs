//
// Created by kevin on 2021/8/11.
//
#include <thread>
#include <atomic>
#include <cassert>
#include <string>
std::atomic<bool> ready{ false };
int data = 0;
void producer()
{
    int a = 20;
    int b = 30;
    int c = a + b;
    data = 100;                                       // A
    ready.store(true, std::memory_order_relaxed);     // B
}
void consumer()
{
    while (!ready.load(std::memory_order_relaxed))    // C
        ;
    assert(data == 100); // never failed              // D
}
int main()
{
    while (true){
        ready = false;
        data = 0;
        std::thread t1(producer);
        std::thread t2(consumer);
        t1.join();
        t2.join();
    }
    return 0;
}