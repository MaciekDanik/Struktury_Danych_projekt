#ifndef QueueNode_H
#define QueueNode_H

#include <string>

using namespace std;

template<class T>
class QueueNode
{
private:
	T value;
	QueueNode<T>* next; //wska�nik na nast�pny element
	QueueNode<T>* prev; //wska�nik na poprzedni element
public:
	QueueNode(); //konstruktor w�z�a
	~QueueNode(); //destruktor w�z�a
	void setValue(T val); //ustawia warto�� w�z�a
	T getValue(); //zwraca warto�� w�z�a
	QueueNode<T>* getNext(); //zwraca nast�pny w�ze�
	QueueNode<T>* getPrev(); //zwraca poprzedni w�ze�
	void setNext(QueueNode<T>* nextNode); //ustawia nast�pny w�ze�
	void setPrev(QueueNode<T>* prevNode); //ustawia poprzedni w�ze�
};

#endif
