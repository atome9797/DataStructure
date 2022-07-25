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
	int* p = new int; // �Ҵ翡�� new �����ڸ�
	delete p; // �������� delete �����ڸ� ����Ѵ�.

	//pointer to array to int
	p = new int[3]; // �迭�� �Ҵ��� �ʿ��� ���� new[] �����ڸ� ����ϸ�
	delete[] p; // �������� delete[] �����ڸ� ����Ѵ�.

	//pointer to class
	Node* no = new Node(1);
	Node* no = new Node;
	delete no;

	//pointer to array to class
	Node* no = new Node[3];
	delete[] no;

	//�̷��� ��밡��
	no[0];

	return 0;
}
