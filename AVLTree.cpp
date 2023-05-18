#include "AVLTree.h"
#include "AVLNode.h"
#include <iostream>

using namespace std;

template <class T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template<class T>
AVLTree<T>::~AVLTree()
{
	;
}

template<class T>
AVLNode<T>* AVLTree<T>::getRoot()
{
	return this->root;
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

	else if (NodeP->getLeftSon() == node)
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

	else if (NodeP->getLeftSon() == node)
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
	AVLNode<T>* NodeB = node->getRightSon();  //pocz�tkowo lewy syn w�z�a wzgl�dem kt�rego obracamy
	AVLNode<T>* NodeC = NodeB->getLeftSon();  //pocz�tkowo prawy syn w�z�a wzgl�dem kt�rego obracamy
	AVLNode<T>* NodeP = node->getParent();  //pocz�tkowo ojciec w�z�a wzgl�dem kt�rego obracamy

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
	else if (NodeP->getLeftSon() == node)
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

template<class T>
void AVLTree<T>::double_LR_Rotation(AVLNode<T>* node)
{
	AVLNode<T>* NodeB = node->getLeftSon();  //pocz�tkowo lewy syn w�z�a wzgl�dem kt�rego obracamy
	AVLNode<T>* NodeC = NodeB->getRightSon();  //pocz�tkowo prawy syn w�z�a wzgl�dem kt�rego obracamy
	AVLNode<T>* NodeP = node->getParent();  //pocz�tkowo ojciec w�z�a wzgl�dem kt�rego obracamy

	NodeB->setRightSon(NodeC->getLeftSon());
	if (NodeB->getRightSon() != nullptr)
	{
		NodeB->getRightSon()->setParent(NodeB);
	}
	node->setLeftSon(NodeC->getRightSon());
	if (node->getLeftSon() != nullptr)
	{
		node->getLeftSon()->setParent(node);
	}
	NodeC->setRightSon(node);
	NodeC->setLeftSon(NodeB);
	node->setParent(NodeC);
	NodeB->setParent(NodeC);
	NodeC->setParent(NodeP);

	if (NodeP == nullptr)
	{
		root = NodeC;
	}
	else if (NodeP->getLeftSon() == node)
	{
		NodeP->setLeftSon(NodeC);
	}
	else
	{
		NodeP->setRightSon(NodeC);
	}

	if (NodeC->getBF() == 1)
	{
		node->setBF(-1);
	}
	else
	{
		node->setBF(0);
	}

	if (NodeC->getBF() == -1)
	{
		NodeB->setBF(1);
	}
	else
	{
		NodeB->setBF(0);
	}

	NodeC->setBF(0);
}

template<class T>
void AVLTree<T>::insertNode(T val)
{
	AVLNode<T>* newNode = new AVLNode<T>; //w�ze� wstawiany
	AVLNode<T>* tmpNodeA = new AVLNode<T>; //w�ze� pomocniczy
	AVLNode<T>* tmpNodeB = new AVLNode<T>; //w�ze� pomocniczy
	bool status = false; //do balansowania drzew

	newNode->setValue(val); //przypisanie warto�ci do nowego w�z��

	///Wstawianie w�z�� do drzewea
	tmpNodeA = root;

	if (root == nullptr)  //je�lil nie ma korzenia to newNode staje si� korzeniem
	{
		root = newNode;
		return;
	}
	else
	{
		while (1)
		{
			if (val <= tmpNodeA->getValue())  //je�li warto�� nowego w�z�a jest <= wcze�niejszym
			{
				if (tmpNodeA->getLeftSon() == nullptr) //nowy w�ze� jest lewym synem je�li go nie by�o
				{
					tmpNodeA->setLeftSon(newNode);
					break;
				}
				tmpNodeA = tmpNodeA->getLeftSon(); //podr� w lewy-d� drzewa
			}
			else   //je�li warto�� nowego w�z�a jest > wcze�niejsze
			{
				if (tmpNodeA->getRightSon() == nullptr)   //nowy w�ze� jest prawym synem je�li go nie by�o
				{
					tmpNodeA->setRightSon(newNode);
					break;
				}
				tmpNodeA = tmpNodeA->getRightSon(); //podr� w prawy-d� drzewa
			}
		}

		newNode->setParent(tmpNodeA);   //ojcem nowego w�z�a jest w�ze� o "poziom" wy�ej
		///FAZA 2 r�wnowa�enie

		if (tmpNodeA->getBF() != 0)   //je�li bf= +/-1 ustawiamy 0, bo mia� jedngo syna
		{
			tmpNodeA->setBF(0);
		}
		else
		{
			if (tmpNodeA->getLeftSon() == newNode) //je�li lewym synem ojca jest nowy w�ze� - lewe poddrzewo d�u�sze
			{
				tmpNodeA->setBF(1);
			}
			else  //w przeciwnym razie prawe poddrzewo jest d�u�sze
			{
				tmpNodeA->setBF(-1);
			}

			tmpNodeB = tmpNodeA->getParent();

			while (tmpNodeB != nullptr) //dop�ki nie dojdziemy do korzenia
			{
				if (tmpNodeB->getBF() != 0)//jedno z poddrzew jest d�u�sze
				{
					status = true;
					break;
				}
				if (tmpNodeB->getLeftSon() == tmpNodeA)//je�li NodeA jest lewyn synem NodeB, lewe poddrzewo jest d�u�sze
				{
					tmpNodeB->setBF(1);
				}
				else //je�li NodeA jest lewyn synem NodeB, prawe poddrzewo jest d�u�sze
				{
					tmpNodeB->setBF(-1);
				}
				tmpNodeA = tmpNodeB;                 //przej�cie w g�r� drzewa
				tmpNodeB = tmpNodeB->getParent();
			}
			if (status == true)    // balance factor tmpNodeB = +/-1
			{
				if (tmpNodeB->getBF() == 1)
				{
					if (tmpNodeB->getRightSon() == tmpNodeA) //je�li tmpNodeA jest prawym synem tmpNodeB
					{
						tmpNodeB->setBF(0);
					}
					else if (tmpNodeA->getBF() == -1)
					{
						double_LR_Rotation(tmpNodeB);
					}
					else
					{
						singleLeftRotation(tmpNodeB);
					}
				}
				else
				{
					if (tmpNodeB->getLeftSon() == tmpNodeA) //je�li tmpNodeA jest lewym synem tmpNodeB
					{
						tmpNodeB->setBF(0);
					}
					else if (tmpNodeA->getBF() == 1)
					{
						double_RL_Rotation(tmpNodeB);
					}
					else
					{
						singleRightRotation(tmpNodeB);
					}
				}
			}
		}
	}
}

template<class T>
void AVLTree<T>::removeNode(AVLNode<T>* del)
{
}

template class AVLTree<int>;
template class AVLTree<double>;
template class AVLTree<float>;