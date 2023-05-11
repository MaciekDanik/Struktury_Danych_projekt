#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <string>

using namespace std;

string cr, cl, cp; //nie wiem co to pisz� z internetu akurat

template <class T>
class AVLTree
{
private:
	AVLNode<T>* root; //wska�nik na korze� drzewa
public:
	void singleRightRotation(AVLNode<T>* root, AVLNode<T>* node); // rotacja w prawo wzgl�dem w�z�a
	void singleLeftRotation(AVLNode<T>* root, AVLNode<T>* node); // rotacja w lewo wzgl�dem w�z�a
	void double_RL_Rotation(AVLNode<T>* root, AVLNode<T>* node); //najpierw rotacja w lewo a potem w prawo
	void double_LR_Rotation(AVLNode<T>* root, AVLNode<T>* node); //najpierw w prawo a potem w lewo

	void printTree(string sp, string sn, AVLNode<T>* V); // to si� zobaczy
	void insertNode(AVLNode<T>* root, T val); //wstawia w�ze� o warto�ci val do drzewa
	AVLNode<T>* Predecesor(AVLNode<T>* node); // zwraca poprzednika w�z�a node
	void findNode(AVLNode<T>* root, T val); //szuka w�z�a o zadanej warto�ci val
	void removeNode(AVLNode<T>* root, AVLNode<T>* del); //usuwa w�ze� podany jako del
};

#endif // !AVLTREE_H
