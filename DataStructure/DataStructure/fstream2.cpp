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

// 출력을 재정의 하고 싶다면 아래와 비슷한 선언을 하면 된다.
std::ostream& operator<<(std::ostream& oss, const A& a)
{
    return oss << "My Data : " << a.GetData();
}

// 입력을 재정의 하고 싶다면 아래와 비슷한 선언을 하면 된다.
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
    // 출력
    std::ofstream ofs("temp.txt");
    A a(14);
    ofs << a; //a데이터를 ofstream클래스에 저장함
    ofs.close();

    // 입력
    std::ifstream ifs("temp.txt");
    A b;
    ifs >> b; //파일데이터를 b에 저장함
    std::cout << b;
    ifs.close();

    return 0;
}
