#include "AVLTree.h"
#include "AVLNode.h"

using namespace std;

template<class T>
void AVLTree<T>::singleRightRotation(AVLNode<T>* root, AVLNode<T>* node)
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