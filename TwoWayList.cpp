#include "TwoWayList.h"
#include <iostream>

using namespace std;

TwoWayList::TwoWayList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

TwoWayList::~TwoWayList() {}

void TwoWayList::addNodeBack(string title, int rating)
{
	TwoWayListNode* newNode = new TwoWayListNode;
	newNode->setNext(nullptr);
	newNode->setRating(rating);
	newNode->setTitle(title);

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
}

void TwoWayList::delFirstNode()
{
	TwoWayListNode* nodePtr;

	if (head == nullptr)
	{
		return;
	}
	else
	{
		nodePtr = head->getNext();
		delete head;
		head = nodePtr;
	}
}

void TwoWayList::display()
{
	if (head)
	{
		TwoWayListNode* nodePtr = head;
		cout << "Zapisana kolejka: " << endl;
		while (nodePtr->getNext())
		{
			int tmpRating = nodePtr->getRating();
			string tmpTitle = nodePtr->getTitle();
			cout << tmpTitle << " : " << tmpRating << endl;   //wszystkie poza ostatnim
			nodePtr = nodePtr->getNext();
		}
		int tmpRating = nodePtr->getRating();
		string tmpTitle = nodePtr->getTitle();
		cout << tmpTitle << " : " << tmpRating << endl;   //ostatni element
	}
	cout << endl;
}