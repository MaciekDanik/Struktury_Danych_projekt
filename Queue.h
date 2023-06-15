#ifndef Queue_H
#define Queue_H

#include "QueueNode.h"

using namespace std;

template <class T>
class Queue
{
private:
	QueueNode<T>* head; //wska�nik na pierwszy element
	QueueNode<T>* tail; //wska�nik na ostatni element
public:
	Queue(); //konstruktor kolejki
	~Queue(); //destruktor kolejki
	void addNodeBack(T val); //dodaj� w�ze� na ko�cu kolejki
	QueueNode<T>* delFirstNode(); // usuwa element z poczatku kolejki
	void display(); //wy�wietla ca�� kolejk�
};

#endif // !Queue_H
