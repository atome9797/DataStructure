#include <iostream>

class A 
{

public:

	A() = delete; //class �����ڰ� �����Ƿ� Ŭ���� ������ �ȵȴ�.

	

	void asd()
	{
		int num = 1;
		ptr = &num;
	}

	void print()
	{
		std::cout << *ptr << std::endl;
	}

	

private:
	int* ptr = nullptr;
};

int main()
{
	A a; //�����ڸ� �ȸ�������� �⺻ �����ڰ� �����Ǽ� �����
	A b; 
	b.asd();
	a = b; // �⺻ = �����Ҵ� �����ڰ� ����Ǽ� �Ҵ� ����(���� ����) => ���� �����Ϸ��� ����� �����
	a.print();
	b.print();


}