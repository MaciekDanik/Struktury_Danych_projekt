#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
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
	Queue<int> queue_int;
	Queue<float> queue_float
	TwoWayList<int> List;
	lista_jednokierunkowa<float> OneWayList;
	AVLTree<int> drzewo;

	int* tablica = new int[1000000];
	float* tablica1 = new float[1000000];
	const int DataQuantity = 10; //iloœæ danych

	fstream calkowite;
	calkowite.open("C:\\Users\\Legion\\Desktop\\calkowite.txt", ios::in | ios::out | ios::app);
	string linia;
	int licznik = 0;
	while (getline(calkowite, linia))
	{
		tablica[licznik] = stoi(linia);
		licznik++;
	}
	calkowite.close();
	fstream zmiennoprzecinkowe;
	zmiennoprzecinkowe.open("C:\\Users\\Legion\\Desktop\\zmiennoprzecinkowe.txt", ios::in | ios::out | ios::app);
	string linia1;
	int licznik1 = 0;
	while (getline(zmiennoprzecinkowe, linia1))
	{
		tablica1[licznik1] = stof(linia1);
		licznik1++;
	}
	zmiennoprzecinkowe.close();

	auto t1 = chrono::high_resolution_clock::now();
	///_________________________________________________________________________________
	for (int i = 0; i < DataQuantity; i++)
	{
		//tutaj dodawanie
		//List.addNodeBack(i);
	}
	///_________________________________________________________________________________

	auto t2 = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
	cout << "Czas dodawania: " << time.count() * 1e-9 << " sekundy" << endl;

	List.display();//do testów
	
	auto t3 = chrono::high_resolution_clock::now();
	///_________________________________________________________________________________
	for (int i = 0; i < DataQuantity; i++)
	{
            queue_int.addNodeBack(tablica[i]);
	}
	///_________________________________________________________________________________

	auto t4 = chrono::high_resolution_clock::now();
	auto time1 = chrono::duration_cast<chrono::nanoseconds>(t4 - t3);
	cout << "Czas dodawania: " << time1.count() * 1e-9 << " sekundy" << endl;

	drzewo.insertNode(3);
	drzewo.insertNode(7);
	drzewo.insertNode(11);
	drzewo.insertNode(5);
	drzewo.insertNode(2);
	drzewo.insertNode(13);
	drzewo.insertNode(8);
	drzewo.insertNode(9);
	//	cout << drzewo.Predecesor(drzewo.findNode(drzewo.getRoot(), 2))->getValue() << endl;

	//drzewo.removeNode(drzewo.findNode(drzewo.getRoot(), 7));
	drzewo.deleteTree(drzewo.getRoot());
	system("pause");


	//cout << "root: " << drzewo.getRoot()->getValue() << endl;

	//for (int i = 1; i <= 10; i++)
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
