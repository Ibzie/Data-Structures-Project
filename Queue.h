#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;
class Queue
{
    int* arr;       
    int capacity;   // max capacity
    int front;     
    int rear;       
    int count;      //current size
    int* dx, dy;

public:
    Queue(int);
    ~Queue();        
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    int dequeue();
    void enqueue(int x);
    int row_count, col_count;
};
/*
Queue was made using the circular array implementation
*/