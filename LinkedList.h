#pragma once
#include "Node.h"
#include "Array.h"
class LinkedList
{
	Node* head;

public:
	LinkedList() { head = NULL; }
	void insertNode(int);
	void printList();
	void deleteNode(int);
	int getCurrentData();
	int popHead();
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else return false;
	}
	void WriteListToFile(string);
	int noBlack();
	//void normalize();//to remove arithematic series
	void backToImage(int);
	void toNegative(int);
};