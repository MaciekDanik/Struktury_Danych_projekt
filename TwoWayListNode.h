#ifndef TwoWayListNode_H
#define TwoWayListNode_H

template <class T>
class TwoWayListNode
{
private:
	T value;
	TwoWayListNode<T>* next;
	TwoWayListNode<T>* prev;
public:
	TwoWayListNode();
	~TwoWayListNode();
	void setValue(T val);
	T getValue();
	TwoWayListNode<T>* getNext();
	TwoWayListNode<T>* getPrev();
	void setNext(TwoWayListNode<T>* nextNode);
	void setPrev(TwoWayListNode<T>* prevNode);
};

#endif // !TwoWayListNode
