#include <iostream>
#include <utility>
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
 * 可以接受左值和右值，但是由于下面的函数匹配了右值。所以这个就只会匹配左值
 * @brief copyArray
 * @param src
 */
void copyArray(const MyIntArray &src) {
    MyIntArray arr(src); // copies the array
    // use arr as needed...
}

/**
 * 精确匹配，这里接收右值
 * @brief copyArray
 * @param src
 */
void copyArray(const MyIntArray &&src) {
    MyIntArray arr(src); // copies the array
    // use arr as needed...
}

struct Person{
    int age = 10;
};

/**
 * 只能接受右值
 * @brief moveArray
 * @param src
 */
template <typename T>
void moveArray(T &&src)
{
    MyIntArray arr(std::forward<T>(src)); // moved the array
    // use arr as needed...
}

int main(int argc, char const *argv[])
{
    Person person{};
    Person *person1 = new Person{};
    int *p1 = new int[30];//未初始化
    int *p2 = new int[30]();//3个数组元素都被初始化为0，通过调用memset或者for循环设置，具体看编译器实现
    int *p3 = new int[30]{};//3个数组元素都被初始化为0，通过调用memset或者for循环设置，具体看编译器实现
    int *p4 = new int[30]{5};//数组首元素初始化为5，其它元素初始为0

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
