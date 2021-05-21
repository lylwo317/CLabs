#include <iostream>
#include "student.h"
#include "MyArray.h"

using namespace std;

//左值引用: 只能绑定到左值；
//右值引用: 可以绑定到右值
//左值常量引用: 可以绑定到左值和右值

///**
// * 只能接受左值。所以不能通过copyArray(MyIntArray());来调用
// *
// * @brief copyArray
// * @param src
// */
//void copyArray(MyIntArray &src)
//{
//    MyIntArray arr(src); // copies the array
//    // use arr as needed...
//}

/**
 * 可以接受左值和右值
 * @brief copyArray
 * @param src
 */
void copyArray(const MyIntArray &src)
{
    MyIntArray arr(src); // copies the array
    // use arr as needed...
}

void moveArray(MyIntArray &&src)
{
    MyIntArray arr(std::move(src)); // moved the array
    // use arr as needed...
}

int main(int argc, char const *argv[])
{
    MyIntArray arr1(5);                // creates a new array
    MyIntArray arr2(arr1);             // copies the array
    MyIntArray arr3(std::move(arr2));  // moves the array
    MyIntArray arr4;                   // default construction
    arr4 = arr3;                       // copies the array
    arr4 = std::move(arr3);            // moves the array
    arr4 = MyIntArray(1);              // creates a new array and moves it
    copyArray(arr4);                   // copies the array
    moveArray(std::move(arr4));        // moves the array
    copyArray(MyIntArray(10));         // creates a new array and copies it
    moveArray(MyIntArray(10));         // creates a new array and moves it
    Student s("Lily");
    Student s2(s);
    Student s3 = s;
    Student s4 = std::move(s);
    return 0;
}
