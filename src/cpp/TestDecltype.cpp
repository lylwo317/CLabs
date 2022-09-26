//
// Created by kevin on 2021/6/14.
//
#include <utility>
#include <typeinfo>
#include <string>
int getSum(){
    return 10;
}

const int && fx() {
  return 0;
}

std::string sx() {
  return "";
}

int main(int argc, const char *argv[]){


    int i = 3;
    int j = 3;

    //decltype ( entity ) 不带括号, 实体类型 T
    decltype(j) i2 = j;    //i2类型 int
    //特例1：
    //decltype ( (entity) ) 带括号, 实体类型 T&
    //通过(变量)让程序员可以获取该类型的引用类型
    decltype((j)) i3 = j;  //i3类型 int&，()变成引用类型

    int &k = j;
    decltype(k) k1 = j;  //k1类型 int&

    const int &h = j;
    decltype(h) h1 = h;  //h1类型 const int&

    // decltype ( expression ) 里面是表达式，根据表达式返回值类型确定
    //  a) if the value category of expression is xvalue, then decltype yields T&&;
    //  b) if the value category of expression is lvalue, then decltype yields T&;
    //  c) if the value category of expression is prvalue, then decltype yields T.
    decltype(fx()) i6 = 30;//i6 const int&&; 由于返回值类型是右值引用(xvalue/将亡值)，这里i6也是右值引用
    decltype((getSum())) i7 = 30;//i7 int; 表达式没有上面实体那种括号的规则。这里的返回值类型是右值(prvalue)，所以这里还是int

    int * m = &k;
    decltype(m) m1 = m;    //m1类型int*
    //特例2:
    //为什么解引用指针，得到的是引用类型？
    //因为解引用后得到指针的对象，并能向该对象赋值(也就是所谓的左值/lvalue)，这个时候只有引用类型能做到
    //否则如果是普通int类型，那就只是拷贝了。
    decltype(*m) m2 = *m;    //m2类型int&
    m2 = 30;//m也会变成30
    //decltype(*m) m2 = *m;//假如m2类型是int，之后对m2赋值并无法改变m的值

    const int * const n = &k;
    decltype(n) n1 = n;    //n1类型const int* const
    decltype(*n) n2 = *n;    //n2类型const int&，引用本身隐含了顶层const

    return 0;
}

