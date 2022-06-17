#include <iostream> // ǥ�� ���� ������� �� ����� �����ؾ� �Ѵ�.
#include <iomanip>  // ����°� ���õ� ������ ���� �����.
#include <string>

int main()
{
    // ����� << �����ڸ� ����ϸ� �ȴ�.
    std::cout << "Hello World!\n";

    // �����õ� �����ϴ�.
    // 1. ���� ���� ����
    std::cout << 12 << "\n";     // "12"
    std::cout << std::hex;       // 16������ ����Ѵ�.
    std::cout << 12 << "\n";     // "c"
    std::cout << std::showbase;  // ������ ǥ���Ѵ�.
    std::cout << 12 << "\n";     // "0xc"
    // �ٽ� ������� �ǵ�����. => 10������ �ٲٰ� , showbase�� ����
    std::cout << std::dec << std::noshowbase; 

    // 2. �Ǽ� ���� ����
    std::cout << 12.34 << "\n";         // "12.34"
    std::cout << std::fixed;            // �Ҽ��� �ڸ��� �������� ǥ���Ѵ�. (�⺻ �Ҽ��� �ڸ����� 6�ڸ�)
    std::cout << 12.34 << "\n";         // "12.340000"
    std::cout << std::setprecision(12); // �Ҽ��� �ڸ��� 12�ڸ��� �����Ѵ�. (�ڸ��� ��ȭ ������)
    std::cout << 12.34 << "\n";         // "12.340000000000"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::defaultfloat << std::setprecision(6);

    // 3. �Ҹ��� ���� ���� 
    std::cout << std::boolalpha;    // �Ҹ��� ���� ����� �� ���� ��� ���ڷ� ����Ѵ�.
    std::cout << true << "\n";      // "true"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::noboolalpha;


    // 4. ���� ���� ����
    
    
    std::cout << std::setfill('*'); // ������ *���
    //���� ���������� �⺻�� ������ ���� �Ѵ�.
    std::cout << std::setw(12);     // ��� ���̸� '�Ͻ���'���� 12�� �����Ѵ�.
    std::cout << std::left;         // ���� ���� 
    std::cout << std::hex << std::showbase; //16�������� ���
    std::cout << 100000000 << "\n";        // "0x2a********"
    std::cout << std::right; // ������ ����
    std::cout << std::setw(12); 
    std::cout << 42 << "\n"; // "********0x2a"
    // �ٽ� ������� �ǵ�����.
    std::cout << std::setfill(' ');
    std::cout.width(0);


    // �Է��� >> �����ڸ� ����ϸ� �ȴ�.
    std::cout << "���ڸ� �Է��ϼ��� : ";
    int num;
    std::cin >> num; //cin�� ��ü��


    // good() / fail()�� ���� ���θ� �� �� �ִ�.
    if (std::cin.good())
    {
        std::cout << "���ڸ� �Է���.\n";
    }
    else if (std::cin.fail())
    {
        std::cout << "���ڰ� �ƴ� �ٸ� ���� �Է���.\n";
        std::cin.clear(); // clear()�� ����ϸ� ��ü�� ����ȭ�� �� �ִ�.
    }

    // bool Ÿ������ ��ȯ�� �����ϴ�. cin�� ������ ��� ������ false�� ��µȴ�.
    // std::cin�� ios_base Ŭ���� ���ø��� ������ �Ѱ� 
    if (std::cin) //std::cin.good() �� ����.
        //1. if�� �ۼ��ϴ� ���ǽ��� Ÿ���� bool
        //2. if (std::cin) => std::cin �� Ÿ���� istream => bool
        //3. std::cin.operator bool(); Ÿ���� ������.
        
    {
        std::cout << "������ ����.\n"; //���� �Ҵ��� �����Ŵ
        /*
            &basic_ostream operator<<(const basic_ostream&)
            {
                return *this;
            }
        */
   
    }
    else
    {
        std::cout << "���� �߻���.\n";
    }

    std::cout << std::setfill('-'); // ������ *���
    std::cout.width(22);
    std::cout << "\n";
    std::cout << std::setfill(' ');
    std::cout << std::setw(10);     // ��� ���̸� '�Ͻ���'���� 12�� �����Ѵ�.
    std::cout << std::left;         // ���� ���� 
    std::cout << "|Name";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right;         // ������ ���� 
    std::cout << "Age|" << "\n";
    std::cout << std::setfill('-');
    std::cout.width(22);
    std::cout << "\n";

    std::cout << std::dec << std::noshowbase;
    int age [] = {31,28,25,38};
    std::string name[] = { "�迵��", "���缺", "�̽���" ,"�����"};
    std::cout << std::setfill(' ');
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|"<< name[i] << std::setw(5) << "|" << std::setw(8) << std::right << age[i] << "|" << "\n";
    }

    
    return 0;
}
