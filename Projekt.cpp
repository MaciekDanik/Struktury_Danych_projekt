#include <iostream>
#include "QueueNode.h"
#include "Queue.h"
#include <string>

using namespace std;

int main()
{
	Queue<int> queue;

	for (int i = 1; i <= 11; i++)
	{
		queue.addNodeBack(i);
	}

	queue.display();
	queue.delFirstNode();
	queue.display();
}