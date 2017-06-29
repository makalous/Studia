#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
typedef struct wektor {   
    float x, y, z, w;       
} wektor;

//aaddps - 4floats, pd-2double
//movups - przenies adres nie musi byc wyrownany
void dodaj(wektor a, wektor b){
asm("movl %0, %%eax\n\t"
    "movl %1, %%ebx\n\t "
    "movups (%%eax),%%XMM0\n\t "
    "movups (%%ebx),%%XMM1\n\t"
    "addps %%XMM1,%%XMM0"
    :
    :"g"(a) , "g"(b) 
    :"%eax","%ebx"
);
}

void odj(wektor a, wektor b){
asm("movl %0, %%eax\n\t" 
    "movl %1, %%ebx\n\t" 
    "movups (%%eax),%%XMM0\n\t" 
    "movups (%%ebx),%%XMM1\n\t" 
    "subps %%XMM1,%%XMM0" 
    :
    :"g"(a) , "g"(b) 
    :"%eax","%ebx"
);
}

void mnoz(wektor a, wektor b){
asm("movl %0, %%eax\n\t" 
    "movl %1, %%ebx\n\t" 
    "movups (%%eax),%%XMM0\n\t"
    "movups (%%ebx),%%XMM1\n\t" 
    "mulps %%XMM1,%%XMM0" 
    :
    :"g"(a) , "g"(b) 
    :"%eax","%ebx"
);
}

void dziel(wektor a, wektor b){
asm("movl %0, %%eax\n\t" 
    "movl %1, %%ebx\n\t"
    "movups (%%eax),%%XMM0\n\t" 
    "movups (%%ebx),%%XMM1\n\t" 
    "divps %%XMM1,%%XMM0" 
    :
    :"g"(a) , "g"(b) 
    :"%eax","%ebx"
);
}
wektor zapelnij(float x,float y,float z,float w) 
{
    wektor a = {x,y,z,w};
    return a;
}
int main()
{
//Zmienne
wektor tab[8192];
int i=0;
for (i=0; i<8192; i=i+1)
{
tab[i].x=rand();
tab[i].y=rand();
tab[i].z=rand();
tab[i].w=rand();
}

typedef FILE* plik;
plik fp;
fp=fopen("wynik.txt", "w");

int ile_akt=8192;
clock_t poczatek;
clock_t koniec;
double ile=0;

//dodaj
int t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	wektor a1=zapelnij(tab[j].x, tab[j].y, tab[j].z, tab[j].w);
	wektor b1=zapelnij(tab[j+1].x, tab[j+1].y, tab[j+1].z, tab[j+1].w);
	dodaj(a1,b1);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "DODAWANIE:  %f \n", ile);
ile=0;

//odejmij
t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	wektor a1=zapelnij(tab[j].x, tab[j].y, tab[j].z, tab[j].w);
	wektor b1=zapelnij(tab[j+1].x, tab[j+1].y, tab[j+1].z, tab[j+1].w);
	odj(a1,b1);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "ODEJMOWANIE:  %f \n", ile);
ile=0;

//mnozenie
t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	wektor a1=zapelnij(tab[j].x, tab[j].y, tab[j].z, tab[j].w);
	wektor b1=zapelnij(tab[j+1].x, tab[j+1].y, tab[j+1].z, tab[j+1].w);
	mnoz(a1,b1);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "MNOZENIE:  %f \n", ile);
ile=0;


//dzielenie
t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	wektor a1=zapelnij(tab[j].x, tab[j].y, tab[j].z, tab[j].w);
	wektor b1=zapelnij(tab[j+1].x, tab[j+1].y, tab[j+1].z, tab[j+1].w);
	dziel(a1,b1);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "DZIELENIE:  %f \n", ile);
ile=0;
fclose (fp);
 
return 0;
}
