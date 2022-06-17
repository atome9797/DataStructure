#include <iomanip>  // 입출력과 관련된 조작을 위한 헤더다.
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>


class A
{
public:
    A() = default;
    explicit A(int data){
        ss << printTest(data);
    }

    std::string GetData() const{
        return ss.str();
    }

    void SetData(std::string str) {
        ss << str;
    }

    std::string printTest(int num)
    {
        std::string str;
        std::stringstream ss;

        for (int i = 0; i < num * 2 + 4; i++)
        {
            ss << "-";
        }
        ss << "\n";
        ss << "|" << std::setw(num) << std::left << "Name" << "|" << std::setw(num) << std::right << "Age" << "|" << "\n";

        for (int i = 0; i < num * 2 + 4; i++)
        {
            ss << "-";
        }
        ss << "\n";

        int age[] = { 31,28,25,58 };
        std::string name[] = { "김영훈", "김재성", "이승일" ,"노우진" };
        
        for (int i = 0; i < 4; i++)
        {
            ss << "|" << std::setw(num) << std::left << name[i] << "|" << std::setw(num) << std::right << age[i] << "|" << "\n";
        }
        for (int i = 0; i < num * 2 + 4; i++)
        {
            ss << "-";
        }
        ss << "\n";

        
        str = ss.str();
       

        return str;
    }


private:
    std::stringstream ss;
};


// 출력을 재정의 하고 싶다면 아래와 비슷한 선언을 하면 된다.
std::ostream& operator<<(std::ostream& oss, const A& a)
{
    return oss << a.GetData();
}


std::istream& operator>>(std::istream& iss, A& a)
{

    std::stringstream str2;
    while (!iss.eof())
    {
        std::string str;
        getline(iss, str);
        str2 << str << "\n";
    }
    a.SetData(str2.str());

    return iss;
}



int main()
{
    
    std::ofstream test1("temptest.txt");
    A a(14);
    test1 << a;
    test1.close();

    std::ifstream test2("temptest.txt");
    
    A b;
    test2 >> b; //파일데이터를 b에 저장함
    std::cout << b;
    test2.close();



	return 0;
}