all:
	nasm -g -f elf64 -o stack.o stack.asm
	ld -o stack stack.o

clean:
	rm stack stack.o