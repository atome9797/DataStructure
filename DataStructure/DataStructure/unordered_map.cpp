#include <unordered_map> //해시테이블
#include <string>
#include <map> //이진 검색 트리
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
		oss << "이 학생은 안경을 썼습니다.\n";
	}
	else
	{
		oss << "이 학생은 안경을 쓰지 않았습니다.\n";
	}

	if (student.Gender == FEMALE)
	{
		oss << "이 학생은 여자입니다.\n";
	}
	else
	{
		oss << "이 학생은 남자입니다.\n";
	}

	if (student.isCodingGosu)
	{
		oss << "이 학생은 고수입니다.\n";
	}
	else
	{
		oss << "이 학생은 고수가 아닙니다.\n";
	}

	if (student.Age > 30)
	{
		oss << "나이가 30이상입니다.\n";
	}
	else
	{
		oss << "나이가 30이상이 아닙니다.\n";
	}
	oss << "-----------------------------\n";

	return oss;

}

int main()
{
	unordered_map<string, Student>hashTable;

	//hash 테이블 
	hash<string> hash;
	size_t value = hash("asdasd"); //어떤것을 넣던간에 8바이트로 만들어줌
	Student student;
	student("asdasd"); //operator 문법임
	
	
	cout << value << "\n";


	//김영훈을 해싱해서 고정된 크기의 데이터로 만든뒤 테이블의 index값으로 받는다.
	//value값은 데이터값이다.
	hashTable["최서연"] = { "학생",false ,FEMALE, true, 22};
	hashTable["김영훈"] = { "학생",false ,MALE, false, 27 };

	cout << hashTable["최서연"];
	cout << hashTable["김영훈"];

}