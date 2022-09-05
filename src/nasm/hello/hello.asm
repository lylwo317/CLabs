section .data ;数据端，放常量之类的
    sys_write_code equ 1;声明常量，int sys_write_code = 1
    sys_exit_code equ 60
    msg db "hello, world!",`\n`

section .text ;代码段
    global _start

;https://filippo.io/linux-syscall-table/
_start:
    mov rax, sys_write_code;syscall table index 1 == sys_write
    mov rdi, 1;fd
    mov rsi, msg;buf
    mov rdx, 14;size_t
    syscall;syscall(long number, ...)
    ;sys_write(fd:1, const char *buf:msg, size_t: 14)

    mov rax, sys_exit_code;syscall table index 60 == sys_exit
    mov rdi, 0;
    syscall;syscall(long number, ...)
    ;sys_exit(0)
