#include "QueueNode.h"

template <class T>
QueueNode<T>::QueueNode()
{
	value = 0;
}
template <class T>
QueueNode<T>::~QueueNode() {}

template<class T>
void QueueNode<T>::setValue(T val)
{
	this->value = val;
}

template<class T>
T QueueNode<T>::getValue()
{
	return this->value;
}

template<class T>
QueueNode<T>* QueueNode<T>::getNext()
{
	return this->next;
}

template<class T>
QueueNode<T>* QueueNode<T>::getPrev()
{
	return this->prev;
}

template<class T>
void QueueNode<T>::setNext(QueueNode<T>* nextNode)
{
	this->next = nextNode;
}

template<class T>
void QueueNode<T>::setPrev(QueueNode<T>* prevNode)
{
	this->prev = prevNode;
}

template class QueueNode<int>;
template class QueueNode<double>;
template class QueueNode<float>;