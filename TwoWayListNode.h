#ifndef TwoWayListNode_H
#define TwoWayListNode_H

template <class T>
class TwoWayListNode
{
private:
	T value;
	TwoWayListNode<T>* next; //wska�nik na nast�pny element
	TwoWayListNode<T>* prev; //wska�nik na poprzedni element
public:
	TwoWayListNode(); //konstruktor list
	~TwoWayListNode(); //destruktor listy
	void setValue(T val); //ustawia warto�� w�z�a
	T getValue(); //zwraca warto�� w�z��
	TwoWayListNode<T>* getNext(); //zwraca nast�pny w�ze�
	TwoWayListNode<T>* getPrev(); //zwraca poprzedni w�ze�
	void setNext(TwoWayListNode<T>* nextNode);// ustawia nast�pny w�ze�
	void setPrev(TwoWayListNode<T>* prevNode);//ustawia poprzedni w�ze�
};

#endif // !TwoWayListNode
