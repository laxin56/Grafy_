#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <chrono>

#include "kruskal.hpp"

using namespace std;
/*
//klasa ktora reprezentuje krawedzie o odpowiednim poczatku,koncu i wadze
class Krawedz{
  public:
 int poczatek;
 int koniec;
 int waga;

};
*/

//funkcja porownujaca dwie krawedzie, a raczej ich wagi
bool porownaj(Krawedz E1, Krawedz E2)
{
    return (E1.waga < E2.waga);
}

int find_rodzic(int V, int *rodzic)
{
    if(rodzic[V] == V){
            return V;
    }

    return find_rodzic(rodzic[V], rodzic);
}


//funkcja wykonujaca algorytm kruskala

void kruskal(Krawedz *wejscie, int V, int E)
{
    //sortuje dane wejsciowe, bazujac na wagach
    sort(wejscie, wejscie+E, porownaj);

    Krawedz *wyjscie = new Krawedz[V-1];

    int *rodzic = new int[V];

    for(int i=0; i<V;i++)
    {
        rodzic[i] = i;
    }

    int liczba =0;
    int j=0;
    while(liczba!= V-1){
            Krawedz takrawedz = wejscie[j];
    //teraz sprawdzamy czy mozna dodac dan¹ krawedz do drzewa MST

    int poczatkowyrodzic = find_rodzic(takrawedz.poczatek, rodzic);
    int koncowyrodzic = find_rodzic(takrawedz.koniec, rodzic);

    if(poczatkowyrodzic != koncowyrodzic)
    {
        wyjscie[liczba] = takrawedz;
        liczba++;
    }
        j++;
    }
    /*
    for(int i =0; i< V-1 ; i++)
    {
        if(wyjscie[i].poczatek < wyjscie[i].koniec)
        {
            cout << wyjscie[i].poczatek << " " << wyjscie[i].koniec << " " << wyjscie[i].waga << endl;

        }
        else {
            cout << wyjscie[i].koniec << " " << wyjscie[i].poczatek << " " << wyjscie[i].waga << endl;
        }
    }
    */
}
void testuj_kruskal()
{
    fstream plik;
    string nazwa;
    nazwa = "kruskal.txt";
    srand(time(NULL)); //zapewnia losowosc liczb
    int V,E;
    double g;//ilosc wierzcholkow i krawedzi
     int tab[5];   //tablica wierzcholkow
 tab[0]=10;
 tab[1]=50;
 tab[2]=100;
 tab[3]=500;
 tab[4]=1000;

 float gestosc[] = {0.25,0.5,0.75,1};  //tablica gestosci



plik.open( nazwa.c_str(), ios::out | ios::app); //zmienna plikowa
    for(int u=0; u <5 ; u++)
    {
        V=tab[u];

        for(int z =0; z<4; z++)
        {
         g = gestosc[z];
        E = (g*V*(V-1))/2; //obliczanie liczby krawedzi z podanych gestosci
        cout << E << " " << V;
        Krawedz *wejscie = new Krawedz[E]; //tablica dynamiczna o ilosci krawedzi typu klasy krawedz

    //podajemy teraz dane wejsciowe
    for(int i = 0; i<E; i++) {
        int p,k,w;
        p = rand()%(V-1);
        k = rand()%(V-1);
        w = rand()%30 + 1;
        wejscie[i].poczatek = p;
        wejscie[i].koniec = k;
        wejscie[i].waga = w;
        //cout << wejscie[i].poczatek << " " << wejscie[i].koniec << " " << wejscie[i].waga << endl;
    }

  cout << "zaczynamy podejscie" << endl;
auto t1 = std::chrono::high_resolution_clock::now(); //zapisanie czasu startu mierzenia

    kruskal(wejscie, V, E);

auto t2 = std::chrono::high_resolution_clock::now();//zapisanie konca mierzenia
 auto roznica = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
    plik <<"Wpisujemy: " << V << " - " << E << " "<< roznica.count() <<endl;

    delete [] wejscie;
        }
    }
    plik.close();
}
