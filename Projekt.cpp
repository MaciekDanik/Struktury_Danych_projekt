#include <iostream>
#include "QueueNode.h"
#include "Queue.h"
#include "TwoWayListNode.h"
#include "TwoWayList.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include "lista.h"
#include "kwota.h"
#include "AVLNode.h"
#include "AVLTree.h"

using namespace std;

int randomNum(int maxWartosc)
{
	return (rand() % maxWartosc);
}

int main()
{
	Queue<int> queue;
	TwoWayList<float> List;
	lista_jednokierunkowa<float> OneWayList;
	//for (float i = 1.0; i <= 6.0; i = i + 0.5)
	//{
	//	//queue.addNodeBack(i);
	//	List.addNodeBack(i);
	//}
	//List.display();
	//List.delNodeAtPosition(1);
	//List.display();
	//List.addNodeFront(4.20);
	//List.display();
	//List.delNodeAtPosition(4);
	//List.display();

	//queue.display();
	//queue.delFirstNode();
	//queue.display();
}