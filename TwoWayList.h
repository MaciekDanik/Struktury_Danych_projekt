#ifndef TwoWayList_H
#define TwoWayList_H

#include "TwoWayListNode.h"

template <class T>
class TwoWayList
{
private:
	TwoWayListNode<T>* head; //wska�nik na pierwszy element
	TwoWayListNode<T>* tail; //wska�nik na ostatni element
public:
	TwoWayList(); //konstruktor listy
	~TwoWayList(); //destruktor listy
	void addNodeFront(T val); //dodaje w�ze� na pocz�tek listy
	void addNodeBack(T val); //dodaje w�ze� na koniec listy
	void delNodeAtPosition(int Pos); // usuwa element z zadanej pozycji
	void delNodeWithValue(T val); //usuwa elemet o danej warto�ci
	void display(); //wy�wietla list�
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
