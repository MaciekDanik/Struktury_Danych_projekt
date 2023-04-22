#ifndef AVLNODE_H
#define AVLNODE_H

template <class T>
class AVLNode
{
private:
	AVLNode<T>* parent; //wska�nik na ojca w�z�a
	AVLNode<T>* leftSon; //wska�nik na lewego praweg w�z�a
	AVLNode<T>* rightSon; //wska�nik na lewego syna w�z�a
	T value;
	int balanceFactor; //wsp�czynnik r�wnowagi
public:
	void setParent(AVLNode<T>* p); //ustawia ojca
	void setLeftSon(AVLNode<T>* l); //ustawia lewego syna
	void setRightSon(AVLNode<T>* r); //ustawia prawego syna
	void setValue(T val); //ustawia warto�� w�z��
	void setBF(int bf); // ustawia wsp�czynnik r�wnowagi w�z��
	AVLNode<T>* getParent(); // zwraca ojca
	AVLNode<T>* getLeftSon(); //zwraca lewego syna
	AVLNode<T>* getRightSon(); //zwraca prawego syna
	T getValue(); //zwraca warto�� w�z��
	int getBF(); //zwraca BF w�z�a
};

#endif // !AVLNODE_H
