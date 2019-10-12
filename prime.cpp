#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

#include "prime.hpp"

using namespace std;
/*
class Prime
{
public:
    int E,V; //krawedzie, wierzcholki
    int** graf;
    int* odwiedzone;
    int* mino; //minimalna odleglosc
    void wyzeruj();
    void wejscie();
    void wyjscie();
    void mst();

    Prime(int edges, int vertices);
    ~Prime();

};
*/
//funkcja zerujaca elementy grafu - macierz
void Prime::wyzeruj()
{
    for(int i=0;i<V;i++)
    {
        odwiedzone[i]=mino[i]=0;
        for(int j=0; j<V;j++)
        {
            graf[i][j]=0;
        }
    }
}
void Prime::wejscie()  //funkcja ktora każe nam podac odpowiednie wejscie
{
    srand(time(NULL));
    int w1,w2,waga;


    for(int i=0; i<E; i++)
    {
        w1 = (rand()%V);
        w2 = (rand()%V);
        waga = (rand()%30);
        graf[w1][w2] = waga;
        graf[w2][w1]=waga;
    }
}

void Prime::wyjscie()
{
    for(int i=0;i<V;i++)
    {
        cout<<endl;
        for(int j=0;j<V;j++)
        {
            cout.width(4);
            cout<<graf[i][j];
        }
    }
}

void Prime::mst()
{
    int m=9999,wiersz,kolumna,ind=0;//m-maxymalna odlegosc
    for(int i=0;i<V;i++)
    {
        for(int j=i;j<V;j++)
        {
            if(graf[i][j]<m &&graf[i][j]!=0)  //jesli dana krawedz jest mniejsza niz najmniejza wartosc i rowzna od zerato przypisuje
            {
                m=graf[i][j];
                wiersz=i;
                kolumna=j;
            }
        }
    }
    odwiedzone[wiersz]=odwiedzone[kolumna]=1;  //przypisuje odwiedzonym wierszom i kolumnom wartosc 1
    mino[ind++]=m;

    for(int i=0; i<(V-2);i++)
    {
        m=9999;
        for(int j=0;j<V;j++)
        {
            if(odwiedzone[j]==1)
            {

                for(int k=0;k<V;k++)
                {
                    if(graf[j][k]<m &&graf[j][k]!=0&&odwiedzone[k]==0)  //jesli dana krawedz jest mniejsza niz najmniejza wartosc i rowna od zera to przypisuje
                    {
                        m=graf[j][k];
                        wiersz=j;
                        kolumna=k;
                    }
                }
            }
        }
    }
    odwiedzone[wiersz]=odwiedzone[kolumna]=1;  //przypisuje odwiedzonym wieroszom i kulomnom wartosc 1
    mino[ind++]=m;

    int suma=0; //zmienna przechowujaca koszt grafu
/*
    cout << endl;
    cout <<"Minimalny dystans to: ";
    for(int i=0;i<V-1;i++)
    {
        cout<<" "<<mino[i]<<" ";
        suma+=mino[i];

    }

    cout<< endl;
    cout << "calkowity koszt to: "<< suma;
    */
}

Prime::Prime(int edges, int vertices)
    : E(edges), V(vertices)
{
    odwiedzone = new int[vertices];
    mino = new int[vertices];
    graf = new int*[vertices];
    for(int i = 0; i < vertices; ++i)
    {
        graf[i] = new int[vertices];
    }
}

Prime::~Prime()
{

    delete[] odwiedzone;
    delete[] mino;
    for(int i = 0 ; i < V; ++i)
    {
        delete[] graf[i];
    }
    delete[] graf;
}

void testuj_prime()
{
     int tab[5];   //tablica wierzcholkow
 tab[0]=10;
 tab[1]=50;
 tab[2]=100;
 tab[3]=500;
 tab[4]=1000;
 float gestosc[] = {0.25,0.5,0.75,1};  //tablica gestosci
 int r,e;
double w;
fstream plik;
string nazwa;
nazwa = "prime.txt";
plik.open( nazwa.c_str(), ios::out | ios::app); //zmienna plikowa

for(int i =0; i<5;i++)
{
    r = tab[i];
    for(int j=0; j<4; j++)
    {
    w = gestosc[j];
 e = (w*r*(r-1))/2;

    Prime obiekt(e,r);
    obiekt.wejscie();
    auto t1 = std::chrono::high_resolution_clock::now();
    obiekt.mst();
    auto t2 = std::chrono::high_resolution_clock::now();
    //obiekt.wyjscie();
    auto roznica = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
    plik <<"Wpisujemy: " << r << " - " << w << " "<< roznica.count() <<endl;
    }
}
plik.close(); //zamykamy plik w ktorym zaposywalismy dane
}
