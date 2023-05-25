#include <stdio.h>

extern int getVal();
// the definition of func is written in assembly language
__asm__(".globl getVal\n\t"
        ".type getVal, @function\n\t"
        "getVal:\n\t"
        ".cfi_startproc\n\t"
        "movl $7, %eax\n\t"
        "ret\n\t"
        ".cfi_endproc");

int main(void)
{
    int n = getVal();
    // gcc's extended inline assembly
    __asm__("leal (%0,%0,4),%0"
            : "=r"(n)
            : "0"(n));
    printf("7*5 = %d\n", n);
    fflush(stdout); // flush is intentional

    // standard inline assembly in C++
    __asm__("movq $60, %rax\n\t" // the exit syscall number on Linux
            "movq $2,  %rdi\n\t" // this program returns 2
            "syscall");
}