#include "Circle_Queue.h"
#include <iostream>

using namespace std;

CircleQueue::CircleQueue(int size)
{
    front = 0;
    rear = 0;
    _size = size + 1;
    elements = new int[_size];
}

CircleQueue::~CircleQueue()
{
    delete[] elements;
}

bool CircleQueue::isEmpty()
{
    return front == rear;
}

bool CircleQueue::isFull()
{
    return (rear + 1) % _size == front;
}

//삽입 삭제가 되면서 front와 rear의 위치가 변한다.

//삽입
void CircleQueue::enqueue(int element)
{
    if (isFull())
    {
        cout << "Error : Queue is Full!" << endl;
    }
    else
    {
        rear = (rear + 1) % _size;
        elements[rear] = element;
    }
}

//삭제
int CircleQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Error : Queue is Empty!" << endl;
    }
    else
    {
        front = (front + 1) % _size;
        return elements[front];
    }
}

//스택이 비어있지 않으면 맨위 요소 반환
int CircleQueue::peek()
{
    if (isEmpty())
    {
        cout << "Error : Queue is Empty!" << endl;
    }
    else 
    {
        return elements[(front + 1) % _size];
    }
}

void CircleQueue::display()
{
    int maxi = (front < rear) ? rear : rear + _size;
    for (int i = front + 1; i <= maxi; i++)
    {
        cout << elements[i % _size] << " ";
    }

    cout << endl;
}


int main()
{

    CircleQueue crque(5);
    crque.enqueue(1);
    crque.enqueue(2);
    crque.enqueue(3);
    crque.enqueue(4);
    crque.enqueue(5);
    crque.enqueue(6);
    crque.enqueue(7);
    crque.dequeue();

    crque.display();



    return 0;
}