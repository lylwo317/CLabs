//
// Created by kevin on 2021/6/14.
//

// 返回值占位符
// auto不能用来声明函数的返回值，但如果函数有一个尾随的返回类型时，auto是可以出现在函数声明中返回值位置。
// 这种情况下，auto并不是告诉编译器去推断返回类型，而是指引编译器去函数的末端寻找返回值类型。
// 在下面这个例子中，函数的返回值类型就是operator+操作符作用在T1、T2类型变量上的返回值类型。
template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}

auto print() -> void
{
}

int main()
{
    int a = 10;
    const int* const p1 = &a;
    // const int* p2 = p1，底层const保留，顶层const去除
    auto p2 = p1;

    // 1. 去除引用      --  const int c = b
    // 2. 去除顶层const --  int c = b;
    const int& b = 10;
    auto c = b;
    return 0;
}