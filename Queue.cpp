#include "Queue.h"
#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
void Queue<T>::addNodeBack(T val)
{
	QueueNode<T>* newNode = new QueueNode<T>;
	newNode->setNext(nullptr);
	newNode->setValue(val);

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
}

template <class T>
void Queue<T>::delFirstNode()
{
	QueueNode<T>* nodePtr;

	if (head == nullptr)
	{
		return;
	}
	else
	{
		nodePtr = head->getNext();
		delete head;
		head = nodePtr;
	}
}

template <class T>
void Queue<T>::display()
{
	if (head)
	{
		QueueNode<T>* nodePtr = head;
		cout << "Zapisana kolejka: " << endl;
		while (nodePtr->getNext())
		{
			int tmpValue = nodePtr->getValue();
			cout << tmpValue << endl;   //wszystkie poza ostatnim
			nodePtr = nodePtr->getNext();
		}
		int tmpValue = nodePtr->getValue();
		cout << tmpValue << endl;   //ostatni element
	}
	cout << endl;
}

template class Queue<int>;
template class Queue<double>;
template class Queue<float>;