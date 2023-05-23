#ifndef TwoWayList_H
#define TwoWayList_H

#include "TwoWayListNode.h"
#include <chrono>

template <class T>
class TwoWayList
{
private:
	TwoWayListNode<T>* head; //wskaźnik na pierwszy element
	TwoWayListNode<T>* tail; //wskaźnik na ostatni element
public:
	TwoWayList(); //konstruktor listy
	~TwoWayList(); //destruktor listy
	void addNodeFront(T val); //dodaje węzeł na początek listy
	void addNodeBack(T* tablica); //dodaje węzeł na koniec listy
	void delNodeAtPosition(int Pos); // usuwa element z zadanej pozycji
	void delNodeWithValue(T val); //usuwa elemet o danej wartości
	void display(); //wyświetla listę
	TwoWayListNode<T>* findNode(TwoWayListNode<T>* node, T val);
	TwoWayListNode<T>* Predecesor(TwoWayListNode<T>* node);
	TwoWayListNode<T>* Succesor(TwoWayListNode<T>* node);
};

#endif // !TwoWayList_H
/*
Lista jedno kierunkowa
	dodaj przód tył
	usuń przód tył
	wyświetl

tablica losowych wartości
zapis do struktury
np. usunięcia danej wartości [pomiar czasu]
znajdź warość
i może czas zapisu
*/
