#ifndef Queue_H
#define Queue_H

#include "QueueNode.h"

using namespace std;

template <class T>
class Queue
{
private:
	QueueNode<T>* head;
	QueueNode<T>* tail;
public:
	Queue();
	~Queue();
	void addNodeBack(T val);
	void delFirstNode(); // usuwa element z poczatku
	void display();
};

#endif // !Queue_H
