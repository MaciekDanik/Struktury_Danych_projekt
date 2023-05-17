#include "AVLTree.h"
#include "AVLNode.h"

using namespace std;

template<class T>
void AVLTree<T>::printTree(string sp, string sn, AVLNode<T>* v)
{
	string s;

	if (v)
	{
		s = sp;
		if (sn == cr)
		{
			s[s.length() - 2] = ' ';
		}
		printTree(s + cp, cr, v->getRightSon());

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->getValue() << ":" << v->getBF() << endl;

		s = sp;
		if (sn == cl)
		{
			s[s.length() - 2] = ' ';
		}
		printTree(s + cp, cl, v->getLeftSon());
	}
}

template<class T>
AVLNode<T>* AVLTree<T>::minValue()
{
	if (root == nullptr)
	{
		return root;
	}

	while (root->getLeftSon() != nullptr)
	{
		root = root->getLeftSon();
	}

	return root;
}

template<class T>
AVLNode<T>* AVLTree<T>::maxValue()
{
	if (root == nullptr)
	{
		return root;
	}

	while (root->getRightSon() != nullptr)
	{
		root = root->getRightSon();
	}

	return root;
}

template<class T>
void AVLTree<T>::findNode(T val)
{
	if (root == nullptr)
	{
		cout << "Drzewo jest puste." << endl;
		return;
	}

	if (val == root)
	{
		cout << "Znaleziono wezel o wartosci: " << val << endl;
	}
	else if (val < root)
	{
		root = root->getLeftSon();
		findNode(root, val);
	}
	else
	{
		root = root->getRightSon();
		findNode(root, val);
	}
}

template<class T>
void AVLTree<T>::singleRightRotation(AVLNode<T>* node)
{
	AVLNode<T>* tmpSon = node->getRightSon();
	AVLNode<T>* tmpParent = node->getParent();

	node->setRightSon(tmpSon->getLeftSon());
	if (node->getRightSon() != nullptr)
	{
		node->getRightSon()->setParent(node);
	}

	tmpSon->setLeftSon(node);
	tmpSon->setParent(tmpParent);
	node->setParent(tmpSon);

	if (tmpParent == nullptr)
	{
		root = tmpSon;
	}

	if (tmpParent->getLeftSon() == node)
	{
		tmpParent->setLeftSon(tmpSon);
	}
	else
	{
		tmpParent->setRightSon(tmpSon);
	}

	if (tmpSon->getBF() == -1)
	{
		node->setBF(0);
		tmpSon->setBF(0);
	}
	else
	{
		node->setBF(-1);
		tmpSon->setBF(1);
	}
}

template<class T>
void AVLTree<T>::singleLeftRotation(AVLNode<T>* node)
{
	AVLNode<T>* tmpSon = node->getLeftSon();
	AVLNode<T>* tmpParent = node->getParent();

	node->setLeftSon(tmpSon->getRightSon());

	if (node->getLeftSon() != nullptr)
	{
		node->getLeftSon()->setParent(node);
	}

	tmpSon->setRightSon(node);
	tmpSon->setParent(tmpParent);
	node->setParent(tmpSon);

	if (tmpParent == nullptr)
	{
		root = tmpSon;
	}

	if (tmpParent->getLeftSon() == node)
	{
		tmpParent->setLeftSon(tmpSon);
	}
	else
	{
		tmpParent->setRightSon(tmpSon);
	}

	if (tmpSon->getBF() == 1)
	{
		node->setBF(0);
		tmpSon->setBF(0);
	}
	else
	{
		node->setBF(1);
		tmpSon->setBF(-1);
	}
}