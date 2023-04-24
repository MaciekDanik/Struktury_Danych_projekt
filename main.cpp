#include <iostream>
#include <string>
#include <cstdlib>
#include "lista.h"
#include "kwota.h"
using namespace std;

int main()
{
lista *dlugi=new lista;
for(;;)
{
    cout<<"Menu Listy:"<<endl;
    cout<<"1. Dodanie elementu"<<endl;
    cout<<"2. Usuniecie elemntu na wybranej pozycji"<<endl;
    cout<<"3. Wyswitlenie zawartosci listy"<<endl;
    cout<<"4. Wyczyszczenie zawartosci listy"<<endl;
    cout<<"5. Wyjscie z programu"<<endl;
    cout<<endl;
    cout<<"Wprowadz numer opcjii ktora chcesz wykonac: "<<endl;
    int wybur;
    cin>>wybur;
    switch(wybur)
    {
    case 1:
        {
            dlugi->dodanie_kwoty();
        }
        break;
    case 2:
        {
            dlugi->usuniecie_kwoty();
        }
        break;
    case 3:
        {
            dlugi->wyswietlenie_listy();
        }
        break;
    case 4:
        {
            dlugi->wyczeyszczenie_listy();
        }
        break;
    case 5:
        {
            exit(0);
        }
    }
}
	return 0;
}
