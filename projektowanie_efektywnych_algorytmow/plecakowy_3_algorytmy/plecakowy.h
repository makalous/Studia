#include "b.h"
#include "Stoper.h"
#include <limits.h>

struct OB
{
	int obj; // objêtosc
	int war; // wartosc
	OB(){obj=0;war=0;}
};

struct node
{
	int benefit;//wartosc
	int weight;//waga
	int ub; //ograniczenkie
	int level;//poziom
	bool *sek;//sekwencja - bierzemy/nie bierzemy

	node()
	{
		benefit=0;
		weight=0;
		ub=0;
		level=0;
		sek=NULL;
	}
};


class Plecak
{
private:
	int ele;			//A liczba elementów
	int poje;			//B pojemnoœæ plecaka
	OB *pom;			// objêtoœci i wartoœci - tablica struktur


public:
	Plecak(){ele=0;poje=0;pom=NULL;}
	~Plecak(){}

	void Sort()
	{
		int tmp, zmiana;
		int *tab = new int [ele];
		int *c1 = new int[ele];
		for (int x=0;x<ele;x++)
		{
			c1[x]=x;
			tab[x]=(pom[x].war)/(pom[x].obj);
		}
		for (int i = 0; i < ele; i++)
		{
			zmiana = 0; 
			for (int j = 0; j < ele-1-i; j++) 
			{
				if (tab[j] < tab[j+1])
				{
					tmp = tab[j];
					tab[j] = tab[j+1];
					tab[j+1] = tmp;

					tmp = c1[j];
					c1[j] = c1[j+1];
					c1[j+1] = tmp;

					tmp = pom[j].obj;
					pom[j].obj = pom[j+1].obj;
					pom[j+1].obj = tmp;
					tmp = pom[j].war;
					pom[j].war = pom[j+1].war;
					pom[j+1].war = tmp;

					zmiana = 1;       
				}
			}
			if(!zmiana) break;
		}


	}
	void wyswietlPlecak()		
	{
		cout << " Oto ilosc przedmiotow:  "<< ele << endl;
		cout<< "PRZEDMIOTY S¥ POSORTOWANE" << endl;
		cout<<"---NUMER---"<<"        " << "---OBJETOSC---" << "        " << "---WARTOSC---" << endl;
		for (int i = 0; i < ele; i++)
		{

			cout <<i<<"                   "<<pom[i].obj << "                         " << pom[i].war << endl; 

		}

	}							
	void wczytajPlecak()
	{
		ifstream plik;
		string nazwa; //nazwa pliku z ktorego wczytujemy
		do
		{
			cout << "\nPodaj nazwe pliku z ktorego mam pobrac dane(musi konczyc sie na .txt i byc w katalogu programu): ";
			cin >> nazwa;
			plik.open(nazwa);
		} 
		while (!plik.good()); //dopoki nie uda sie wczytac pliku powtarza

		int a,b;
		plik >> a; // wczytana liczba elementów
		ele = a;


		OB *chwilowa = new OB[a];
		pom=chwilowa;

		for (int i=0;i<a;i++)
		{
			plik >> b;
			chwilowa[i].obj=b;

			plik>> b;
			chwilowa[i].war=b;

		}
		cout << "\nWczytalem z pliku\n";
		plik.close();
	}	
	int F_ub(int M,node p1,int j)
	{
		float x1=0;
		int wynik;
		node p;
		p.benefit=p1.benefit;
		p.weight=p1.weight;
		int d=j-1;
		if (p.weight>M)
		{
			p.benefit=p.benefit-pom[d].war;
			p.weight=p.weight-pom[d].obj;
			x1=(M-p.weight);
			x1=x1/pom[d].obj;
			wynik=p.benefit+(x1*pom[d].war);
			return wynik;
		}
		else
		{
			if(j==ele){return p.benefit;}
			else
			{
				for (int i=j;i<ele;i++)
				{
					p.benefit=p.benefit+pom[i].war;
					p.weight=p.weight+pom[i].obj;

					if (p.weight>M)
					{	
						p.benefit=p.benefit-pom[i].war;
						p.weight=p.weight-pom[i].obj;
						x1=(M-p.weight);
						x1=x1/pom[i].obj;
						wynik=p.benefit+(x1*pom[i].war);
						return wynik;
						break;
					}

					if(i==ele-1) {return p.benefit;break;}

				}
			}
		}

	}
	void wygenerujPlecak(int O, int M) //ilosc przedmiotot/pojemnosc plecaka
	{
		if (O > 1 && M > 0)
		{
			ele = O;			//przypisujemy iloœæ obiektów
			poje = M;			//przypisujemy wagê plecaka

			float wspWagi;			//do spe³nienia warunku ¿e sumaryczna waga wszystkich przedmiotów musi byæ wiêksza od pojemnoœci plecaka
			unsigned int korektaBezpieczenstwa = 1;	//korekta od jakiego pu³apu zacz¹æ losowanie
			unsigned int sumaKontrolna = 0;		//suma wag wszystkich przedmiotów
			unsigned int zakresMax = poje;			//wartoœæ do jakiej liczby maj¹ byæ losowane wartoœci

			if (pom != nullptr)		delete[] pom;		//usuwamy stare wartoœci o ile by³y
			pom = new OB[ele];				//tworzymy now¹ tablicê struktur

			wspWagi = ((float)ele/poje);		//obliczamy stosunek liczby elementów do pojemnoœci plecaka

			if (wspWagi < 1.25)				//jeœli jest on mniejsza od 125% to
			{
				korektaBezpieczenstwa = (int)ceil(((float)poje + (float)poje*0.25)/ele);	//ka¿dy element powinien byæ wiêkszy/równy tej wartoœci
				zakresMax = poje - korektaBezpieczenstwa;							//ka¿dy element powinien byæ mniejszy równy tej wartoœci
			}

			for (int i = 0; i < ele; i++)
			{
				pom[i].obj = (rand() % zakresMax + korektaBezpieczenstwa);	
				pom[i].war = (rand() % 150 + 1);
			}
		}
	}
	void Sort2()
	{
		int tmp, zmiana;
		int *tab = new int [ele];
		int *c1 = new int[ele];
		for (int x=0;x<ele;x++)
		{
			c1[x]=x;
			tab[x]=(pom[x].war);
		}
		for (int i = 0; i < ele; i++)
		{
			zmiana = 0; 
			for (int j = 0; j < ele-1-i; j++) 
			{
				if (tab[j] < tab[j+1])
				{
					tmp = tab[j];
					tab[j] = tab[j+1];
					tab[j+1] = tmp;

					tmp = c1[j];
					c1[j] = c1[j+1];
					c1[j+1] = tmp;

					tmp = pom[j].obj;
					pom[j].obj = pom[j+1].obj;
					pom[j+1].obj = tmp;
					tmp = pom[j].war;
					pom[j].war = pom[j+1].war;
					pom[j+1].war = tmp;

					zmiana = 1;       
				}
			}
			if(!zmiana) break;
		}


	}
	void bb(int M)
	{
		node global;//globalny wêze³ - przechowujemy informacje o wyniku
		global.benefit=0;
		global.weight=0;
		global.ub=F_ub(M,global,0);
		global.sek=new bool [ele]; for (int h=0;h<ele;h++) global.sek[h]=false;

		int wsk=2;//indeks-ile ju¿ nodów by³o
		node *temp = new node[2];   ///(2^(ele+1))-2
		node *kolejka = new node[wsk-2];

		int zmiana;
		node tmp; //do sortowania

		for(int i=0;i<ele;i++)
		{
			//opcja - bierzemy przedmiot 
			temp[0].benefit=global.benefit+pom[i].war;
			temp[0].weight=global.weight+pom[i].obj;
			temp[0].ub=F_ub(M,temp[0],i+1);
			temp[0].level=i;

			temp[0].sek=new bool[ele];
			for (int yu=0;yu<ele;yu++) temp[0].sek[yu]=global.sek[yu];
			temp[0].sek[i]=true;

			//for (int yu=0;yu<ele;yu++) cout << temp[0].sek[yu]<< " ";
			//cout << endl;
			//system ("pause");

			//opcja - nie bierzemy
			temp[1].benefit=global.benefit;
			temp[1].weight=global.weight;//waga i benefit siê nie zmienia bo nie dodajemy przedmiotu
			temp[1].ub=F_ub(M,temp[1],i+1);
			temp[1].level=i;

			temp[1].sek=new bool[ele];
			for (int yu=0;yu<ele;yu++) temp[1].sek[yu]=global.sek[yu];
			temp[1].sek[i]=false;

			if(temp[0].weight>M) 
			{
				wsk=wsk-1;
				node *t_kolejka = new node[wsk];
				for (int yo=0;yo<wsk-1;yo++)
				{
					t_kolejka[yo]=kolejka[yo];
				}
				t_kolejka[wsk-1]=temp[1];

				delete [] kolejka; 
				kolejka = new node [wsk];

				for (int yo=0;yo<wsk;yo++)
				{
					kolejka[yo]=t_kolejka[yo];
				}
				delete [] t_kolejka;

			}
			else
			{
				node *t_kolejka = new node[wsk];
				for (int yo=0;yo<wsk-2;yo++)
				{
					t_kolejka[yo]=kolejka[yo];
				}
				t_kolejka[wsk-2]=temp[0];
				t_kolejka[wsk-1]=temp[1];

				delete [] kolejka; 
				kolejka = new node [wsk];

				for (int yo=0;yo<wsk;yo++)
				{
					kolejka[yo]=t_kolejka[yo];
				}
				delete [] t_kolejka;

			}



			for( int i1 = 0; i1 < wsk; i1++ )
			{
				for( int j = 0; j < wsk - 1; j++ )
				{
					if( kolejka[j].ub < kolejka[j + 1].ub )
						swap( kolejka[j],kolejka[j+1] );

				}
			}


			global.benefit=kolejka[0].benefit;
			global.weight=kolejka[0].weight;
			global.ub=kolejka[0].ub;
			global.level=kolejka[0].level;

			for (int yu=0;yu<ele;yu++) global.sek[yu]=kolejka[0].sek[yu];

			if (global.benefit>=global.ub && global.benefit>=kolejka[1].ub) break;

			wsk=wsk-1;
			for (int yo=0;yo<wsk;yo++)
			{
				kolejka[yo]=kolejka[yo+1];
			}

			node *t_kolejka2 = new node[wsk];
			for (int yo=0;yo<wsk;yo++)
			{
				t_kolejka2[yo]=kolejka[yo];
			}
			delete [] kolejka; 
			kolejka = new node [wsk];

			for (int yo=0;yo<wsk;yo++)
			{
				kolejka[yo]=t_kolejka2[yo];
			}
			delete [] t_kolejka2;

			i=global.level;
			wsk=wsk+2;
		}


		cout << "Koniec algorytmu branch and bound" << endl;

		cout<< "Benefit" << "  " << "Waga"<<endl;
		cout << global.benefit << "    " << global.weight <<endl;


		for(int l=0;l<ele;l++)
		{
			cout << l << " przedmiot";
			if (global.sek[l]==true) cout <<" JEST W PLECAKU" << "  " << pom[l].war << " " << pom[l].obj<<endl;

			else cout <<" NIE JEST W PLECAKU" << endl;
		}


		delete[] temp;

	}

