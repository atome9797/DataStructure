#include <iostream>

class A 
{

public:

	A() = delete; //class 생성자가 없으므로 클래스 선언이 안된다.

	

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
	A a; //생성자를 안만들었을때 기본 생성자가 생성되서 실행됨
	A b; 
	b.asd();
	a = b; // 기본 = 복사할당 연산자가 실행되서 할당 받음(얕은 복사) => 깊은 복사하려면 만들어 줘야함
	a.print();
	b.print();


}