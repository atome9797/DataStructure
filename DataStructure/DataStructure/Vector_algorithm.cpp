#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //표준 네임스페이스를 사용하겠다는 의미
//std라는 이름을 가지고 있는 네임스페이스 속의 함수, 변수들을 
//선언 범위 내에서 사용하겠다는 의미를 가집니다 => 사용시 생략가능해짐


int main()
{
	//범위 지정 연산자 :: 

	//일반 배열에서 알고리즘 라이브러리 사용
	int arr[4] = { 10,20,5,30 };

	sort(arr, arr + 4);

	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << endl;
	}

	//vector 에서 알고리즘 라이브러리 사용
	vector <int> vec = { 1,30,5,20 };
	sort(vec.begin(), vec.end());
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}

	//at 요소 접근
	vector <int> vec2 = { 1,2,3,4 };
	vec2.at(0) = 20;
	vector <int>::iterator iter = vec2.begin();
	cout << *iter << endl; //요소의 값이 바귄것을 확인할수 있다.
	
	
	



}
