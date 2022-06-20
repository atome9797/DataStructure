#include <iostream>
#include <array>
#include <list>

using namespace std;

int main()
{
	array<int, 5> arr = {1,2,3,4,5};

	for (array<int, 5>::iterator iter = arr.begin(); iter != arr.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	for (auto element : arr)
	{
		cout << element << endl;
	}


	list<string> letters;
	letters.push_back("abc");
	string s{ "asd" };
	letters.push_back(move(s));

	for (int i = 0; i < letters.size(); i++)
	{
		cout << letters[i] << endl;
	}

	for (auto element : letters)
	{
		cout << element << endl;
	}
	

	return 0;
}