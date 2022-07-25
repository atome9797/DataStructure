#include <iostream>
#include <fstream> // ���� ������� ���� �����.
#include <string>

int main()
{
    // ���� ����� ofstream�� �̿��Ѵ�.
    std::ofstream of("temp.txt");

    // ������ ǥ�� ���ϰ� ����ϴ�. 
    of << "Hello World!"; //���� Ŭ������ Hello World!�� �Ѱ��ش�.

    // close()�� ��������� ������ ���� �� �ִ�.
    // ���� ���� ���� �ʾƵ� �Ҹ��ڿ��� �ڵ����� ȣ���Ѵ�.
    of.close();

    {
        // ���� �Է��� ifstream�� �̿��Ѵ�.
        std::ifstream ifs;

        // is_open()���� ������ �������� Ȯ���� �� �ִ�.
        if (false == ifs.is_open())
        {
            // open()���� ������ �� �� �ִ�.
            ifs.open("temp.txt");
        }

        std::string str;
        std::getline(ifs, str);
        std::cout << str << "\n";

        // eof()�� ������ ���� �����ߴ��� �� �� �ִ�.
        if (ifs.eof())
        {
            std::cout << "������ ���� ������.\n";
        }
    } // �ڵ����� ifs.close()�� ȣ��ȴ�.

    // ���̳ʸ� ���� ���� �ʹٸ� ios::binary�� �Ѱ��ش�.
    std::ofstream of2("temp.bin", std::ios::binary);

    return 0;
}
