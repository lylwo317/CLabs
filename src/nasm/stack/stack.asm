section .data
   SYS_WRITE equ 1
   SYS_EXIT equ 60
   EXIT_CODE equ 0
   NEW_LINE db 0xa
   WRONG_ARGC db "Must be two command",0xa

section .text
   global _start

;rsp == argc
;rsp + 8 == arg[0]
;rsp + 16 == arg[1]

_start:
   pop rcx
   cmp rcx, 3;参数数量 = 程序名 + 参数数量
   jne .argcError
   jmp .exit
   mov rsi, [rsp + 8];arg[1]
   ret

.argcError:
   mov rax, SYS_WRITE
   mov rdi, 1; fd
   mov rsi, WRONG_ARGC; const char* msg
   mov rdx, 34; len
   syscall
   jmp .exit


.exit:
   mov rax, 60
   mov rdi, 0
   syscall