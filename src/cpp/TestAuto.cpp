//
// Created by kevin on 2021/6/14.
//


int main()
{
    int a = 10;
    const int * const p1 = &a;
    auto p2 = p1;//const int* p2 = p1，底层const保留，顶层const去除
    const int& b = 10;
    auto c = b;//去除引用--const int c = b，去除顶层const--int c = b;
    return 0;
}