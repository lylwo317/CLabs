#include <stdio.h>
#include <string.h>

static int *a;

int main(int argc, char *argv[])
{
    
    int **b = &a;
    char *hello = "hello";//编译的时候，会存在常量区，所以不能对hello修改
    char str1[] = {"TsinghuaOK"};//存在函数栈中，是局部变量，可以修改
    str1[0] = 'D';
    printf("str1 = %s \n", str1);
    // char[] helloTmp = em
    // hello[1] = '2';
    char *p = strchr(hello, 'o');
    printf("first char position: %s\n", p);
    printf("%s\n", "Hello CLab");
    return 0;
}
