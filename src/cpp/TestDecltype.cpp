//
// Created by kevin on 2021/6/14.
//
#include <bits/move.h>
#include <typeinfo>
int getSum(){
    return 10;
}
const int&& fx(){

}

class Person{
private:
    int age = 0;
public:
    int getAge(){
        return age;
    }
};


int main(int argc, const char *argv[]){


    int i = 3;
    int j = 3;
    decltype(j) i2 = j;    //i2类型 int
    //特例1：
    //通过(变量)让程序员可以获取该类型的引用类型
    decltype((j)) i3 = j;  //i3类型 int&，()变成引用类型

    int &k = j;
    decltype(k) k1 = j;  //k1类型 int&

    const int &h = j;
    decltype(h) h1 = h;  //h1类型 const int&

    decltype(fx()) i6 = 30;//i6 const int&&;
    decltype((getSum())) i7 = 30;//i7 int;

    int * m = &k;
    decltype(m) m1 = m;    //m1类型int*
    //特例2:
    //为什么解引用指针，得到的是引用类型？
    //因为解引用后得到指针的对象，并能向该对象赋值，这个时候只有引用类型能做到
    //否则如果是普通int类型，那就只是拷贝了。
    decltype(*m) m2 = *m;    //m2类型int&
    m2 = 30;//m也会变成30
    //decltype(*m) m2 = *m;//假如m2类型是int，之后对m2赋值并无法改变m的值

    const int * const n = &k;
    decltype(n) n1 = n;    //n1类型const int* const
    decltype(*n) n2 = *n;    //n2类型const int&，引用本身隐含了顶层const

    return 0;
}

