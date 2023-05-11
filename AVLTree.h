#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <string>

using namespace std;

string cr, cl, cp; //nie wiem co to piszê z internetu akurat

template <class T>
class AVLTree
{
private:
	AVLNode<T>* root; //wskaŸnik na korzeñ drzewa
public:
	void singleRightRotation(AVLNode<T>* root, AVLNode<T>* node); // rotacja w prawo wzglêdem wêz³a
	void singleLeftRotation(AVLNode<T>* root, AVLNode<T>* node); // rotacja w lewo wzglêdem wêz³a
	void double_RL_Rotation(AVLNode<T>* root, AVLNode<T>* node); //najpierw rotacja w lewo a potem w prawo
	void double_LR_Rotation(AVLNode<T>* root, AVLNode<T>* node); //najpierw w prawo a potem w lewo

	void printTree(string sp, string sn, AVLNode<T>* V); // to siê zobaczy
	void insertNode(AVLNode<T>* root, T val); //wstawia wêze³ o wartoœci val do drzewa
	AVLNode<T>* Predecesor(AVLNode<T>* node); // zwraca poprzednika wêz³a node
	void findNode(AVLNode<T>* root, T val); //szuka wêz³a o zadanej wartoœci val
	void removeNode(AVLNode<T>* root, AVLNode<T>* del); //usuwa wêze³ podany jako del
};

#endif // !AVLTREE_H
