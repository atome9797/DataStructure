#include <iostream>
#include <string> // std::string�� ���� �ʹٸ� �� ����� �����ؾ� �Ѵ�.
#include <assert.h>
#include <string_view> //string_view�� ���� �ʹٸ� �� ����� �����ؾ��Ѵ�.

int main()
{
    std::string_view s = "Hello"; //string_view �� 16����Ʈ string �� 40����Ʈ
    std::cout << s << "\n";

    // empty()�� �� ���ڿ����� Ȯ���� �� �ִ�.
    if (s.empty())
    {
        std::cout << "�� ���ڿ��̴�.\n";
    }

    // length() / size()�� ���ڿ��� ���̸� �� �� �ִ�.
    std::cout << "�� ���ڿ��� ���̴� " << s.length() << "\n";
    // std::cout << "�� ���ڿ��� ���̴� " << s.size() << "\n";

    // [] �����ڷ� �� ���ڿ� ������ �� �ִ�.
    // front()�� ù ��° ���ڿ�, back()���� ������ ���ڿ� ������ �� �ִ�.
    std::cout << "�� ���ڿ��� 3��° ���ڴ� " << s[2] << "\n";
    std::cout << "�� ���ڿ��� 1��° ���ڴ� " << s.front() << "\n";
    std::cout << "�� ���ڿ��� ������ ���ڴ� " << s.back() << "\n";

    // clear()�� �� ���ڿ��� ���� �� �ִ�.
    if (s.empty())
    {
        std::cout << "�� ���ڿ��̴�.\n";
    }


    // ==, !=, <, > �����ڷ� ���ڿ��� ���� �� �ִ�.
    if (s == "Hello World")
    {
        std::cout << "Hello World�� ����.\n";
    }

    if (s != "Hello")
    {
        std::cout << "Hello�� �ٸ���.\n";
    }

    if (s > "Hello")
    {
        std::cout << s << "�� Hello �ڿ� ���´�.\n";
    }

    if (s < "Idle")
    {
        std::cout << s << "�� Idle ���� ���´�.\n";
    }

    // substr()�� ���ڿ��� ������ �� �ִ�.
    std::cout << s.substr(0) << "\n";       // "Hello"
    
    //�߸��� ����
    s = std::to_string(14);
    //1. std::string result = std::to_string(14); 
    //2. s = result; //�����Ϳ� ���� �Ҵ���
    //3. result�� �ӽ����� ��ü�̹Ƿ� �Ҹ�





    std::cout << s << "\n";
    


    return 0;
}
