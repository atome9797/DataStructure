#include <iostream>
#include <string>
#include <sstream> // ���ڿ� ������� ���� �����.

int main()
{
    // ���ڿ� ������� stringstream�� �̿��Ѵ�.
    std::stringstream ss;
    std::stringstream ss2;

    // ���������� ����� << �����ڸ� ����Ѵ�. => ss Ŭ������ Hello�� �޴´�.
    ss << "Hello";
    ss2 << "asd";

    // �Է��� >> �����ڸ� ����Ѵ�.
    std::string str;
    ss >> str; //ss Ŭ������ �ִ� hello�� str Ŭ������ �Ѱ��ش�.
    ss2 >> str;
    std::cout << str; //=> str�� �ִ� hello�� ��� Ŭ������ �Ѱ��ش�.
    //asd

    // str()�� �̿��ϸ� ��Ʈ���� �ִ� ���ڿ���
    // std::string ��ü�� ��ȯ�Ѵ�.
    std::string str2 = ss.str();
    std::cout << str2; //str2Ŭ������ �ִ� hello�� ���Ŭ������ �Ѱ��ش�.
    //Hello
    
    return 0;
}
