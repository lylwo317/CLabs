//
// Created by kevin on 2022/4/24.
//

#ifndef CLABS_TESTINLINEA_H
#define CLABS_TESTINLINEA_H
class A
{
public:
    /**
     * @brief 类中定义了的函数是隐式内联函数,声明要想成为内联函数，必须在实现处(定义处)加inline关键字。
     *
     * @param x
     * @param y
     */
    int Foo(int x,int y) ///< 定义即隐式内联函数！
    {
        int z = x + y;
        return z;
    };

    int f1(int x);
    ///< 声明后，要想成为内联函数，必须在定义处加inline关键字。
    ///< 但是如果是在TestInlineA.cpp中添加，就会报错了。因为内联函数不需要链接，也就是链接时是找不到的
};

inline int A::f1(int x) {
    return x*100;
}

#endif //CLABS_TESTINLINEA_H
