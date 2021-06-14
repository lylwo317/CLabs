//
// Created by kevin on 2021/6/14.
//
#include <iostream>

using namespace std;

double divide(int a, int b) throw(int){
    if (b == 0) {
        throw 666;
    }
    return a / b;
}

double divide(int a, int b) throw(int);


int main()
{
    try {
        double a = divide(1, 0);
    } catch (int exception) {
        cout << "exception: " << exception << endl;
    }
    return 0;
}