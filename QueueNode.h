#ifndef QueueNode_H
#define QueueNode_H

#include <string>

using namespace std;

template<class T>
class QueueNode
{
private:
	T value;
	QueueNode<T>* next; //wskaŸnik na nastêpny element
	QueueNode<T>* prev; //wskaŸnik na poprzedni element
public:
	QueueNode(); //konstruktor wêz³a
	~QueueNode(); //destruktor wêz³a
	void setValue(T val); //ustawia wartoœæ wêz³a
	T getValue(); //zwraca wartoœæ wêz³a
	QueueNode<T>* getNext(); //zwraca nastêpny wêze³
	QueueNode<T>* getPrev(); //zwraca poprzedni wêze³
	void setNext(QueueNode<T>* nextNode); //ustawia nastêpny wêze³
	void setPrev(QueueNode<T>* prevNode); //ustawia poprzedni wêze³
};

#endif
