#include<stdint.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int8_t i1 = 1;
    int8_t i2 = -0;
    uint8_t i3 = 255;
    for (size_t i = 0; i < 100; i++)
    {
        i3+=3;
    }

    float f1 = 0.1;

    printf("i = %d", i1);
    return 0;
}
