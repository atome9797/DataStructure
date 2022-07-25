#pragma once

class Queue 
{
public:
	Queue(int size);
	~Queue();
	bool isEmpty();
	bool isFull();
	void enqueue(int element);
	int dequeue();
	int peek();
	void display();
private:
	int front = 0;
	int rear = 0;
	int _size = 0;
	int* elements = nullptr;

};