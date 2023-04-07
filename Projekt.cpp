#include <iostream>
#include "TwoWayListNode.h"
#include "TwoWayList.h"
#include <string>

using namespace std;

int main()
{
	TwoWayList list;

	for (int i = 1; i <= 11; i++)
	{
		list.addNodeBack("a", i);
	}

	list.display();
	list.delFirstNode();
	list.display();
}