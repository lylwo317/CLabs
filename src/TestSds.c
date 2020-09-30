
#include "sds.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    sds s = sdsnew("Hello sds");
    printf("sds = %s, sds.length = %zu, sds.free = %zu\n", s, sdslen(s), sdsavail(s));
    sdsfree(s);
    sds s1 = sdsempty();
    sdsfree(s1);
    sds x = sdsnew("foo"), y;
    x = sdsnewlen("\a\nfoo\r", 7);
    y = sdscatrepr(sdsempty(), x, sdslen(x));
    printf("x = %s\n", x);
    printf("y = %s\n", y);
    printf("pointer = %p", x);
    sdsfree(x);
    sdsfree(y);
    return 0;
}
