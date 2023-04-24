#include <iostream>
#include "lista.h"
using namespace std;

lista::lista()
{
    pierwsza=nullptr;
}
void lista::wyswietlenie_listy()
{
    kwota *temp=pierwsza;
    int pozycja=1;
    while (temp)
    {
        cout<<"Kwota "<<pozycja<<": "<<temp->liczba<<" "<<endl;
        temp=temp->nastepna;
        pozycja++;
    }
}
void lista::dodanie_kwoty()
{
    kwota *nowa=new kwota;
    cout<<"Wprowadz kwote na liste"<<endl;
    float nowosc;
    cin>>nowosc;
    nowa->liczba=nowosc;
    if(pierwsza==nullptr)
    {
        pierwsza=nowa;
    }
    else
    {
        kwota *temp=pierwsza;
        while (temp->nastepna)
        {
            temp=temp->nastepna;
        }
        temp->nastepna=nowa;
    }
}
void lista::usuniecie_kwoty()
{
    cout<<"Kwote na ktorej pozycji chcesz usunac ?"<<endl;
    int pozycja;
    cin>>pozycja;
    if(pozycja==1)
    {
        kwota *temp=pierwsza;
        pierwsza=temp->nastepna;
        delete temp;
    }

    else if (pozycja>=2)
    {
        int i=1;

        kwota *temp=pierwsza;
        while(temp)
        {
            if((i+1)==pozycja)
            {
                break;
            }
            temp=temp->nastepna;
            i++;
        }
        if(temp->nastepna->nastepna==nullptr)
        {
            delete temp->nastepna;
            temp->nastepna=nullptr;

        }
        else
        {
            kwota *usuwana=temp->nastepna;
            temp->nastepna=temp->nastepna->nastepna;
            delete usuwana;
        }
    }
}
void lista::wyczeyszczenie_listy()
{
    kwota* temp=temp->nastepna;
  while(pierwsza !=nullptr)
  {
      kwota* tep=pierwsza->nastepna;
      delete pierwsza;
      pierwsza=tep;
  }

}
