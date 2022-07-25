#include <iostream>
#include <stack>
#include <vector>
#include <forward_list>
#include <list>
#include "Stack.h"

using namespace std;

int main()
{


	stack<int> s;

	vector<int> vec; 
	vec.push_back(1);
	vec.pop_back();

	forward_list<int> list1;
	list1.push_front(1);
	list1.pop_front();

	list<int> list2;
	//list2.push_back(2); list2.pop_front();
	//list2.push_back(2); list2.pop_front();

	
	for (int i = 1; i <= 5; i++)
	{
		s.push(i); // s {5,4,3,2,1}
	}

	//반복자가 존재하지 않는다. => 순회하지 않기 때문
	s.pop(); //요소 삭제함
	
	cout << "top() " << s.top() << "\n";

	if (s.empty())
	{
		cout << "empty\n";
	}

	cout << "size" << s.size() << "\n";


	

	return 0;
}
