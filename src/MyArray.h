//
// Created by kevin on 2021/5/13.
//

#ifndef CLABS_MYARRAY_H
#define CLABS_MYARRAY_H


#include <algorithm>

class MyIntArray
{
private:
    int *arr = nullptr;
    int size = 0;

public:
    MyIntArray() = default;

    MyIntArray(int size) {
        arr = new int[size];
        this->size = size;
        for(int i = 0; i < size; ++i) {
            arr[i] = i;
        }
    }

    // copy constructor
    MyIntArray(const MyIntArray &src) {
        // allocate a new copy of the array...
        arr = new int[src.size];
        size = src.size;
        for(int i = 0; i < src.size; ++i) {
            arr[i] = src.arr[i];
        }
    }

    // move constructor
    MyIntArray(MyIntArray &&src) {
        // just swap the array pointers...
        src.swap(*this);
    }

    ~MyIntArray() {
        delete[] arr;
    }

    // copy assignment operator
    MyIntArray& operator=(const MyIntArray &rhs) {
        if (&rhs != this) {
            MyIntArray temp(rhs); // copies the array
            temp.swap(*this);
        }
        return *this;
    }

    // move assignment operator
    MyIntArray& operator=(MyIntArray &&rhs) {
        MyIntArray temp(std::move(rhs)); // moves the array
        temp.swap(*this);
        return *this;
    }

    /*
    or, the above 2 operators can be implemented as 1 operator, like below.
    This allows the caller to decide whether to construct the rhs parameter
    using its copy constructor or move constructor...

    MyIntArray& operator=(MyIntArray rhs) {
        rhs.swap(*this);
        return *this;
    }
    */

    void swap(MyIntArray &other) {
        // swap the array pointers...
        std::swap(arr, other.arr);
        std::swap(size, other.size);
    }
};

#endif //CLABS_MYARRAY_H
