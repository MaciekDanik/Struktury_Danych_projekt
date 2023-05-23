#include "TwoWayList.h"
#include <iostream>
#include <chrono>

using namespace std;

template<class T>
TwoWayList<T>::TwoWayList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template<class T>
TwoWayList<T>::~TwoWayList() {}

template<class T>
void TwoWayList<T>::addNodeFront(T val)
{
	TwoWayListNode<T>* newNode = new TwoWayListNode<T>;
	newNode->setNext(nullptr);
	newNode->setValue(val);
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->setPrev(newNode);
		newNode->setNext(head);
		head = newNode;
	}
}

template<class T>
void TwoWayList<T>::addNodeBack(T* tablica)
{
	int val1 = 0;
	cout << "Ile liczb chesz umiescic na liscie?" << endl;
	cin >> val1;
	auto t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < val1; i++)
	{
		T val = tablica[i];
		TwoWayListNode<T>* newNode = new TwoWayListNode<T>;
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
	auto t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
	cout << "Czas dodawania: " << time.count() * 1e-9 << " sekundy" << endl;
}

template<class T>
void TwoWayList<T>::delNodeAtPosition(int Pos)
{
	TwoWayListNode<T>* nodePtr;
	if (!head)
	{
		return;
	}
	if (Pos == 1)
	{
		nodePtr = head->getNext();
		delete head;
		head = nodePtr;
	}
	else if (Pos >= 2)
	{
		int counter = 1;
		nodePtr = head;

		while (nodePtr->getNext())
		{
			if ((counter + 1) == Pos)
			{
				break;
			}
			nodePtr = nodePtr->getNext();
			counter++;
		}

		if (nodePtr->getNext()->getNext() == nullptr)
		{
			delete nodePtr->getNext();
			nodePtr->setNext(nullptr);
		}
		else
		{
			TwoWayListNode<T>* del = nodePtr->getNext();
			nodePtr->setNext(del->getNext());
			del->getNext()->setPrev(nodePtr);
			delete del;
		}
	}
}

template<class T>
TwoWayListNode<T>* TwoWayList<T>::findNode(TwoWayListNode<T>* node, T val)
{
	TwoWayListNode<T>* first = head;
	TwoWayListNode<T>* last = tail;

	if (first->getValue() == val || last->getValue() == val)
	{
		if (first->getValue() == val)
		{
			return first;
		}
		else
		{
			return last;
		}
	}
	else
	{
		first = first->getNext();
		last = last->getPrev();
	}
}

template<class T>
TwoWayListNode<T>* TwoWayList<T>::Predecesor(TwoWayListNode<T>* node)
{
	TwoWayListNode<T>* tmpNode = head;
	TwoWayListNode<T>* foundNode = head;
	if (node == nullptr)
	{
		return node;
	}
	while (tmpNode->getNext())
	{
		if (tmpNode->getValue() < node->getValue() && tmpNode->getValue() > foundNode->getValue())
		{
			foundNode = tmpNode;
		}
		tmpNode = tmpNode->getNext();
	}
	return foundNode;
}

template<class T>
TwoWayListNode<T>* TwoWayList<T>::Succesor(TwoWayListNode<T>* node)
{
	TwoWayListNode<T>* tmpNode = head;
	TwoWayListNode<T>* foundNode = head;
	if (node == nullptr)
	{
		return node;
	}
	while (tmpNode->getNext())
	{
		if (tmpNode->getValue() > node->getValue() && tmpNode->getValue() < foundNode->getValue())
		{
			foundNode = tmpNode;
		}
		tmpNode = tmpNode->getNext();
	}
	return foundNode;
}

template<class T>
void TwoWayList<T>::delNodeWithValue(T val)
{
}

template<class T>
void TwoWayList<T>::display()
{
	if (head)
	{
		TwoWayListNode<T>* nodePtr = head;
		cout << "Zapisana lista: " << endl;
		while (nodePtr->getNext())
		{
			T tmpValue = nodePtr->getValue();
			cout << tmpValue << "\t";   //wszystkie poza ostatnim
			nodePtr = nodePtr->getNext();
		}
		T tmpValue = nodePtr->getValue();
		cout << tmpValue << endl;   //ostatni element
	}
	cout << endl;
}

template class TwoWayList<int>;
template class TwoWayList<double>;
template class TwoWayList<float>;