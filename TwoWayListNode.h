#ifndef TwoWayListNode_H
#define TwoWayListNode_H

template <class T>
class TwoWayListNode
{
private:
	T value;
	TwoWayListNode<T>* next; //wskaŸnik na nastêpny element
	TwoWayListNode<T>* prev; //wskaŸnik na poprzedni element
public:
	TwoWayListNode(); //konstruktor list
	~TwoWayListNode(); //destruktor listy
	void setValue(T val); //ustawia wartoœæ wêz³a
	T getValue(); //zwraca wartoœæ wêz³¹
	TwoWayListNode<T>* getNext(); //zwraca nastêpny wêze³
	TwoWayListNode<T>* getPrev(); //zwraca poprzedni wêze³
	void setNext(TwoWayListNode<T>* nextNode);// ustawia nastêpny wêze³
	void setPrev(TwoWayListNode<T>* prevNode);//ustawia poprzedni wêze³
};

#endif // !TwoWayListNode
