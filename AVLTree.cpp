#include "AVLTree.h"
#include "AVLNode.h"
#include <iostream>

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
AVLNode<T>* AVLTree<T>::minValue(AVLNode<T>* node)
{
	if (node == nullptr)
	{
		return node;
	}

	while (node->getLeftSon() != nullptr)
	{
		node = node->getLeftSon();
	}

	return root;
}

template<class T>
AVLNode<T>* AVLTree<T>::maxValue(AVLNode<T>* node)
{
	if (node == nullptr)
	{
		return node;
	}

	while (node->getRightSon() != nullptr)
	{
		node = node->getRightSon();
	}

	return root;
}

template<class T>
AVLNode<T>* AVLTree<T>::Predecesor(AVLNode<T>* node)
{
	AVLNode<T>* tmpNode;
	if (node == nullptr)
	{
		return node;
	}

	if (node->getLeftSon() != nullptr)
	{
		return maxValue(node->getLeftSon());
	}
	else
	{
		tmpNode = node->getParent();

		while (tmpNode != nullptr && node == tmpNode->getLeftSon())
		{
			node = tmpNode;
			tmpNode = tmpNode->getParent();
		}
		return tmpNode;
	}
}

template<class T>
AVLNode<T>* AVLTree<T>::Succesor(AVLNode<T>* node)
{
	AVLNode<T>* tmpNode;
	if (node == nullptr)
	{
		return node;
	}

	if (node->getRightSon() != nullptr)
	{
		return minValue(node->getRightSon());
	}
	else
	{
		tmpNode = node->getParent();
		while (tmpNode != nullptr && node == tmpNode->getRightSon())
		{
			node = tmpNode;
			tmpNode = tmpNode->getParent();
		}
		return tmpNode;
	}
}

template<class T>
void AVLTree<T>::findNode(T val)
{
	if (root == nullptr)
	{
		cout << "Drzewo jest puste." << endl;
		return;
	}

	if (val == root->getValue())
	{
		cout << "Znaleziono wezel o wartosci: " << val << endl;
	}
	else if (val < root->getValue())
	{
		root = root->getLeftSon();
		findNode(val);
	}
	else
	{
		root = root->getRightSon();
		findNode(val);
	}
}

template<class T>
void AVLTree<T>::singleRightRotation(AVLNode<T>* node)
{
	AVLNode<T>* NodeB = node->getRightSon();
	AVLNode<T>* NodeP = node->getParent();

	node->setRightSon(NodeB->getLeftSon());
	if (node->getRightSon() != nullptr)
	{
		node->getRightSon()->setParent(node);
	}

	NodeB->setLeftSon(node);
	NodeB->setParent(NodeP);
	node->setParent(NodeB);

	if (NodeP == nullptr)
	{
		root = NodeB;
	}

	if (NodeP->getLeftSon() == node)
	{
		NodeP->setLeftSon(NodeB);
	}
	else
	{
		NodeP->setRightSon(NodeB);
	}

	if (NodeB->getBF() == -1)
	{
		node->setBF(0);
		NodeB->setBF(0);
	}
	else
	{
		node->setBF(-1);
		NodeB->setBF(1);
	}
}

template<class T>
void AVLTree<T>::singleLeftRotation(AVLNode<T>* node)
{
	AVLNode<T>* NodeB = node->getLeftSon();
	AVLNode<T>* NodeP = node->getParent();

	node->setLeftSon(NodeB->getRightSon());

	if (node->getLeftSon() != nullptr)
	{
		node->getLeftSon()->setParent(node);
	}

	NodeB->setRightSon(node);
	NodeB->setParent(NodeP);
	node->setParent(NodeB);

	if (NodeP == nullptr)
	{
		root = NodeB;
	}

	if (NodeP->getLeftSon() == node)
	{
		NodeP->setLeftSon(NodeB);
	}
	else
	{
		NodeP->setRightSon(NodeB);
	}

	if (NodeB->getBF() == 1)
	{
		node->setBF(0);
		NodeB->setBF(0);
	}
	else
	{
		node->setBF(1);
		NodeB->setBF(-1);
	}
}

template<class T>
void AVLTree<T>::double_RL_Rotation(AVLNode<T>* node)
{
	AVLNode<T>* NodeB = node->getRightSon();  //pocz¹tkowo lewy syn wêz³a wzglêdem którego obracamy
	AVLNode<T>* NodeC = NodeB->getLeftSon();  //pocz¹tkowo prawy syn wêz³a wzglêdem którego obracamy
	AVLNode<T>* NodeP = node->getParent();  //pocz¹tkowo ojciec wêz³a wzglêdem którego obracamy

	NodeB->setLeftSon(NodeC->getRightSon());
	if (NodeB->getLeftSon() != nullptr)
	{
		NodeB->getLeftSon()->setParent(NodeB);
	}
	node->setRightSon(NodeC->getLeftSon());
	if (node->getRightSon() != nullptr)
	{
		node->getRightSon()->setParent(node);
	}
	NodeC->setLeftSon(node);
	NodeC->setRightSon(NodeB);
	node->setParent(NodeC);
	NodeB->setParent(NodeC);
	NodeC->setParent(NodeP);

	if (NodeP == nullptr)
	{
		root = NodeC;
	}
	if (NodeP->getLeftSon() == node)
	{
		NodeP->setLeftSon(NodeC);
	}
	else
	{
		NodeP->setRightSon(NodeC);
	}

	if (NodeC->getBF() == -1)
	{
		node->setBF(1);
	}
	else
	{
		node->setBF(0);
	}

	if (NodeC->getBF() == 1)
	{
		NodeB->setBF(-1);
	}
	else
	{
		NodeB->setBF(0);
	}

	NodeC->setBF(0);
}

template class AVLTree<int>;
template class AVLTree<double>;
template class AVLTree<float>;