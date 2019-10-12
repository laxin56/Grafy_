#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "macierz.hpp"

using namespace std;

void macierz()
{
     srand(time(NULL));

//25% to 0.25 = 2e/v*(v-1) - wzor na gestosc
    int v,e,v1,v2;// v - wierzcholki,   e - krawedzie,  v1 i v2 -zmienne "wierzcholkowe" potrzebne do losowania krawedzi, g- zmienna przechowujaca gestosc

cin >> v >> e;
    int **M = new int *[v]; //alokacja dablicy dynamicznej dwuwymiarowej
    for(int i =0; i<v; i++) { M[i]= new int [v]; }//alokacja pamieci kolumn

    for(int i=0; i<v; i++)                           //W tym miejscu wstawiamy we wszystkie pola naszej macierzy zera
        for(int j=0; j<v; ++j) { M[i][j] =0; }



for(int m=0; m<e; m++) //dla okreslonej gestosci grafu wpisuje 1 do macierzy
{
    v1 = (rand()%(v-1)) + 1;
    v2 = (rand()%(v-1)) + 1;
    M[v1][v2] = 1;   //w miejscu gdzie wierzcholki laczy krawedz w macierzy wpisujemy 1
    M[v2][v1] = 1;   // graf nieskierowany
}

/*
  for(int i = 0; i < v; i++)
  {
    cout << endl << " " << i + 1 << ":";
    for(int j = 0; j < v; j++) cout << " " << M[i][j];
  }

  cout << endl << endl;
*/
 for(int i = 0; i < v; i++)
 {
     delete [] M[i];
 }
  delete [] M;

   }
