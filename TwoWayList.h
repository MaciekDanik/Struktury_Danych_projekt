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
	dodaj prz�d ty�
	usu� prz�d ty�
	wy�wietl

tablica losowych warto�ci
zapis do struktury
np. usuni�cia danej warto�ci [pomiar czasu]
znajd� waro��
i mo�e czas zapisu
*/
