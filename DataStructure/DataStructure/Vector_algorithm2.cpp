#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//문제 : n개의 정수중 x라는 정수의 존재여부를 파악
	//입력 :
	// 1. 벡터 길이를 입력한다.
	// 2. 백터에 담을 요소를 입력한다.
	// 3. 비교할 벡터의 길이를 입력한다.
	// 4. 비교할 벡터에 담을 요소를 입력한다.
	//처리 :
	// 기존 벡터와 비교할 벡터의 요소를 비교한다.
	//출력 :
	// 같은 요소면 1, 다른 요소면 0을 출력한다.

	int vec_input = 0;
	cin >> vec_input;

	vector<int> vec(vec_input); //벡터에 갯수 부여

	for (int i = 0; i < vec_input; i++)
	{
		int vec_input_number = 0;
		cin >> vec_input_number;

		vec.push_back(vec_input_number);
	}
	
	//binary_search는 순차배열만 사용가능하다.그러므로 sort로 정렬해준다.
	sort(vec.begin(), vec.end());
	

	int vec_input2 = 0;
	cin >> vec_input2;
	for (int i = 0; i < vec_input2; i++)
	{
		int vec_input_number = 0;
		cin >> vec_input_number;

		if (binary_search(vec.begin(), vec.end(), vec_input_number))
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}


	return 0;
}