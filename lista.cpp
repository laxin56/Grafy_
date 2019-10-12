#include <iostream>
#include <ctime>
#include <cstdlib>

#include "lista.hpp"

using namespace std;

const int MAX_N = 100; // maksymalna iloœæ wierzcho³ków w grafie



void lista()
{
     srand(time(NULL));



  int i,wmax,n,x,y;
cin >> n;
  Lista *L[MAX_N],*p;
  for(i = 0; i < MAX_N; i++)
  L[i] = 0;
  wmax = 0;

  for(i = 0; i < n; i++)
  {
    x =(rand()%9)+1; //losuje poczatkowy wierzcholek z predzialu od 1 do 9
    y =(rand()%9)+1; // losuje koncowy wierzcholek z przedzialu od 1 do 9
    wmax = (x > wmax) ? x : wmax;
    wmax = (y > wmax) ? y : wmax;
    p = new Lista; //dynamiczna alokacja struktury
    p->next = L[x-1];
    p->node = y;
    L[x-1] = p;

    p = new Lista;
    p->next = L[y-1];
    p->node = x;
    L[y-1] = p;
  }
  cout << endl;
  for(i = 0; i < wmax; i++)
  {
    cout << i + 1 << ":";
    p = L[i];
    while(p)
    {
      cout << p->node << " ";
      p = p->next;
    }
    cout << endl;
  }

}
