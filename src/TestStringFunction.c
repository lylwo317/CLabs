#include<string.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int r = strcmp("Hello", "HelloA");
    printf("result = %d\n",r);

    char buf[12];
    int len = snprintf(buf, sizeof(buf), "%s", "HelloWorld!");
    printf("buf[] = %s, len = %d\n", buf, len);
    return 0;
}
