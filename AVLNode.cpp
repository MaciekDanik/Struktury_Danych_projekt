#include "AVLNode.h"

using namespace std;

template<class T>
AVLNode<T>::AVLNode()
{
	parent = nullptr;
	leftSon = nullptr;
	rightSon = nullptr;
	value = 0;
	balanceFactor = 0;
}

template<class T>
AVLNode<T>::~AVLNode() {}

template<class T>
void AVLNode<T>::setParent(AVLNode<T>* p)
{
	this->parent = p;
}

template<class T>
void AVLNode<T>::setLeftSon(AVLNode<T>* l)
{
	this->leftSon = l;
}

template<class T>
void AVLNode<T>::setRightSon(AVLNode<T>* r)
{
	this->rightSon = r;
}

template<class T>
void AVLNode<T>::setValue(T val)
{
	this->value = val;
}

template<class T>
void AVLNode<T>::setBF(int bf)
{
	this->balanceFactor = bf;
}

template<class T>
AVLNode<T>* AVLNode<T>::getParent()
{
	return this->parent;
}

template<class T>
AVLNode<T>* AVLNode<T>::getLeftSon()
{
	return this->leftSon;
}

template<class T>
AVLNode<T>* AVLNode<T>::getRightSon()
{
	return this->rightSon;
}

template<class T>
T AVLNode<T>::getValue()
{
	return this->value;
}

template<class T>
int AVLNode<T>::getBF()
{
	return this->balanceFactor;
}

template class AVLNode<int>;
template class AVLNode<double>;
template class AVLNode<float>;