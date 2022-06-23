#include <queue>
#include <iostream>
#include "Queue.h"

int main()
{
	std::queue<int> q;

	//삽입
	for (int i = 1; i <= 5; i++)
	{
		q.push(i); //{1,2,3,4,5} front 1 부터 뽑아냄
	}

	//삭제
	q.pop();// q{2,3,4,5}

	//읽기
	std::cout << "q.front() : " << q.front() << "\n"; //2
	std::cout << "q.back() : " << q.back() << "\n"; //5

	//크기
	if (q.empty())
	{
		std::cout << "q is empty\n";
	}

	std::cout << "q.size() : " << q.size() << "\n";

	
	return 0;
}
