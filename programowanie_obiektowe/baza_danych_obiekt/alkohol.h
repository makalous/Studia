#include "ngazowany.h"

class alkohol: public napoj
{
protected:
	int proc;//procentowosc alkoholu
public:
	alkohol(){}
	alkohol(float c, string n,int il,float po, int p)
		: napoj(c,n,il,po), proc(p){}
	alkohol(alkohol &j)
		: napoj(j.cena,j.nazwa,j.ilosc,j.pojemnosc), proc(j.proc){}
	friend ostream& operator<<(ostream& out, alkohol& k){
		out <<" Cena= "<< k.cena<<" Nazwa= " << k.nazwa<<" Iloœæ= " << k.ilosc<<" Pojemnoœæ= " <<k.pojemnosc<<" Procent= " <<k.proc<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, alkohol&k){
		cout << "Podaj cenê "<<endl;while(!(in>>k.cena)) {cin.clear(); cin.sync(); }
		cout << "Podaj nazwê "<<endl;while(!(in>>k.nazwa)) {cin.clear(); cin.sync(); }
		cout << "Podaj iloœæ "<<endl;while(!(in>>k.ilosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj pojemnoœæ "<<endl;while(!(in>>k.pojemnosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj procent "<<endl;while(!(in>>k.proc)) {cin.clear(); cin.sync(); }
		return in;
	}
	alkohol& operator=(const alkohol& k)
	{
		return * this;
	}
	void wyswietl()
	{
		cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Iloœæ= " << ilosc<<" Pojemnoœæ= " <<pojemnosc<<" Procenty= " << proc<< endl;
	}
	virtual void szukaj (float y){
		if (cena<=y)  cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Iloœæ= " << ilosc<<" Pojemnoœæ= " <<pojemnosc<<" Procenty= " << proc<< endl;


	}
	virtual void zapis(fstream& plik){
		plik << cena<< " ";
		plik << nazwa<< " ";
		plik << ilosc<< " ";
		plik << pojemnosc<< " ";
		plik << proc<<endl;
	}
	static void wczyt (napoj **b,int i,alkohol g,fstream& plik)
	{

		plik >> g.cena;
		plik >> g.nazwa;
		plik >> g.ilosc;
		plik >> g.pojemnosc;
		plik >> g.proc;
		b[i]=new alkohol (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.proc);
	}
	static void dodaj (napoj **b,alkohol g,int m)
	{
		b[m]=new alkohol (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.proc);
	}

};