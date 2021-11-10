//
// Created by kevin on 2021/6/14.
//
#include <cstdio>

int main()
{
    int i = 0;
    /*顶层*/
    int *const p1 = &i;
    /*顶层*/
    const int ci = 42;
    /*底层*/
    const int *p2 = &ci;
    /*底层*/   /*顶层*/
    const int *const p3 = p2;
    /*底层*/
    const int &r = ci;//引用本质就是指针，所以当做指针来看就行。

    //const是顶层还是底层的区别在于

    //1. 拷贝时顶层const不受影响
    //值拷贝，拷贝操作并不会影响（改变）被拷贝对象的值。
    i = ci;
    p2 = p3;

    //2. 拷贝时底层const受影响
    //指针地址拷贝，拷贝后指向的是同一块内存区域，会影响被拷贝对象所指向的区域

    //执行拷贝操作后，如果允许有底层const拷贝给没有底层const的指针或者引用，
    //那么没有底层const的指针或者引用就可以改变原来含有底层const的指针或者引用所指向的const对象

    //p3有底层const，p没有
    //int* p = p3;//错误，如果允许这种拷贝，那么p就可以改变p3所指向的const int
    //int &r = ci;//错误，理由同上

    p2 = p3;//p2，p3都有底层const
    p2 = &i;//没有底层const的可以拷贝给含有底层const。因为i允许修改，p2不允许修改。这对i并没有什么影响
    const int & r2 = i;
    return 0;
}
