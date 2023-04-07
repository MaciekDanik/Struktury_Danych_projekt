#ifndef TwoWayListNode_H
#define TwoWayListNode_H

#include <string>

using namespace std;

class TwoWayListNode
{
private:
	int rating;
	string title;
	TwoWayListNode* next;
	TwoWayListNode* prev;
public:
	TwoWayListNode();
	~TwoWayListNode();
	int getRating();
	string getTitle();
	void setRating(int rating);
	void setTitle(string title);
	TwoWayListNode* getNext();
	TwoWayListNode* getPrev();
	void setNext(TwoWayListNode* nextNode);
	void setPrev(TwoWayListNode* prevNode);
};

#endif
