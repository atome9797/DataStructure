#include "Vector1_Test.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	MyVector v(10); //배열 공간 10인 vector생성

	assert(v.GetCapacity() == 10);
	assert(v.GetSize() == 0);

	v.Add(1);
	v.Add(2);
	v.Add(3);
	v.Add(4);
	//{ 1, 2, 3, 4 }

	MyObject*ptr = v.FindById(3);
	printf("해당 id 내용 : %d\n", ptr->_id);
	printf("해당 id 주소 : %p\n", &ptr->_id);
	printf("해당 struct 주소 : %p\n", &ptr);

	printf("벡터 총 사이즈 : %d\n", v.GetCapacity());
	printf("벡터 사이즈 : %d\n", v.GetSize());


	assert(v.GetSize() == 4);

	v.TrimToSize(); //벡터 총 사이즈 4
	assert(v.GetSize() == v.GetCapacity());

	assert(nullptr == v.FindById(5));
	assert(nullptr != v.FindById(3));

	//_capacity 8 
	v.Add(1); v.Add(1); v.Add(1);
	v.RemoveAll(1);

	printf("벡터 총 사이즈 2 : %d\n", v.GetCapacity());

	assert(nullptr == v.FindById(1));
	assert(v.GetSize() == 3);

	cout << v.ToString() << endl;

	srand(time(nullptr));

	//size 103 / capacity 128
	for (int i = 0; i < 100; ++i)
	{
		v.Add(1 + rand() % 4);
	}

	printf("벡터 사이즈 3 : %d\n", v.GetSize());
	printf("벡터 총 사이즈 3 : %d\n", v.GetCapacity());

	int nums = 0;
	MyVector* vecs = v.GroupById(&nums); //구조체 포인터에 들어 있는 배열값을
	assert(nums == 4);
	for (int i = 0; i < nums; ++i)
	{
		cout << "각 벡터의 원소 " << i << " : " << vecs[i].ToString() << endl;
	}
	delete[] vecs;
	return 0;
}