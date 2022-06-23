#include <queue>
#include <iostream>
#include "Queue.h"

int main()
{
	std::queue<int> q;

	//����
	for (int i = 1; i <= 5; i++)
	{
		q.push(i); //{1,2,3,4,5} front 1 ���� �̾Ƴ�
	}

	//����
	q.pop();// q{2,3,4,5}

	//�б�
	std::cout << "q.front() : " << q.front() << "\n"; //2
	std::cout << "q.back() : " << q.back() << "\n"; //5

	//ũ��
	if (q.empty())
	{
		std::cout << "q is empty\n";
	}

	std::cout << "q.size() : " << q.size() << "\n";

	
	return 0;
}
