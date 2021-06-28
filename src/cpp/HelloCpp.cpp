#include <iostream>
#include <utility>
#include <set>

using namespace std;

//左值引用: 只能绑定到左值；
//右值引用: 可以绑定到右值
//左值常量引用: 可以绑定到左值和右值
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;  if (v2 < v1) return 1;  return 0;
}

int main(int argc, char const *argv[])
{
    set<int, std::less<int>> m_set = { 1, 1, 5, 3, 2, 9, 6, 7, 7 };
    for(auto& var : m_set)
    {
        cout << var << " ";
    }
    std::cout << std::endl;
    std::cout << "finish" << std::endl;
    /*Person person{};
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
    Student s4 = std::move(s);*/
    return 0;
}
