#include "alkohol.h"

class piwo:public alkohol
{
private:
	string barwa;//barwa
public:
	piwo(){}
	piwo(float c, string n,int il,float po, int p,string ko)
		: alkohol(c,n,il,po,p),barwa(ko){}
	piwo (piwo&j)
		: alkohol(j.cena,j.nazwa,j.ilosc,j.pojemnosc,j.proc),barwa(j.barwa){}
	friend ostream& operator<<(ostream& out, piwo& k){
		out <<" Cena= "<< k.cena<<" Nazwa= " << k.nazwa<<" Iloœæ= " << k.ilosc<<" Pojemnoœæ= " <<k.pojemnosc<<" Procent= " <<k.proc<<" Barwa= " <<k.barwa<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, piwo&k){
		cout << "Podaj cenê "<<endl;while(!(in>>k.cena)) {cin.clear(); cin.sync(); }
		cout << "Podaj nazwê "<<endl;while(!(in>>k.nazwa)) {cin.clear(); cin.sync(); }
		cout << "Podaj iloœæ "<<endl;while(!(in>>k.ilosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj pojemnoœæ "<<endl;while(!(in>>k.pojemnosc)) {cin.clear(); cin.sync(); }
		cout << "Podaj procent "<<endl;while(!(in>>k.proc)) {cin.clear(); cin.sync(); }
		cout << "Podaj barwê " << endl;while(!(in>>k.barwa)) {cin.clear(); cin.sync(); }
		return in;
	}
	piwo& operator=(const piwo& k)
	{
		return * this;
	}
	void wyswietl()
	{
		cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Iloœæ= " << ilosc<<" Pojemnoœæ= " <<pojemnosc<<" Procenty= " << proc<<" Barwa= " <<barwa<< endl;
	}
	virtual void szukaj (float y){
		if (cena<=y)  cout <<" Cena= "<< cena<<" Nazwa= " << nazwa<<" Iloœæ= " << ilosc<<" Pojemnoœæ= " <<pojemnosc<<" Procenty= " << proc<<" Barwa= " <<barwa<< endl;


	}
	virtual void zapis(fstream &plik){
		plik << cena<< " ";
		plik << nazwa<< " ";
		plik << ilosc<< " ";
		plik << pojemnosc<< " ";
		plik << proc<< " ";
		plik << barwa<<endl;
	}
	static void wczyt (napoj **b,int i,piwo g,fstream& plik)
	{

		plik >> g.cena;
		plik >> g.nazwa;
		plik >> g.ilosc;
		plik >> g.pojemnosc;
		plik >> g.proc;
		plik >> g.barwa;
		b[i]=new piwo (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.proc,g.barwa);
	}
	static void dodaj (napoj **b,piwo g,int m)
	{
		b[m]=new piwo (g.cena,g.nazwa,g.ilosc,g.pojemnosc,g.proc,g.barwa);
	}
};
