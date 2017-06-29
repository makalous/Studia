#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

void dodaj(a,b)
{
asm("movups %0,%%XMM0 \n\t"
    "movups %1,%%XMM1 \n\t"
    "addps %%XMM1,%%XMM0"	
    :
    :"g"(a) , "g"(b)
    :
);
}

void odj(a,b)
{
asm("movups %0,%%XMM0 \n\t"
    "movups %1,%%XMM1 \n\t"
    "subps %%XMM1,%%XMM0"	
    :
    :"g"(a) , "g"(b) 
    :
);
}

void mnoz(a,b)
{
asm("movups %0,%%XMM0 \n\t"
    "movups %1,%%XMM1 \n\t"
    "mulps %%XMM1,%%XMM0"	
    :
    :"g"(a) , "g"(b) 
    :
);
}

void dziel(a,b)
{
asm("movups %0,%%XMM0 \n\t"
    "movups %1,%%XMM1 \n\t"
    "divps %%XMM1,%%XMM0"	
    :
    :"g"(a) , "g"(b) 
    :
);
}

int main()
{
typedef FILE* plik;
plik fp;
fp=fopen("wynik.txt", "w");

int ile_akt=2048;
clock_t poczatek;
clock_t koniec;
double ile=0;

int tab[8192];
int i=0;
for (i=0; i<8192; i++)
{
tab[i]=rand(); 
}

//dodaj
int t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	dodaj(tab[j],tab[j+1]);
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
	odj(tab[j],tab[j+1]);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "ODEJMOWANIE:  %f \n", ile);
ile=0;


//pomnoz
t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	mnoz(tab[j],tab[j+1]);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "MNOZENIE:  %f \n", ile);
ile=0;

//dziel
t=0;
for (t=0; t<10; t=i+1)
{
poczatek=clock();
int j=0;
for (j=0; j<ile_akt; j++)
{
	dziel(tab[j],tab[j+1]);
}
koniec=clock();
ile+=((double)(koniec-poczatek))/CLOCKS_PER_SEC;
}
ile=ile/10;
fprintf (fp, "DZIELENIE:  %f \n", ile);
ile=0;

fclose(fp);
return 0;
}
