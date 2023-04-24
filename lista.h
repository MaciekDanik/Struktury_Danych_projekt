#ifndef lista_h_
#define lista_h_
#include "kwota.h"
#include <iostream>
using namespace std;
class lista
{
    public:
    kwota *pierwsza;
    void dodanie_kwoty();
    void usuniecie_kwoty();
    void wyswietlenie_listy();
    void wyczeyszczenie_listy();
    lista();
};

#endif // lista_h_
