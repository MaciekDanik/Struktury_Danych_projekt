#ifndef Queue_H
#define Queue_H

#include "QueueNode.h"

using namespace std;

template <class T>
class Queue
{
private:
	QueueNode<T>* head; //wskaŸnik na pierwszy element
	QueueNode<T>* tail; //wskaŸnik na ostatni element
public:
	Queue(); //konstruktor kolejki
	~Queue(); //destruktor kolejki
	void addNodeBack(T val); //dodajê wêze³ na koñcu kolejki
	QueueNode<T>* delFirstNode(); // usuwa element z poczatku kolejki
	void display(); //wyœwietla ca³¹ kolejkê
};

#endif // !Queue_H
