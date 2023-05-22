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

string cr = " ", cl = " ", cp = " ";

template <class T>
void printTree(string sp, string sn, AVLNode<T>* v)
{
	string s;

	if (v)
	{
		s = sp;
		if (sn == cr)
		{
			s[s.length() - 2] = ' ';
		}
		printTree(s + cp, cr, v->getRightSon());

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->getValue() << ":" << v->getBF() << endl;

		s = sp;
		if (sn == cl)
		{
			s[s.length() - 2] = ' ';
		}
		printTree(s + cp, cl, v->getLeftSon());
	}
}

int main()
{
	cr = " ";
	cl = " ";
	cp = " ";
	cr[0] = 218;
	cl[0] = 192;
	cp[0] = 179;
	cr[1] = 196;
	cl[1] = 196;

	Queue<int> queue;
	TwoWayList<float> List;
	lista_jednokierunkowa<float> OneWayList;
	AVLTree<int> drzewo;

	drzewo.insertNode(3);
	drzewo.insertNode(7);
	drzewo.insertNode(7);
	drzewo.insertNode(5);
	drzewo.insertNode(2);
	drzewo.insertNode(13);
	drzewo.insertNode(8);
	drzewo.insertNode(9);

	AVLNode<int>* del = drzewo.findNode(drzewo.getRoot(), 7);
	drzewo.removeNode(del);
	system("pause");

	printTree("", "", drzewo.getRoot());
	//Wczytywanie danych do pomiaru czasu ->
	 /*TwoWayList<int> czas_int;
	 TwoWayList<float> czas_float;
	 int* tablica=new int[1000000];
	 float* tablica1=new float[1000000];
	 fstream calkowite;
	 calkowite.open("C:\\Users\\Legion\\Desktop\\calkowite.txt", ios::in | ios::out |ios::app);
	 string linia;
	 int licznik=0;
	 while(getline(calkowite,linia))
	 {
		tablica[licznik]=stoi(linia);
		licznik++;
	 }
	 calkowite.close();
	fstream zmiennoprzecinkowe;
	 zmiennoprzecinkowe.open("C:\\Users\\Legion\\Desktop\\zmiennoprzecinkowe.txt", ios::in | ios::out |ios::app);
	 string linia1;
	 int licznik1=0;
	 while(getline(zmiennoprzecinkowe,linia1))
	 {
		tablica1[licznik1]=stof(linia1);
		licznik1++;
	 }
	 zmiennoprzecinkowe.close();

	cout<<"Chcesz pracowac na danych int czy float?"<<endl;
	cout<<"1. int, 2. float"<<endl;
	int wybur;
	cin>>wybur;
	if(wybur==1)
	czas_int.addNodeBack(tablica);
	if(wybur==2)
	czas_float.addNodeBack(tablica1);
	*/

	//cout << "root: " << drzewo.getRoot()->getValue() << endl;

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