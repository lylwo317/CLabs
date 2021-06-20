//
// Created by kevin on 2021/6/19.
//
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using std::vector;
using std::string;

template <typename It>
auto fcn(It beg) -> decltype(*beg){////如何查看这个类型呢？其实在return那里返回错误类型就行，这个时候编译器会报错，并告诉你decltype(*beg)的类型是什么
    return *beg;
}
template <typename It>
auto fcnCopy(It beg) -> typename std::remove_reference<decltype(*beg)>::type{
    return *beg;
}

void testDecltype(){
    vector<int> a = {1,2,3,4};
    auto it = a.begin();
    fcn(it);
    fcnCopy(it);
}

template <typename T>
int compare(T && a, T&& b){
    return 0;
}

//template <typename T>
//int compare(T &a, T&b){
//    return 0;
//}
template <>//函数特例化，要声明一个空的<>
inline
int compare(const char* const &v1, const char* const &v2)//填充实参类型
{
    return std::strcmp(v1, v2);
}

void testRef(){
    const int a = 1;
    const int b = 2;

    int c = 23;

    compare(a,b);
    compare(c,c);
    //compare(12,34);
}

template<typename T, typename ... Args>
void foo(const T &t, const Args &...rest){
    printf("sizeof...(Args) = %lu \n", sizeof...(Args));//类型参数的数量
    printf("sizeof...(rest) = %lu \n", sizeof...(rest));//函数参数的数量
    printf("\n");
}

template<typename T>
std::ostream &print(std::ostream &os, const T &t){
    return os << t;
}

template <typename T, typename... Args>
std::ostream &
print(std::ostream &os, const T &t, const Args&... rest)//expand Args
{
    os << t << ", ";
    return print(os, rest...);                     //expand rest
}

void testMultiArgs(){
    int i = 0;
    double d = 3.14;
    string s = "hello";
    string s1 = "world";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");

    int a = 10;
    double  b = 23.3;
    print(std::cout, "hello", a, b);
}

//第1个版本，通用，适配所有类型
template<typename _Tp>
struct remove_reference {
    typedef _Tp type;
};

//第2个版本，偏特化，适配左值引用
template<typename _Tp>
struct remove_reference<_Tp&>
{
    typedef _Tp type;
};

//第3个版本，偏特化，适配右值引用
template<typename _Tp>
struct remove_reference<_Tp&&>
{
    typedef _Tp   type;
};


void testPartialSpecialization(){
    int i = 23;
    remove_reference<decltype(42)>::type a = 43;//int，匹配第一个版本
    remove_reference<decltype((i))>::type b = 53;//int&，匹配第二个版本
    remove_reference<decltype(std::move(i))>::type c = 45;//int&&, 匹配第三个版本
}


int main(int argc, const char * argv[]){
//    testDecltype();
//    testRef();
//    testMultiArgs();
    return 0;
}

