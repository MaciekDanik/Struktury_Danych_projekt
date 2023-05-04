#ifndef kwota_h_
#define kwota_h_
#include <iostream>
using namespace std;
template <class T>
class kwota
{
    public:
   T liczba;
    kwota<T> *nastepna;
   kwota()
{
    nastepna = nullptr;
}
};

#endif // kwota_h_
