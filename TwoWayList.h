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
	void addNode(int Pos, T val);
	void delNodeAtPosition(int Pos); // usuwa element z zadanej pozycji
	void delNodeWithValue(T val);
	void display();
};

#endif // !TwoWayList_H
