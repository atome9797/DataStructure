#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //ǥ�� ���ӽ����̽��� ����ϰڴٴ� �ǹ�
//std��� �̸��� ������ �ִ� ���ӽ����̽� ���� �Լ�, �������� 
//���� ���� ������ ����ϰڴٴ� �ǹ̸� �����ϴ� => ���� ������������


int main()
{
	//���� ���� ������ :: 

	//�Ϲ� �迭���� �˰��� ���̺귯�� ���
	int arr[4] = { 10,20,5,30 };

	sort(arr, arr + 4);

	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << endl;
	}

	//vector ���� �˰��� ���̺귯�� ���
	vector <int> vec = { 1,30,5,20 };
	sort(vec.begin(), vec.end());
	
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
	}

	//at ��� ����
	vector <int> vec2 = { 1,2,3,4 };
	vec2.at(0) = 20;
	vector <int>::iterator iter = vec2.begin();
	cout << *iter << endl; //����� ���� �ٱϰ��� Ȯ���Ҽ� �ִ�.
	
	
	



}
