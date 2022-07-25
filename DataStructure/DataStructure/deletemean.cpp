#include <iostream>

struct A
{
	A() { std::cout << "Constructor"; }
	~A() { std::cout << "Desturctor"; }
};

class Node
{
public:
	Node(int a);
	Node();
};


int main()
{
	//pointer to int
	int* p = new int; // 할당에는 new 연산자를
	delete p; // 해제에는 delete 연산자를 사용한다.

	//pointer to array to int
	p = new int[3]; // 배열의 할당이 필요할 때는 new[] 연산자를 사용하며
	delete[] p; // 해제에는 delete[] 연산자를 사용한다.

	//pointer to class
	Node* no = new Node(1);
	Node* no = new Node;
	delete no;

	//pointer to array to class
	Node* no = new Node[3];
	delete[] no;

	//이렇게 사용가능
	no[0];

	return 0;
}
