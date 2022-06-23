#include "Stack.h"
#include <iostream>
#include <stack>

std::stack<int> stack1;

Stack::Stack(int size)
{
	stack = new char [size];
	top = -1;
	MaxSize = size;
}

bool Stack::isFull()
{
	if (top == MaxSize - 1)
	{
		return true;
	}
	return false;
}

bool Stack::isEmpty()
{
	if (-1 == top)
	{
		return true;
	}

	return false;
}

char Stack::pop()
{
	if (!isEmpty())
	{
		return stack[top--];
	}
}

void Stack::push(char element)
{
	if (!isFull())
	{
		stack[++top] = element;
	}
}

void Stack::print()
{
	for (int i = 0; i < top + 1; i++)
	{
		std::cout << stack[i] << "\n";
	}
}


int main()
{
	Stack stack(5);
	stack.push('a');
	if (stack.isEmpty())
	{
		std::cout <<  "비어있음" << "\n";
	}
	stack.pop();
	stack.pop();
	stack.push('b');
	stack.print();
	
}