#include "macierz.hpp"
#include "kruskal.hpp"
#include "lista.hpp"
#include "prime.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    //wykonuje dwie funkcje, ktore testuja nam odpowiednio algorytmy kruskala i prima
testuj_kruskal();
testuj_prime();
    return 0;
}
