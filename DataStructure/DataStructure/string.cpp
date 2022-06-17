#include <iostream>
#include <string> // std::string을 쓰고 싶다면 이 헤더를 포함해야 한다.
#include <assert.h>
#include <string_view> //string_view를 쓰고 싶다면 이 헤더를 포함해야한다.

int main()
{
    std::string_view s = "Hello"; //string_view 는 16바이트 string 은 40바이트
    std::cout << s << "\n";

    // empty()로 빈 문자열인지 확인할 수 있다.
    if (s.empty())
    {
        std::cout << "빈 문자열이다.\n";
    }

    // length() / size()로 문자열의 길이를 알 수 있다.
    std::cout << "이 문자열의 길이는 " << s.length() << "\n";
    // std::cout << "이 문자열의 길이는 " << s.size() << "\n";

    // [] 연산자로 각 문자에 접근할 수 있다.
    // front()로 첫 번째 문자에, back()으로 마지막 문자에 접근할 수 있다.
    std::cout << "이 문자열의 3번째 문자는 " << s[2] << "\n";
    std::cout << "이 문자열의 1번째 문자는 " << s.front() << "\n";
    std::cout << "이 문자열의 마지막 문자는 " << s.back() << "\n";

    // clear()로 빈 문자열로 만들 수 있다.
    if (s.empty())
    {
        std::cout << "빈 문자열이다.\n";
    }


    // ==, !=, <, > 연산자로 문자열을 비교할 수 있다.
    if (s == "Hello World")
    {
        std::cout << "Hello World와 같다.\n";
    }

    if (s != "Hello")
    {
        std::cout << "Hello와 다르다.\n";
    }

    if (s > "Hello")
    {
        std::cout << s << "가 Hello 뒤에 나온다.\n";
    }

    if (s < "Idle")
    {
        std::cout << s << "가 Idle 전에 나온다.\n";
    }

    // substr()로 문자열을 추출할 수 있다.
    std::cout << s.substr(0) << "\n";       // "Hello"
    
    //잘못된 사용법
    s = std::to_string(14);
    //1. std::string result = std::to_string(14); 
    //2. s = result; //포인터에 값을 할당함
    //3. result는 임시적인 객체이므로 소멸





    std::cout << s << "\n";
    


    return 0;
}
