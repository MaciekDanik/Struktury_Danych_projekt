#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <string>

using namespace std;

//string cr = " ", cl = " ", cp = " "; //nie wiem co to piszê z internetu akurat

template <class T>
class AVLTree
{
private:
	AVLNode<T>* root; //wskaŸnik na korzeñ drzewa
public:
	AVLTree();
	~AVLTree();
	void singleRightRotation(AVLNode<T>* node); // rotacja w prawo wzglêdem wêz³a
	void singleLeftRotation(AVLNode<T>* node); // rotacja w lewo wzglêdem wêz³a
	void double_RL_Rotation(AVLNode<T>* node); //najpierw rotacja w lewo a potem w prawo
	void double_LR_Rotation(AVLNode<T>* node); //najpierw w prawo a potem w lewo

	AVLNode<T>* getRoot();  // do testow
	//void printTree(string sp, string sn, AVLNode<T>* v); // to siê zobaczy
	AVLNode<T>* minValue(AVLNode<T>* node); //zwraca wêze³ o najmniejszej wartoœci
	AVLNode<T>* maxValue(AVLNode<T>* node); //zwraca wêze³ o najwiêkszej wartoœci
	AVLNode<T>* Predecesor(AVLNode<T>* node); // zwraca poprzednika wêz³a node
	AVLNode<T>* Succesor(AVLNode<T>* node); // zwraca nastêpcê wêz³a node
	void findNode(T val); //szuka wêz³a o zadanej wartoœci val
	void insertNode(T val); //wstawia wêze³ o wartoœci val do drzewa
	void removeNode(AVLNode<T>* del); //usuwa wêze³ podany jako del
};

#endif // !AVLTREE_H
