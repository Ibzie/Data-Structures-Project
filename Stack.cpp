#include "Stack.h"

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
Stack::~Stack() {
    delete[] arr;
}
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Tis empty";
        return -1111111;
    }
    int x = arr[front];
    cout << "Removing " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}
void Stack::push(int item)
{
    if (isFull())
    {
        cout << "Overflow\n";
    }
    cout << "Inserting " << item << endl;
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
    }
    return arr[front];
}
int Stack::size() {
    return count;
}
bool Stack::isEmpty() {
    return (size() == 0);
}
bool Stack::isFull() {
    return (size() == capacity);
}

//void Stack::readPic(Picture Pic)
//{
//    int l = Pic.getLen();
//    int h = Pic.getHeight();
//
//    for (int i = 0; i < l; i++)
//    {
//        for (int j = 0; j < h; j++)
//        {
//            push(Pic.getPixel(i, j));
//        }
//    }
//}