#include<iostream>
#include "LinkedList.h"
using namespace std;
#include "LinkedList.h"
//struct Node2
//{
//public:
//	int data;
//	Node2* next;
//};
class Hash
{
	int BUCKET;    // No. of buckets
	Node** table;
public:
	Hash(int size);
	int hashing(int key);
	void insert(int key);
	void Display_Hash();
	void Question6(Picture P);
	bool find(Picture P);
};