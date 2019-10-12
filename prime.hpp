#ifndef PRIME_H
#define PRIME_H

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

    Prime(int, int);
    ~Prime();

};

void testuj_prime();


#endif
