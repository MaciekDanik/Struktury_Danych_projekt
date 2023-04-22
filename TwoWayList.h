#ifndef TwoWayList_H
#define TwoWayList_H

#include "TwoWayListNode.h"

template <class T>
class TwoWayList
{
private:
	TwoWayListNode<T>* head; //wskaŸnik na pierwszy element
	TwoWayListNode<T>* tail; //wskaŸnik na ostatni element
public:
	TwoWayList(); //konstruktor listy
	~TwoWayList(); //destruktor listy
	void addNodeFront(T val); //dodaje wêze³ na pocz¹tek listy
	void addNodeBack(T val); //dodaje wêze³ na koniec listy
	void delNodeAtPosition(int Pos); // usuwa element z zadanej pozycji
	void delNodeWithValue(T val); //usuwa elemet o danej wartoœci
	void display(); //wyœwietla listê
};

#endif // !TwoWayList_H
/*
Lista jedno kierunkowa
	dodaj przód ty³
	usuñ przód ty³
	wyœwietl

tablica losowych wartoœci
zapis do struktury
np. usuniêcia danej wartoœci [pomiar czasu]
znajdŸ waroœæ
i mo¿e czas zapisu
*/
