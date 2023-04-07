#include "TwoWayListNode.h"

TwoWayListNode::TwoWayListNode()
{
	rating = 0;
	title = "";
}

TwoWayListNode::~TwoWayListNode() {}

int TwoWayListNode::getRating()
{
	return this->rating;
}

string TwoWayListNode::getTitle()
{
	return this->title;
}

void TwoWayListNode::setRating(int rating)
{
	this->rating = rating;
}

void TwoWayListNode::setTitle(string title)
{
	this->title = title;
}

TwoWayListNode* TwoWayListNode::getNext()
{
	return this->next;
}

TwoWayListNode* TwoWayListNode::getPrev()
{
	return this->prev;
}

void TwoWayListNode::setNext(TwoWayListNode* nextNode)
{
	this->next = nextNode;
}

void TwoWayListNode::setPrev(TwoWayListNode* prevNode)
{
	this->prev = prevNode;
}