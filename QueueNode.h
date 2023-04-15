#ifndef QueueNode_H
#define QueueNode_H

#include <string>

using namespace std;

template<class T>
class QueueNode
{
private:
	T value;
	QueueNode<T>* next;
	QueueNode<T>* prev;
public:
	QueueNode();
	~QueueNode();
	void setValue(T val);
	T getValue();
	QueueNode<T>* getNext();
	QueueNode<T>* getPrev();
	void setNext(QueueNode<T>* nextNode);
	void setPrev(QueueNode<T>* prevNode);
};

#endif
