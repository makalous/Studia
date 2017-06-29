.align 32
.code32
#x/4wx
.data
liczba1: .long 0x10304008, 0x701100ff, 0x45100020, 0x18570030
liczba2: .long 0xf040500c, 0x00220026, 0x321000cb, 0xf4520031
liczba3: .long 0x00000000, 0x00000000, 0x00000000, 0x00000000
liczba4: .long 0x00000000

ilosc_bajtow= . - liczba1
.text
.global _start

_start:
movl $ilosc_bajtow, %eax
movl $8, %ebx
movl $0, %edx
divl %ebx
decl %eax
movl %eax, %ecx



#mov $4, %ecx
#dec %ecx
loop:
clc
 mov liczba1(,%ecx,4), %eax
 mov liczba2(,%ecx,4), %ebx
 adcl %eax, %ebx
 jc carry
 pushl %ebx
 mov %ebx, liczba3(,%ecx,4)

 dawaj:
 dec %ecx
 cmp $0, %ecx
 jge loop

 jmp koniec

 carry:
 cmp $0, %ecx
 je last_carry
 pushl %ebx
 mov %ebx, liczba3(,%ecx,4)
 dec %ecx
 mov liczba1(,%ecx,4), %eax
 inc %eax
 mov %eax, liczba1(,%ecx,4)
 pushl $1
 inc %ecx
 jmp dawaj

 last_carry:
 pushl %ebx
 pushl $1
 mov %ebx, liczba3(,%ecx,4)
 mov $1, %eax
 mov %eax, liczba4
 clc
 jmp koniec

koniec:
mov $1, %eax
mov $0, %ebx
int $0x80
