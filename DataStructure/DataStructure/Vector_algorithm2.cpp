#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//���� : n���� ������ x��� ������ ���翩�θ� �ľ�
	//�Է� :
	// 1. ���� ���̸� �Է��Ѵ�.
	// 2. ���Ϳ� ���� ��Ҹ� �Է��Ѵ�.
	// 3. ���� ������ ���̸� �Է��Ѵ�.
	// 4. ���� ���Ϳ� ���� ��Ҹ� �Է��Ѵ�.
	//ó�� :
	// ���� ���Ϳ� ���� ������ ��Ҹ� ���Ѵ�.
	//��� :
	// ���� ��Ҹ� 1, �ٸ� ��Ҹ� 0�� ����Ѵ�.

	int vec_input = 0;
	cin >> vec_input;

	vector<int> vec(vec_input); //���Ϳ� ���� �ο�

	for (int i = 0; i < vec_input; i++)
	{
		int vec_input_number = 0;
		cin >> vec_input_number;

		vec.push_back(vec_input_number);
	}
	
	//binary_search�� �����迭�� ��밡���ϴ�.�׷��Ƿ� sort�� �������ش�.
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