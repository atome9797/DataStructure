#include <unordered_map> //�ؽ����̺�
#include <string>
#include <map> //���� �˻� Ʈ��
#include <iostream>

enum Gender {MALE, FEMALE};

using namespace std;

struct Student
{
	string name;
	//char name2[10];
	bool IsOnGlasses;
	Gender Gender;
	bool isCodingGosu;
	int Age;

	void operator()(string name)
	{
		cout << name << "\n";
	}

};



ostream& operator<<(ostream& oss, const Student& student)
{
	oss << "-----------------------------\n";

	//oss << student.name2 << "\n";
	oss << student.name << "\n";

	if (student.IsOnGlasses)
	{
		oss << "�� �л��� �Ȱ��� ����ϴ�.\n";
	}
	else
	{
		oss << "�� �л��� �Ȱ��� ���� �ʾҽ��ϴ�.\n";
	}

	if (student.Gender == FEMALE)
	{
		oss << "�� �л��� �����Դϴ�.\n";
	}
	else
	{
		oss << "�� �л��� �����Դϴ�.\n";
	}

	if (student.isCodingGosu)
	{
		oss << "�� �л��� ����Դϴ�.\n";
	}
	else
	{
		oss << "�� �л��� ����� �ƴմϴ�.\n";
	}

	if (student.Age > 30)
	{
		oss << "���̰� 30�̻��Դϴ�.\n";
	}
	else
	{
		oss << "���̰� 30�̻��� �ƴմϴ�.\n";
	}
	oss << "-----------------------------\n";

	return oss;

}

int main()
{
	unordered_map<string, Student>hashTable;

	//hash ���̺� 
	hash<string> hash;
	size_t value = hash("asdasd"); //����� �ִ����� 8����Ʈ�� �������
	Student student;
	student("asdasd"); //operator ������
	
	
	cout << value << "\n";


	//�迵���� �ؽ��ؼ� ������ ũ���� �����ͷ� ����� ���̺��� index������ �޴´�.
	//value���� �����Ͱ��̴�.
	hashTable["�ּ���"] = { "�л�",false ,FEMALE, true, 22};
	hashTable["�迵��"] = { "�л�",false ,MALE, false, 27 };

	cout << hashTable["�ּ���"];
	cout << hashTable["�迵��"];

}