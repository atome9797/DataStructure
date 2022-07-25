#include "Set.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main()
{
	auto initList = { 10,5,1,6,17,14,21 };
	
	Set s;
	for (int elem : initList)
	{
		s.insert(elem);
	}

	cout << "���� ��ȸ\n";
	s.traverseByPreorder();
	cout << "���� ��ȸ\n";
	s.traverseByInorder();
	cout << "���� ��ȸ\n";
	s.traverseByPostorder();
	cout << "���� ��ȸ\n";
	s.traverseByLevelorder();
	cout << "\n";

	s.erase(10);
	//s.traverseByInorder();






	return 0;
}