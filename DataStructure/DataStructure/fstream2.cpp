#include <iostream>
#include <fstream>

class A
{
public:
    A() = default;
    explicit A(int data) : _data(data) { }

    int GetData() const { return _data; }
    void SetData(int data) { _data = data; }
private:
    int _data = 0;
};

// ����� ������ �ϰ� �ʹٸ� �Ʒ��� ����� ������ �ϸ� �ȴ�.
std::ostream& operator<<(std::ostream& oss, const A& a)
{
    return oss << "My Data : " << a.GetData();
}

// �Է��� ������ �ϰ� �ʹٸ� �Ʒ��� ����� ������ �ϸ� �ȴ�.
std::istream& operator>>(std::istream& iss, A& a)
{
    iss.ignore(sizeof("My Data : "), ':');

    int data;
    iss >> data;
    a.SetData(data);

    return iss;
}

int main()
{
    // ���
    std::ofstream ofs("temp.txt");
    A a(14);
    ofs << a; //a�����͸� ofstreamŬ������ ������
    ofs.close();

    // �Է�
    std::ifstream ifs("temp.txt");
    A b;
    ifs >> b; //���ϵ����͸� b�� ������
    std::cout << b;
    ifs.close();

    return 0;
}
