#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <string>

using namespace std;

//string cr = " ", cl = " ", cp = " "; //nie wiem co to pisz� z internetu akurat

template <class T>
class AVLTree
{
private:
	AVLNode<T>* root; //wska�nik na korze� drzewa
public:
	AVLTree();
	~AVLTree();
	void singleRightRotation(AVLNode<T>* node); // rotacja w prawo wzgl�dem w�z�a
	void singleLeftRotation(AVLNode<T>* node); // rotacja w lewo wzgl�dem w�z�a
	void double_RL_Rotation(AVLNode<T>* node); //najpierw rotacja w lewo a potem w prawo
	void double_LR_Rotation(AVLNode<T>* node); //najpierw w prawo a potem w lewo

	AVLNode<T>* getRoot();  // do testow
	//void printTree(string sp, string sn, AVLNode<T>* v); // to si� zobaczy
	AVLNode<T>* minValue(AVLNode<T>* node); //zwraca w�ze� o najmniejszej warto�ci
	AVLNode<T>* maxValue(AVLNode<T>* node); //zwraca w�ze� o najwi�kszej warto�ci
	AVLNode<T>* Predecesor(AVLNode<T>* node); // zwraca poprzednika w�z�a node
	AVLNode<T>* Succesor(AVLNode<T>* node); // zwraca nast�pc� w�z�a node
	void findNode(T val); //szuka w�z�a o zadanej warto�ci val
	void insertNode(T val); //wstawia w�ze� o warto�ci val do drzewa
	void removeNode(AVLNode<T>* del); //usuwa w�ze� podany jako del
};

#endif // !AVLTREE_H
