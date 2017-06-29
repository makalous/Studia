all: skrypt

skrypt: skrypt.o
	ld -o skrypt skrypt.o
skrypt.o: skrypt.s
	as -g -o skrypt.o skrypt.s

