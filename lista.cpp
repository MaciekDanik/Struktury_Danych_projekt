#include <iostream>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <chrono>
#include "lista.h"


using namespace std;
template <class T>
lista_jednokierunkowa<T>::lista_jednokierunkowa()
{
    pierwsza=nullptr;
}
template <class T>
void lista_jednokierunkowa<T>::wyswietlenie_listy()
{
    kwota<T> *temp=pierwsza;
    int pozycja=1;
    while (temp)
    {
        cout<<"Kwota "<<pozycja<<": "<<temp->liczba<<" "<<endl;
        temp=temp->nastepna;
        pozycja++;
    }
}
template <class T>
void lista_jednokierunkowa<T>::dodanie_kwoty()
{

    cout<<"Chcesz dodac element na koniec czy poczatek listy?"<<endl;
    cout<<"1 - pocz¹tek, 2 - koniec, lub pierwszy element"<<endl;
    int wybur;
    cin>>wybur;
    if(wybur==1)
    {
        kwota<T> *przod=new kwota<T>;
        cout<<"Wprowadz element na poczatek listy: "<<endl;
        T nowosc1;
        cin>>nowosc1;
        przod->liczba=nowosc1;
        przod->nastepna=pierwsza;
        pierwsza=przod;
    }
    if(wybur==2)
    {
        cout<<"Ile elementow chcesz dodac, wprowadz liczbe: ..."<<endl;
        T dec;
        cin>>dec;
        auto t1=chrono::high_resolution_clock::now();
        for(int i=0; i<dec; i++)
        {
            kwota<T> *nowa=new kwota<T>;
            //cout<<"Wprowadz kwote na liste"<<endl;
            T nowosc;
            nowosc=i;
            nowa->liczba=nowosc;
            if(pierwsza==nullptr)
            {
                pierwsza=nowa;
            }
            else
            {
                kwota<T> *temp=pierwsza;
                while (temp->nastepna)
                {
                    temp=temp->nastepna;
                }
                temp->nastepna=nowa;
            }
        }
         auto t2=chrono::high_resolution_clock::now();
        auto time =chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
        cout<<"Czas sortowania: "<<time.count()*1e-9<<" sekundy"<<endl;
     }
}
template <class T>
void lista_jednokierunkowa<T>::usuniecie_kwoty()
{

    cout<<"Kwote na ktorej pozycji chcesz usunac ?"<<endl;
    int pozycja;
    cin>>pozycja;
    auto t1=chrono::high_resolution_clock::now();
    if(pozycja==1)
    {
        kwota<T> *temp=pierwsza;
        pierwsza=temp->nastepna;
        delete temp;
    }

    else if (pozycja>=2)
    {
        int i=1;

        kwota<T> *temp=pierwsza;
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
            kwota<T> *usuwana=temp->nastepna;
            temp->nastepna=temp->nastepna->nastepna;
            delete usuwana;
        }
    }
    auto t2=chrono::high_resolution_clock::now();
    auto time =chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
    cout<<"Czas usuwania: "<<time.count()*1e-9<<" sekundy"<<endl;
}
template <class T>
void lista_jednokierunkowa<T>::wyczeyszczenie_listy()
{
    //kwota<T>* temp=temp->nastepna;
    auto t1=chrono::high_resolution_clock::now();
  while(pierwsza !=nullptr)
  {
      kwota<T>* tep=pierwsza->nastepna;
      delete pierwsza;
      pierwsza=tep;
  }
   auto t2=chrono::high_resolution_clock::now(); 
   auto time=chrono::duration_cast<chrono::nanoseconds>(t2-t1);
   cout<<"Czas usuwania: "<<time.count()*1e-9<<" sekundy"<<endl;
}
template class lista_jednokierunkowa<int>;
template class lista_jednokierunkowa<double>;
template class lista_jednokierunkowa<float>;
template class kwota<int>;
template class kwota<double>;
template class kwota<float>;

