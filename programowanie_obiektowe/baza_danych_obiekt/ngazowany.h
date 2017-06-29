#include "gazowany.h"


class ngazowany: public napoj
{
private:
	int jakosc; //Jakosc wody �r�dlanej u�ytej do produkcji napoju
public: 
	ngazowany(){}
	ngazowany(float c, string n,int il,float po, int j)
		:napoj(c,n,il,po), jakosc(j){}
	ngazowany(ngazowany &g)
		:napoj(g.cena,g.nazwa,g.ilosc,g.pojemnosc),jakosc(g.jakosc){}
	friend ostream& operator<<(ostream& out, ngazowany& k){
		out <<" Cena= "<< k.cena<<" Nazwa= " << k.nazwa<<" Ilo��= " << k.ilosc<<" Pojemno��= " <<k.pojemnosc<< " Jako��= " << k.jakosc<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, ngazowany&k){
		cout << "Podaj cen� "<<endl;while(!(in>>k.cena)) {cin.clear(); cin.sync(); }
		cout << "Podaj nazw� "<<endl;while(!(in>>k.nazwa)) {cin.clear(); cin.sync(); }
		cout << "Podaj ilo�� "<<endl;while(!(in>>k.ilosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj pojemno�� "<<endl;while(!(in>>k.pojemnosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj jako�� "<<endl;while(!(in>>k.jakosc)) {cin.clear(); cin.sync(); }
		return in;
	}
	ngazowany& operator=(const ngazowany& k)
	{
		return * this;
	}
	void wyswietl()
	{
		cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Ilo��= " << ilosc<<" Pojemno��= " <<pojemnosc<<" Jakosc= " << jakosc<< endl;
	}
	virtual void szukaj (float y){
		if (cena<=y)  cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Ilo��= " << ilosc<<" Pojemno��= " <<pojemnosc<<" Jakosc= " << jakosc<< endl;


	}
	virtual void zapis(fstream &plik){
		plik << cena<< " ";
		plik << nazwa<< " ";
		plik << ilosc<< " ";
		plik << pojemnosc<< " ";
		plik << jakosc<<endl;
	}	
	static void wczyt (napoj **b,int i,ngazowany g,fstream& plik)
	{
		plik >> g.cena;
		plik >> g.nazwa;
		plik >> g.ilosc;
		plik >> g.pojemnosc;
		plik >> g.jakosc;
		b[i]=new ngazowany (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.jakosc);
	}
	static void dodaj (napoj **b,ngazowany g,int m)
	{
		b[m]=new ngazowany (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.jakosc);
	}

};
