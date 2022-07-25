#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> list1;

	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);

	for (list<int>::iterator iter = list1.begin() ; iter != list1.end(); iter++)
	{
		cout << *iter << endl;
	}

	list<int> list20;

	list20.push_back(1);
	list20.push_back(2);
	list20.push_back(3);

	for (list<int>::iterator iter = list20.begin(); iter != list20.end(); iter++)
	{
		cout << *iter << endl;
	}




	list1.push_back(2);

	//특정 요소 앞에 삽입가능
	list1.insert(list1.begin(), 9); //첫 요소 전에 삽입

	list1.push_back(5); //9 1 2 5


	list<int>::iterator iter;
	iter = list1.begin(); //[9]<->[1]<->[2]<->[5]<->[ ]

	iter = list1.end(); // [9]<->[1]<->[2]<->[5]<->[ ]

	//이중 연결리스트는 이전 요소에 접근가능하다.
	list<int>::reverse_iterator riter;

	riter = list1.rbegin(); 
	// [ ]<->[9]<->[1]<->[2]<->[5]
	//                          ↑

	riter = list1.rend();
	// [ ]<->[9]<->[1]<->[2]<->[5]
	//  ↑

	//삭제
	list1.pop_front();
	list1.pop_back();
	list1.erase(list1.begin()); //첫번째 요소 삭제
	list1.clear(); //컨테이너 전부 비움

	if (list1.empty())
	{
		cout << "리스트 비었음" << endl;
	}

	cout << list1.size() << endl;
	
	list <int> list2 = { 1,2,3,4,5 };
	cout << "list2.front : " << list2.front() << "\n";
	cout << "list2.back : " << list2.back() << "\n";

	list1 = list2; //대입 가능
	if (list1 == list2)
	{
		cout << "둘이 같다." << "\n";
	}
	std::list list3 = { 1, 2, 3, 4, 5 };


	for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
	{
		cout << *iter << " ";
	}




	return 0;
}