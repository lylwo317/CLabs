#include <stdio.h>
#include <string.h>

static int *a;
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))

int add(int* a, int* b){

}

int main(int argc, char *argv[])
{

    add(10, 20);
    int **b = &a;
    char *hello = "hello";//编译的时候，会存在常量区，所以不能对hello修改
    char str1[] = {"TsinghuaOK"};//存在函数栈中，是局部变量，可以修改
    printf("%d\n" , FF_ARRAY_ELEMS(str1));
    str1[0] = 'D';
    printf("str1 = %s \n", str1);
    // char[] helloTmp = em
    // hello[1] = '2';
    char *p = strchr(hello, 'o');
    printf("first char position: %s\n", p);
    printf("%s\n", "Hello CLab");
    printf("%s\n", 1 ? "true":"false");
    if (-1) {
        printf("%s\n", "true");
    } else {
        printf("%s\n", "false");
    }
    return 0;
}
