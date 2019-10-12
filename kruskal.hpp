#ifndef KRUSKAL_H
#define KRUSKAL_H

class Krawedz{
  public:
 int poczatek;
 int koniec;
 int waga;

};

bool porownaj(Krawedz E1, Krawedz E2);
int find_rodzic(int V, int *rodzic);
void kruskal(Krawedz *wejscie, int V, int E);
void testuj_kruskal();

#endif

