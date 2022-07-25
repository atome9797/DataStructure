#pragma once
class Deque 
{
public:
	Deque(int size);
	~Deque();

	bool empty()const;
	bool full() const;
	int size() const;
	int front() const;
	int back() const;
	void pushFront(const int data);
	void pushBack(const int data);
	int popFront();
	int popBack();
	void display() const;
private:
	int* elements = nullptr;
	int maxSize = 0;
	int dataSize = 0;
	int frontIndex = 0;
	int rearIndex = 0;
};