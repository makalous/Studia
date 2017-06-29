#include "piwo.h"
#include <string>

using namespace std;
int main ()
{
	setlocale (LC_ALL, "");//polskie znaki

	int roz;
	cout << "Jak du¿a ma byæ baza?" <<endl;
	while(!(cin>>roz)) 
	{

		cin.clear(); 
		cin.sync(); 
	}

	napoj **b=new napoj *[roz];
	for (int i=0;i<roz;i++) b[i]=NULL;

	int opcja=2;

	do
	//MENU START
	{

		system("cls");//czyœci ekran przy ka¿dym kolejnym wyœwietleniu menu

		cout << endl << endl<<endl;
		cout <<" HURTOWNIA NAPOJÓW " <<endl<<endl<<endl;
		cout << "1. Dodaj do bazy" << endl;
		cout << "2. Usuñ z bazy" << endl;
		cout << "3. Wczytaj bazê" << endl;
		cout << "4. Zapisz bazê" << endl;
		cout << "5. Wyswietl" << endl;
		cout << "6. Wyszukaj" << endl<<endl;
		cout << "7. Koniec"<< endl;

		int znak;
		while(!(cin>>znak)) 
		{

			cin.clear(); 
			cin.sync(); 
		}

		if (znak!=1&&znak!=2&&znak!=3&&znak!=4&&znak!=5&&znak!=6&&znak!=7) {cout << "Z³a cyfra" <<endl; continue;}

		switch(znak)
		{
			//CASE1:DODAWANIE DO BAZY
		case 1:
			{
				system("cls");
				cout << "Jaki napój chcesz dodaæ?"<<endl;
				cout << "1.Gazowany"<<endl<<"2.Alkohol"<<endl<<"3.Niegazowany"<<endl;
				int w;
				while(!(cin>>w)) 
				{

					cin.clear(); 
					cin.sync(); 
				}
				if (w!=1&&w!=2&&w!=3) {cout << "Z³a cyfra. Wyrzucam do ekranu g³ównego" <<endl; continue;}
				switch (w)
				{
				case 1:
					{
						system("cls");
						gazowany g;
						cin >> g;
						cout << "Na jakie miejsce dodaæ napój?"<<endl;
						int m;
						cin >> m;
						gazowany::dodaj(b,g,m);
						cout<<"Napój dodany poprawnie"<<endl;
						break;
					}
				case 2:
					{
						system("cls");
						int u;
						cout << "1. Alkohol wysokoprocentowy" <<"	" << "2. Piwo" << endl;
						while(!(cin>>u)) 
						{

							cin.clear(); 
							cin.sync(); 
						}
						if (u!=1&&u!=2) {cout << "Z³a cyfra. Wyrzucam do ekranu g³ównego" <<endl; continue;}
						switch (u)
						{
						case 1:
							{
								system("cls");
								alkohol g;
								cin >> g;
								cout << "Na jakie miejsce dodaæ napój?"<<endl;
								int m;
								cin >> m;
								alkohol::dodaj(b,g,m);
								cout<<"Napój dodany poprawnie"<<endl;
								break;
							}
						case 2:
							{
								system("cls");
								piwo g;
								cin >> g;
								cout << "Na jakie miejsce dodaæ napój?"<<endl;
								int m;
								cin >> m;
								piwo::dodaj(b,g,m);
								cout<<"Napój dodany poprawnie"<<endl;
								break;}
						}
						break;
					}
				case 3:
					{
						system("cls");
						ngazowany g;
						cin >> g;
						cout << "Na jakie miejsce dodaæ napój?"<<endl;
						int m;
						cin >> m;
						ngazowany::dodaj(b,g,m);
						cout<<"Napój dodany poprawnie"<<endl;
						break;
					}

				}
				system ("pause");
				break;
			}
			//CASE2:USUWANIE Z BAZY
		case 2:
			{
				system("cls");
				cout << "Ktore miejsce chcesz usun¹æ?"<<endl;
				int w;
				while(!(cin>>w)) 
				{

					cin.clear(); 
					cin.sync(); 
				}
				delete b[w];
				for (int i=w;i<roz-1;i++) (b)[i]=(b)[i+1];
				b[roz-1]=NULL;
				cout << "Napój usuniêty poprawnie" << endl;
				system ("pause");
				break;
			}
			//CASE3:WCZYTYWANIE DO BAZY
		case 3:
			{
				system("cls");
				for (int i=0;i<roz;i++) delete b[i];
				delete [] b;

				int roz1;
				cout << "Ile miejsc posiada wczytywana baza ?" <<endl;
				while(!(cin>>roz1)) 
				{

					cin.clear(); 
					cin.sync(); 
				}

				napoj **b=new napoj *[roz1];
				for (int i=0;i<roz1;i++) b[i]=NULL;

				cout << "Jaka nazwa wczytywanego pliku [musi siê koñczyæ na .txt oraz byæ w katalogu programu]" << endl;
				string nasfa;
				cin >> nasfa;
				fstream plik;
				plik.open(nasfa);

				gazowany g;ngazowany ng;alkohol al;piwo pi;

				for (int i=0;i<roz1;i++)
				{
					string n0="";
					string n1="";
					plik >> n0; plik >> n1;
					if (n1=="gazowany"||n1=="ngazowany"||n1=="alkohol"||n1=="piwo")
					{
						if (n1=="gazowany"){gazowany::wczyt(b,i,g,plik);}
						if (n1=="ngazowany"){ngazowany::wczyt(b,i,ng,plik);}
						if (n1=="alkohol"){alkohol::wczyt(b,i,al,plik);}
						if (n1=="piwo"){piwo::wczyt(b,i,pi,plik);}
					}
					else continue;
				}

				plik.close();
				cout << "Plik wczytany" << endl;
				roz=roz1;


				system ("pause");
				break;
			}
			//CASE4:ZAPISYWANIE DO BAZY
		case 4:
			{
				system("cls");
				cout << "Plik zostanie zapisany do BazaZapisana.txt" << endl;

				FILE *k;
				k=fopen("BazaZapisana.txt", "w+t");
				fstream plik;
				plik.open("BazaZapisana.txt");
				for (int i=0;i<roz;i++){if (b[i] != NULL){plik << typeid(*(b[i])).name() << " ";
				b[i]->zapis(plik);}}
				plik.close();
				fclose(k);
				cout << "Plik zostal zapisany!"<<endl;
				system ("pause");
				break;

			}
			//CASE5:WYSWIETLANIE
		case 5:
			{
				system("cls");
				for (int i=0;i<roz;i++)
				{
					if ((b)[i]!=NULL)
					{
						(b)[i]->wyswietl();
					}
				}

				system ("pause");
				break;
			}
			//CASE6:SZUKANIE PO CENIE
		case 6:
			{
				system("cls");
				cout << "Podaj cenê maksymaln¹ produktu" << endl;
				float c;
				cin >> c;
				for (int i=0;i<roz;i++)
				{
					if (b[i] != NULL)
					{

						b[i]->szukaj(c);

					}

				}
				system ("pause");
				break;
			}
			//CASE7:KONIEC PROGRAMU
		case 7:
			{
				system("cls");
				cout << "Czy na pewno chcesz wyjœæ?" << endl;
				cout << "1-Tak		2-Nie" << endl;
				int u;
				while(!(cin>>u)) 
				{

					cin.clear(); 
					cin.sync(); 
				}
				if (u!=1&&u!=2) {cout << "Z³a cyfra. Wyrzucam do ekranu g³ównego" <<endl; continue;}
				if (u==1){
					opcja=0;delete [] b;}
				if (u==2) continue;
			}

		}
	}
	while (opcja);
	cout << "KONIEC"<<endl;
	system ("pause");
}