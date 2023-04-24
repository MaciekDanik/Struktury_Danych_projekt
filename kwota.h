#ifndef kwota_h_
#define kwota_h_
#include <iostream>
using namespace std;
class kwota
{
    public:
    float liczba;
    kwota *nastepna;
   kwota()
{
    nastepna = nullptr;
}
};

#endif // kwota_h_
