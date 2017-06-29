all: skrypt

skrypt: skrypt.o
	ld -m elf_i386 -o skrypt skrypt.o
skrypt.o: skrypt.s
	as --32 -g -o skrypt.o skrypt.s

clean:
	rm -f skrypt.o
	rm -f skrypt
	
