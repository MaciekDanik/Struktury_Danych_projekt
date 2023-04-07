#ifndef TwoWayList_H
#define TwoWayList_H

#include "TwoWayListNode.h"

using namespace std;

class TwoWayList
{
private:
	TwoWayListNode* head;
	TwoWayListNode* tail;
public:
	TwoWayList();
	~TwoWayList();
	void addNodeBack(string title, int rating);
	void delNode(); // usuwa element z poczatku
	void display();
};

#endif // !TwoWayList_H
