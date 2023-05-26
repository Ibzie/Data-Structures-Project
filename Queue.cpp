#include "Queue.h"

Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
    const int dx[] = { +1, 0, -1, 0 };
    const int dy[] = { 0, +1, 0, -1 };
}
Queue::~Queue() {
    delete[] arr;
}
int Queue::dequeue()
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
void Queue::enqueue(int item)
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
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
    }
    return arr[front];
}
int Queue::size() {
    return count;
}
bool Queue::isEmpty() {
    return (size() == 0);
}
bool Queue::isFull() {
    return (size() == capacity);
}
//void Queue::readPic(Picture Pic)
//{
//    int l = Pic.getLen();
//    int h = Pic.getHeight();
//
//    for (int i = 0; i < l; i++)
//    {
//        for (int j = 0; j < h; j++)
//        {
//            enqueue(Pic.getPixel(i, j));
//        }
//    }
//}