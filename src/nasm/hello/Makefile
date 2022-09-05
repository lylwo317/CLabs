all:
	nasm -g -O0 -f elf64 -o hello.o hello.asm
	ld -o hello hello.o

clean:
	rm hello hello.o