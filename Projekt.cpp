#include <iostream>
#include "QueueNode.h"
#include "Queue.h"
#include "TwoWayListNode.h"
#include "TwoWayList.h"
#include <string>

using namespace std;

int main()
{
	Queue<int> queue;
	TwoWayList<float> Lista2;

	for (float i = 1.0; i <= 6.0; i = i + 0.5)
	{
		//queue.addNodeBack(i);
		Lista2.addNodeBack(i);
	}
	Lista2.display();
	Lista2.delNodeAtPosition(1);
	Lista2.display();
	Lista2.addNodeFront(4.20);
	Lista2.display();
	Lista2.delNodeAtPosition(4);
	Lista2.display();

	//queue.display();
	//queue.delFirstNode();
	//queue.display();
}