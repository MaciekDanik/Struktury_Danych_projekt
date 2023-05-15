#ifndef lista_h_
#define lista_h_
#include "kwota.h"
#include <iostream>
#include <chrono>
using namespace std;
template <class T>
class lista_jednokierunkowa
{
    public:
    kwota<T> *pierwsza;
    void dodanie_kwoty();
    void usuniecie_kwoty();
    void wyswietlenie_listy();
    void wyczeyszczenie_listy();
    lista_jednokierunkowa();
};

#endif // lista_h_