	void dynamina(int W)
	{
		int i, w;

		int **K = new int *[ele+1];
		for (i = 0; i <= ele; i++)
		{
			K[i] = new int [W+1];
			for (w = 0; w <= W; w++)
			{
				if (i==0 || w==0)
					K[i][w] = 0;
				else if (pom[i-1].obj <= w)
				{
					K[i][w] = max(pom[i-1].war + K[i-1][w-pom[i-1].obj],  K[i-1][w]);

				}
				else
				{
					K[i][w] = K[i-1][w] ;

				}
				//cout << K[i][w] << " ";

			}
			//cout << endl;
		}
		//system("pause");
		int waga=0;
		for (int ju=W;ju>0;ju--)
		{
			if (K[ele][ju]==K[ele][ju-1]) continue;
			else
			{
				waga=ju;
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////
		int **pol = new int *[ele+1];
		for (int i = 0; i <= ele; i++)
		{
			pol[i] = new int [W+1];
			for (int w = 0; w <= W; w++)
			{
				pol[i][w]=0;
			}
		}
		for (int i = 1; i<=ele; i++)
		{
			for (int j = 1; j <= W; j++)
			{ 

				if (j>=pom[i-1].obj && K[i-1][j] <= (K[i][j-pom[i-1].obj] + pom[i-1].war) )
				{
					pol[i][j]=i-1;
				}
				else
				{
					pol[i][j]=pol[i-1][j];
				}
				//cout << pol[i][j]<<" ";
			}
			//cout << endl;
		}

		/*int k9=W;

		while (true)
		{
			cout << pol[ele][k9]<< " zabrany"<<endl;

			if (pol[ele][k9]==0)break;

			k9=k9-pom[pol[ele][k9]].obj;
		}*/
		///////////////////////////////////////////////////////////////////////////////////////////
		cout << "Koniec programowania dynamicznego" << endl;

		cout<< "Benefit" << "  " << "Waga"<<endl;
		cout << K[ele][W] << "    " << waga <<endl;
		//return K[ele][W];

	}

	void tas(int W, double e)
	{
		double *t9b = new double [ele]; //tablica double
		int *tabex = new int [ele+1]; // tablica intów
		double K = (pom[0].war * e); // obliczamy wspolczynnik K - najcennejszy przedmiot * e / l_elementów
		K/=ele;
		for (int io=0;io<ele;io++) 
		{
			//skalujemy pozosta³e przedmioty i wrzucamy zaokr¹glenia w dó³ do tablicy intow
			t9b[io]=(pom[io].war);
			t9b[io]/=K;
			tabex[io+1]=floor(t9b[io]);
		}
		tabex[0]=0;
		int p_max = tabex[1];//maksimum po przeskalowaniu

		
        
		delete [] t9b;

		int **F = new int *[ele+1];
		int profit2=0;

		for(int k=0;k<=ele;k++)
		{
			F[k] = new int [(ele*p_max)+1];
			for (int u=0;u<=(ele*p_max);u++) F[k][u]=0;
		}
		//^^^ Tworzona jest tablica i wype³niana zerami

		for (int i=1;i<=ele*p_max;i++) F[0][i]=INT_MAX; //pierwszy wiersz wypelniany INT_MAX

		for(int k=1;k<=ele;k++)
		{
			for (int u=1;u<=(ele*p_max);u++)
			{
				if (u-tabex[k]<0 || F[k-1][u-tabex[k]] == INT_MAX ) F[k][u]=F[k-1][u];
				else F[k][u]=min((F[k-1][u]),( F[k-1][u-tabex[k]] + pom[k-1].obj ));
				//minimalna waga przedmiotów od 1 do k których wartoœæ wynosi co najwy¿ej u
				if (F[ele][u] <= W) profit2 = u; 

				//if (F[k][u]==INT_MAX) cout << "M" << " ";
				//else cout << F[k][u] << " ";
			}
			//cout << endl;
		}


		int i = ele;          // liczba przedmiotów do algorytmu
		int j = profit2;        // najwy¿sza osi¹gniêta wartoœæ dla plecaka
		int wx=0;//profit2
		int laga=0;//waga
		while (i > 0 && j > 0 )
		{
			if (F[i][j] != F[i-1][j])       //  macierz FPTAS
			//jezeli nastapila zmiana w macierzy FPTAS - oznacza to, ¿e zosta³ zabrany przedmiot
			//jezeli zmian nie bylo - nic nie dodwano do plecaka
			{
				cout << "Przedmiot numer: " << i-1 << endl;
				j=j-tabex[i];
				i--;
				laga = laga + pom[i].obj;
				wx+=pom[i].war;
			}
			else i--;
		}
		cout << "Waga: " << laga << endl;  
		cout << "Profit: " << profit2 *K << endl;
		cout << "Profit2: " << wx << endl;  

		//return profit2*K;
	}




};

