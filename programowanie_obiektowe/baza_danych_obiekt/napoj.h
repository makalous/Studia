#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include <ostream>
#include <istream>
using namespace std;

class napoj{
protected:
	float cena;//Cena napoju
	string nazwa;//nazwa napoju
	int ilosc;//ilo�� 
	float pojemnosc;//pojemno�� napoju
public:
	napoj(){}
	napoj(float c, string n, int il,float po)
		: cena(c), nazwa(n),ilosc(il),pojemnosc(po){}
	napoj (napoj &t)
		: cena(t.cena), nazwa(t.nazwa),ilosc(t.ilosc),pojemnosc(t.pojemnosc){}
	friend ostream& operator<<(ostream& out, napoj& k)
	{

		cout <<" Cena= "<< k.cena<<" Nazwa= " << k.nazwa<<" Ilo��= " << k.ilosc<<" Pojemno��= " <<k.pojemnosc<< endl;
		return out;
	}
	friend istream& operator>>(istream& in, napoj&k)
	{
		cout << "Podaj cen� "<<endl; while(!(in>>k.cena)) {cin.clear(); cin.sync(); }
		cout << "Podaj nazw� "<<endl; while(!(in>>k.nazwa)) {cin.clear(); cin.sync(); }
		cout << "Podaj ilo�� "<<endl; while(!(in>>k.ilosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj pojemno�� "<<endl; while(!(in>>k.pojemnosc)) {cin.clear(); cin.sync(); }
		return in;
	}
	napoj& operator=( napoj& j)
	{
		return * this;
	}
	virtual void wyswietl()=0;
	virtual void szukaj (float y)=0;
	virtual void zapis(fstream& plik)=0;
	virtual ~napoj (){}
};