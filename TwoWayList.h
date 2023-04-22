#ifndef TwoWayList_H
#define TwoWayList_H

#include "TwoWayListNode.h"

template <class T>
class TwoWayList
{
private:
	TwoWayListNode<T>* head;
	TwoWayListNode<T>* tail;
public:
	TwoWayList();
	~TwoWayList();
	void addNodeFront(T val);
	void addNodeBack(T val);
	void delNodeAtPosition(int Pos); // usuwa element z zadanej pozycji
	void delNodeWithValue(T val);
	void display();
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
