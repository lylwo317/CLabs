//
// Created by kevin on 2021/6/14.
//
#include <bits/move.h>
int getSum(){
    return 10;
}
const int&& fx(){

}


int main(int argc, const char *argv[]){


    int i = 3;
    int j = 3;
    decltype(j) i2 = j;    //i2类型 int
    decltype((j)) i3 = j;  //i3类型 int&，()变成引用类型
    int &k = j;
    decltype(k+1) i4;  //i4类型 int

    decltype(fx()) i6 = 30;//i6 const int&&;

    const int &n = j;
    decltype(n) i1 = n;    //i1类型const int&

    const int * const m = &k;
    decltype(m) i5 = m;    //i5类型const int&

    return 0;
}

