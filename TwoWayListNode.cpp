#include "TwoWayListNode.h"

template <class T>
TwoWayListNode<T>::TwoWayListNode()
{
	value = 0;
}
template <class T>
TwoWayListNode<T>::~TwoWayListNode() {}

template<class T>
void TwoWayListNode<T>::setValue(T val)
{
	this->value = val;
}

template<class T>
T TwoWayListNode<T>::getValue()
{
	return this->value;
}

template<class T>
TwoWayListNode<T>* TwoWayListNode<T>::getNext()
{
	return this->next;
}

template<class T>
TwoWayListNode<T>* TwoWayListNode<T>::getPrev()
{
	return this->prev;
}

template<class T>
void TwoWayListNode<T>::setNext(TwoWayListNode<T>* nextNode)
{
	this->next = nextNode;
}

template<class T>
void TwoWayListNode<T>::setPrev(TwoWayListNode<T>* prevNode)
{
	this->prev = prevNode;
}

template class TwoWayListNode<int>;
template class TwoWayListNode<double>;
template class TwoWayListNode<float>;