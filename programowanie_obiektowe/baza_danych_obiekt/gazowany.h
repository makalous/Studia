#include "napoj.h"


class gazowany: public napoj
{
private:
	bool wysnasyc;//czy wysokonasycony CO2 [wtedy 1] czy niskonasycony[wtedy 0]
public:
	gazowany(){}
	gazowany(float c, string n,int il,float po, bool w)
		:napoj(c,n,il,po), wysnasyc(w){}
	gazowany(gazowany &g)
		:napoj(g.cena,g.nazwa,g.ilosc,g.pojemnosc),wysnasyc(g.wysnasyc){}
	friend ostream& operator<<(ostream& out, gazowany& k){
		string s;
		if (k.wysnasyc==1) s="Tak"; else s="Nie";
		out <<" Cena= "<< k.cena<<" Nazwa= " << k.nazwa<<" Ilo��= " << k.ilosc<<" Pojemno��= " <<k.pojemnosc<< " Wysokonasycony CO2? " << s <<endl;
		return out;
	}
	friend istream& operator>>(istream& in, gazowany&k){
		cout << "Podaj cen� "<<endl; while(!(in>>k.cena)) {cin.clear(); cin.sync(); }
		cout << "Podaj nazw� "<<endl; while(!(in>>k.nazwa)) {cin.clear(); cin.sync(); }
		cout << "Podaj ilo�� "<<endl; while(!(in>>k.ilosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj pojemno�� "<<endl; while(!(in>>k.pojemnosc)) {cin.clear(); cin.sync(); }
		cout << "Wysokonasycony CO2?[1-tak,0-nie] "<<endl; while(!(in>>k.wysnasyc)) {cin.clear(); cin.sync(); }
		return in;
	}
	gazowany& operator=( gazowany& j)
	{
		return * this;
	}
	void wyswietl()
	{
		cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Ilo��= " << ilosc<<" Pojemno��= " <<pojemnosc<< " Wysokonasycony CO2 [1-TAK, 0-NIE]? " << wysnasyc<< endl;
	}
	virtual void szukaj (float y){
		if (cena<=y) {
			string s;
			if (wysnasyc==1) s="Tak"; else s="Nie";
			cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Ilo��= " << ilosc<<" Pojemno��= " <<pojemnosc<< " Wysokonasycony CO2? " << s<< endl;

		} 

	}
	virtual void zapis(fstream& plik){
		plik << cena<< " ";
		plik << nazwa<< " ";
		plik << ilosc<< " ";
		plik << pojemnosc<< " ";
		plik << wysnasyc<<endl;
	}
	static void wczyt (napoj **b,int i,gazowany g,fstream& plik)
	{
		plik >> g.cena;
		plik >> g.nazwa;
		plik >> g.ilosc;
		plik >> g.pojemnosc;
		plik >> g.wysnasyc;
		b[i]=new gazowany (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.wysnasyc);
	}
	static void dodaj (napoj **b,gazowany g,int m)
	{
		b[m]=new gazowany (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.wysnasyc);
	}
};
