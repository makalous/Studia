#include<stdio.h>

typedef struct wiersz
{
float w,z,y,x;
} wiersz;

void druk(wiersz* wiersz)
{
printf("\n %f %f %f %f",wiersz->x,wiersz->y,wiersz->z,wiersz->w);
}

int main()
{
float det=0;
wiersz A, B, C, D;

A.x=2;
A.y=2;
A.z=2;
A.w=3;

B.x=2;
B.y=2;
B.z=3;
B.w=2;


C.x=2;
C.y=3;
C.z=2;
C.w=2;


D.x=3;
D.y=2;
D.z=2;
D.w=2;
float returno1[4];
float returno2[4];
asm(
		 "movaps (%%rax), %%xmm0 \n\t"
		"shufps $0xDE,%%xmm0,%%xmm0 \n\t"
		"movaps (%%rbx), %%xmm1 \n\t"
		"shufps $0xB1,%%xmm1,%%xmm1 \n\t"
		"mulps %%xmm1,%%xmm0 \n\t"

		 "movaps (%%rax), %%xmm1 \n\t"
		"shufps $0xB1,%%xmm1,%%xmm1 \n\t"
		 "movaps (%%rbx), %%xmm2 \n\t"
		"shufps $0xDE,%%xmm2,%%xmm2 \n\t"
		"mulps %%xmm2,%%xmm1 \n\t"

		"subps %%xmm1,%%xmm0 \n\t"
////////////////////////////////////////////////////////////////////
		"movaps (%%rcx), %%xmm1 \n\t"
		"shufps $0x6B,%%xmm1,%%xmm1 \n\t"
		"movaps (%%rdx), %%xmm2 \n\t"
		"shufps $0x4,%%xmm2,%%xmm2 \n\t"
		"mulps %%xmm2,%%xmm1 \n\t"

		 "movaps (%%rcx), %%xmm2 \n\t"
		"shufps $0x4,%%xmm2,%%xmm2 \n\t"
		 "movaps (%%rdx), %%xmm3 \n\t"
		"shufps $0x6B,%%xmm3,%%xmm3 \n\t"
		"mulps %%xmm3,%%xmm2 \n\t"

		"subps %%xmm2,%%xmm1 \n\t"
/////////////////////////////////////////////////////////////
		 "movaps (%%rax), %%xmm2 \n\t"
		"shufps $0x40,%%xmm2,%%xmm2 \n\t"
		"movaps (%%rbx), %%xmm3 \n\t"
		"shufps $0x20,%%xmm3,%%xmm3 \n\t"
		"mulps %%xmm3,%%xmm2 \n\t"

		 "movaps (%%rax), %%xmm3 \n\t"
		"shufps $0x20,%%xmm3,%%xmm3 \n\t"
		 "movaps (%%rbx), %%xmm4 \n\t"
		"shufps $0x40,%%xmm4,%%xmm4 \n\t"
		"mulps %%xmm4,%%xmm3 \n\t"

		"subps %%xmm3,%%xmm2 \n\t"
////////////////////////////////////////////////////////
		"movaps (%%rcx), %%xmm3 \n\t"
		"shufps $0xF0,%%xmm3,%%xmm3 \n\t"
		"movaps (%%rdx), %%xmm4 \n\t"
		"shufps $0x90,%%xmm4,%%xmm4 \n\t"
		"mulps %%xmm4,%%xmm3 \n\t"

		 "movaps (%%rcx), %%xmm4 \n\t"
		"shufps $0x90,%%xmm4,%%xmm4 \n\t"
		 "movaps (%%rdx), %%xmm5 \n\t"
		"shufps $0xF0,%%xmm5,%%xmm5 \n\t"
		"mulps %%xmm5,%%xmm4 \n\t"

		"subps %%xmm4,%%xmm3 \n\t"
////////////////////////////////////////////////////////////////
		"mulps %%xmm1,%%xmm0 \n\t"
		"mulps %%xmm3,%%xmm2 \n\t"
		"movups %%xmm0, (%4)         \n\t"
		"movups %%xmm2, (%5)         \n\t"
		
   		 : 			
   		 :"a"(&A), "b"(&B), "c"(&C), "d"(&D),"r"(returno1), "r"(returno2)
		

);


druk (returno1);
printf ("\n");
druk (returno2);
printf ("\n");

for (int i=0; i<4; i++)
{
det+=returno1[i];
det+=returno2[i];
}
printf ("Wyznacznik: %f", det);
printf ("\n");

getchar();
return 0;
}

