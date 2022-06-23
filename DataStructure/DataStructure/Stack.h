#pragma once
#include <iostream>

class Stack {
public:
	Stack(int size);
	bool isFull();
	bool isEmpty();
	char pop();
	void push(char element);
	void print();
private:
	int top;
	int MaxSize;
	char* stack;		
};




