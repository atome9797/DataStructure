#include "Queue.h"
#include <iostream>

Queue::Queue(int size)
{
	front = 0;
	rear = 0;
	_size = size;
	elements = new int[size];
}

Queue::~Queue()
{
	delete[] elements;
}

bool Queue::isEmpty()
{
	return front == rear;
}

bool Queue::isFull()
{
	return rear == _size;
}

//»ðÀÔ
void Queue::enqueue(int element)
{
	if (isFull())
	{
		std::cout << "Error : Queue is Full!" << std::endl;
	}
	else
	{
		elements[rear++] = element;
	}
}

//»èÁ¦
int Queue::dequeue()
{
	if (isEmpty())
	{
		std::cout << "Error : Queue is Empty!" << std::endl;
	}
	else
	{
		return elements[front++];
	}
}

int Queue::peek()
{
	if (isEmpty())
	{
		std::cout << "Error : Queue is Empty!" << std::endl;
	}
	else
	{
		return elements[++front];
	}
}

void Queue::display()
{
	for (int i = front; i < rear; i++)
	{
		std::cout << elements[i] << " ";
	}

	std::cout << std::endl;
}


int main()
{
	Queue que(5);
	que.enqueue(1);
	que.enqueue(2);
	que.enqueue(3);
	que.enqueue(4);
	que.enqueue(5);
	que.display();
	std::cout << que.dequeue() << std::endl; //trueÀÏ¶§ 1³ª¿È
	que.enqueue(6);

	que.display();
	
}