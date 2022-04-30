all:
	nasm -g -f elf64 -o sum.o sum.asm
	ld -o sum sum.o

clean:
	rm sum sum.o