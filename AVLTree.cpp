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

	return node;
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

	return node;
}

template<class T>
AVLNode<T>* AVLTree<T>::Predecesor(AVLNode<T>* node)
{
	AVLNode<T>* tmpNode;
	if (node == nullptr)
	{
		return node;
	}
	else if (node == minValue(root))
	{
		return nullptr;
	}
	else if (node->getLeftSon() != nullptr)
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
	else if (node == maxValue(root))
	{
		return nullptr;
	}
	else if (node->getRightSon() != nullptr)
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
AVLNode<T>* AVLTree<T>::findNode(AVLNode<T>* node, T val)
{
	AVLNode<T>* tmpNode = node;
	if (node == nullptr)
	{
		return nullptr;
	}

	if (val == tmpNode->getValue())
	{
		return tmpNode;
	}
	else if (val < tmpNode->getValue())
	{
		tmpNode = tmpNode->getLeftSon();
		findNode(tmpNode, val);
	}
	else
	{
		tmpNode = tmpNode->getRightSon();
		findNode(tmpNode, val);
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
AVLNode<T>* AVLTree<T>::removeNode(AVLNode<T>* delNode)
{
	AVLNode<T>* tmpNode1;
	AVLNode<T>* tmpNode2;
	AVLNode<T>* tmpNode3;
	AVLNode<T>* tmpNode4;
	bool tangeld; // zagnie�dzenie

	if ((delNode->getLeftSon() != nullptr) && (delNode->getRightSon() != nullptr))
	{
		tmpNode4 = Predecesor(delNode);
		tmpNode1 = removeNode(tmpNode4);
		tangeld = false;
	}
	else
	{
		if (delNode->getLeftSon() != nullptr)
		{
			tmpNode1 = delNode->getLeftSon();
			delNode->setLeftSon(nullptr);
		}
		else
		{
			tmpNode1 = delNode->getRightSon();
			delNode->setRightSon(nullptr);
		}
		delNode->setBF(0);
		tangeld = true;
	}

	if (tmpNode1 != nullptr)
	{
		tmpNode1->setParent(delNode->getParent());
		tmpNode1->setLeftSon(delNode->getLeftSon());
		if (tmpNode1->getLeftSon() != nullptr)
		{
			tmpNode1->getLeftSon()->setParent(tmpNode1);
		}
		tmpNode1->setRightSon(delNode->getRightSon());
		if (tmpNode1->getRightSon() != nullptr)
		{
			tmpNode1->getRightSon()->setParent(tmpNode1);
		}
		tmpNode1->setBF(delNode->getBF());
	}

	if (delNode->getParent() != nullptr)
	{
		if (delNode->getParent()->getLeftSon() == delNode)
		{
			delNode->getParent()->setLeftSon(tmpNode1);
		}
		else
		{
			delNode->getParent()->setRightSon(tmpNode1);
		}
	}
	else
	{
		root = tmpNode1;
	}

	if (tangeld == true)
	{
		tmpNode2 = tmpNode1;
		tmpNode1 = delNode->getParent();

		while (tmpNode1 != nullptr)
		{
			if (tmpNode1->getBF() == 0) //przypadek 1
			{
				if (tmpNode1->getLeftSon() == tmpNode2)
				{
					tmpNode1->setBF(-1);
				}
				else
				{
					tmpNode1->setBF(1);
				}
				break;
			}
			else
			{
				if (((tmpNode1->getBF() == 1) && (tmpNode1->getLeftSon() == tmpNode2)) || ((tmpNode1->getBF() == -1) && (tmpNode1->getRightSon() == tmpNode2))) //[rzypadek 2
				{
					tmpNode1->setBF(0);
					tmpNode2 = tmpNode1;
					tmpNode1 = tmpNode1->getParent();
				}
				else
				{
					if (tmpNode1->getLeftSon() == tmpNode2)
					{
						tmpNode3 = tmpNode1->getRightSon();
					}
					else
					{
						tmpNode3 = tmpNode1->getLeftSon();
					}
					if (tmpNode3->getBF() == 0) //prztpadek 3A
					{
						if (tmpNode1->getBF() == 1)
						{
							singleLeftRotation(tmpNode1);
						}
						else
						{
							singleRightRotation(tmpNode1);
						}
						break;
					}
					else if (tmpNode1->getBF() == tmpNode3->getBF())//przyp 3B
					{
						if (tmpNode1->getBF() == 1)
						{
							singleLeftRotation(tmpNode1);
						}
						else
						{
							singleRightRotation(tmpNode1);
						}
						tmpNode2 = tmpNode3;
						tmpNode1 = tmpNode3->getParent();
					}
					else  //przypadek 3c
					{
						if (tmpNode1->getBF() == 1)
						{
							singleLeftRotation(tmpNode1);
						}
						else
						{
							singleRightRotation(tmpNode1);
						}
						tmpNode2 = tmpNode1->getParent();
						tmpNode1 = tmpNode2->getParent();
					}
				}
			}
		}
	}

	return delNode;
}

template<class T>
void AVLTree<T>::deleteTree(AVLNode<T>* del)
{
	while (root != nullptr)
	{
		removeNode(root);
	}
}

template class AVLTree<int>;
template class AVLTree<double>;
template class AVLTree<float>;