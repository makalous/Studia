#include "plecakowy.h"
#include "Stoper.h"
		//Stoper stj;
		//stj.Start();
		//if(stj.Stop()>=5000) break;

int main()
{
	

	/*Plecak p;
	p.wczytajPlecak(); 
	p.Sort(); 
	p.wyswietlPlecak();
	cout<< "Wprowadz pojemnosc plecaka"<<endl;
	int pok;
	cin>>pok;
	p.dynamina(pok);
	cout<<endl;
	p.bb(pok);
	system("pause");*/

	Plecak p;
	p.wczytajPlecak(); 
	p.Sort2(); 
	p.wyswietlPlecak();
	cout<< "Wprowadz pojemnosc plecaka"<<endl;
	int pok;
	cin>>pok;
	cout<< "Wprowadz epsilon "<<endl;
	float pok1;
	cin>>pok1;
	p.tas(pok,pok1);

	//p.Sort();
	//p.dynamina(pok);
	//p.bb(pok);
	system("pause");
	//http://www.asdpb.republika.pl/wyk78.pdf//
	
	
	


	
	/*Stoper fg;
	Plecak p;
	double suma=0;

	for (int i=0;i<100;i++)
	{
	p.wygenerujPlecak(65,20); //liczba przedmiotów / max objetosc przedmiotu
	p.Sort2();

	fg.Start();
	p.tas(140,01);
	fg.Stop();

	suma+=fg.Stop();
	
	}
	suma=suma/100;
	cout <<endl<<"*** "<< suma <<endl;

	system("pause");*/

	/*Plecak p;
	//p.wczytajPlecak();
	p.wygenerujPlecak(125,20); //liczba przedmiotów / max objetosc przedmiotu
	p.Sort();
	int b=p.dynamina(50);
	cout << b<<endl;

	p.Sort2();
	float a=p.tas(50,0.1);
	cout << a<<endl;

	cout << "BLAD: " << (a-b)/b << endl;

	system("pause");*/
	

}