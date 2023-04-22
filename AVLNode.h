#ifndef AVLNODE_H
#define AVLNODE_H

template <class T>
class AVLNode
{
private:
	AVLNode<T>* parent; //wskaŸnik na ojca wêz³a
	AVLNode<T>* leftSon; //wskaŸnik na lewego praweg wêz³a
	AVLNode<T>* rightSon; //wskaŸnik na lewego syna wêz³a
	T value;
	int balanceFactor; //wspó³czynnik równowagi
public:
	void setParent(AVLNode<T>* p); //ustawia ojca
	void setLeftSon(AVLNode<T>* l); //ustawia lewego syna
	void setRightSon(AVLNode<T>* r); //ustawia prawego syna
	void setValue(T val); //ustawia wartoœæ wêz³¹
	void setBF(int bf); // ustawia wspó³czynnik równowagi wêz³¹
	AVLNode<T>* getParent(); // zwraca ojca
	AVLNode<T>* getLeftSon(); //zwraca lewego syna
	AVLNode<T>* getRightSon(); //zwraca prawego syna
	T getValue(); //zwraca wartoœæ wêz³¹
	int getBF(); //zwraca BF wêz³a
};

#endif // !AVLNODE_H
