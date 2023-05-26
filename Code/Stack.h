#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
    int* arr;
    int capacity;   // max capacity
    int front;      //same as top or head
    int rear;       //simple base
    int count;      //current size

public:
    Stack(int);
    ~Stack();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
};

/*
Stack was made using the circular array implementation
*/