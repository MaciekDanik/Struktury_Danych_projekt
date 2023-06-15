#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include<random>
#include <algorithm>
#include <time.h>
#include "QueueNode.h"
#include "Queue.h"
#include "TwoWayListNode.h"
#include "TwoWayList.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
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
	Queue<float> queue_float;
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
	/*
	//dodawanie do kolejki ->
	auto t3 = chrono::high_resolution_clock::now();
	///_________________________________________________________________________________
	for (int i = 0; i < DataQuantity; i++)
	{
		//queue_float.addNodeBack(tablica1[i]);
			queue_int.addNodeBack(tablica[i]);
	}
	///_________________________________________________________________________________

	auto t4 = chrono::high_resolution_clock::now();
	auto time1 = chrono::duration_cast<chrono::nanoseconds>(t4 - t3);
	cout << "Czas dodawania: " << time1.count() * 1e-9 << " sekundy" << endl;
	// Usuwanie z kolejki ->
	auto t5=chrono::high_resolution_clock::now();
		for(int i=0; i<DataQuantity;i++)
		{
			queue_int.delFirstNode();
		//queue_float.delFirstNode();
		}
		auto t6=chrono::high_resolution_clock::now();
		auto time2 =chrono::duration_cast<chrono::nanoseconds>(t6 - t5);
		cout<<"Czas usuwania: "<<time2.count()*1e-9<<" sekundy"<<endl;
	*/

	vector<unsigned int> dane;
	for (int i = 0; i < 10000000; i++)
	{
		dane.push_back(i);
	}

	auto rng = default_random_engine{};
	shuffle(dane.begin(), dane.end(), rng);

	for (auto x : dane)
	{
		drzewo.insertNode(x);
	}

	clock_t start = clock();
	cout << start << " clocks" << endl;
	//cout << drzewo.Predecesor(drzewo.findNode(drzewo.getRoot(), 7))->getValue() << endl;
	AVLNode<int>* temp = drzewo.findNode(drzewo.getRoot(), 555555);
	cout << temp->getValue() << endl;
	//cout << drzewo.Succesor(drzewo.findNode(drzewo.getRoot(), temp->getValue()))->getValue() << endl;
	clock_t stop = clock();
	clock_t result = stop - start;

	//stop / (CLOCKS_PER_SEC * 1000);
	cout << stop << " clocks" << endl;
	cout << result << " clocks" << endl;
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

//Szukanie na nastepnika/poprzednika na liscie dwu-kier:

/*
TwoWayListNode<int>* tep;
TwoWayListNode<int>* znal;
int val=tablica[1000000-1];
auto t1=chrono::high_resolution_clock::now();
znal=czas_int.findNode(tep,val);
auto t2=chrono::high_resolution_clock::now();
auto time =chrono::duration_cast<chrono::nanoseconds>(t2 - t1);
cout<<"Czas szukania: "<<time.count()<<" sekundy"<<endl;
int val1=znal->getValue();
cout<<"To powinna byc wartosc: "<<endl;
cout<<val1<<endl;
TwoWayListNode<int>* znal1;
auto t3=chrono::high_resolution_clock::now();
znal1=czas_int.Succesor(znal);
auto t4=chrono::high_resolution_clock::now();
auto time1 =chrono::duration_cast<chrono::nanoseconds>(t4 - t3);
cout<<"Czas szukania nastepnika: "<<time1.count()<<" sekundy"<<endl;
int val2=znal1->getValue();
cout<<"To powinna byc wartosc nastepnika: "<<endl;
cout<<val2<<endl;
//poprzednik
TwoWayListNode<int>* znal2;
auto t5=chrono::high_resolution_clock::now();
znal2=czas_int.Predecesor(znal);
auto t6=chrono::high_resolution_clock::now();
auto time2 =chrono::duration_cast<chrono::nanoseconds>(t6 - t5);
cout<<"Czas szukania poprzednika: "<<time2.count()<<" sekundy"<<endl;
int val3=znal2->getValue();
cout<<"To powinna byc wartosc poprzednika: "<<endl;
cout<<val3;
*/
//Szukanie na nastepnika/poprzednika na AVL:
	/*
   AVLNode<int>* znal;
   int val=tablica[300000];
   znal=czas_int.findNode(czas_int.getRoot(),val);
   int val1=znal->getValue();
   cout<<"To powinna byc wartosc: "<<endl;
   cout<<val1<<endl;
   AVLNode<int>* znal1;
   auto t3=chrono::high_resolution_clock::now();
   znal1=czas_int.Succesor(znal);
   auto t4=chrono::high_resolution_clock::now();
   auto time1 =chrono::duration_cast<chrono::nanoseconds>(t4 - t3);
   cout<<"Czas szukania nastepnika: "<<time1.count()<<" sekundy."<<endl;
   cout<<"To powinna byc wartosc nastepnika: "<<endl;
   int val2=0;
   val2=znal1->getValue();
   cout<<val2<<endl;
	*/
}