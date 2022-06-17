#include <iostream>
#include <string>
#include <sstream> // 문자열 입출력을 위한 헤더다.

int main()
{
    // 문자열 입출력은 stringstream을 이용한다.
    std::stringstream ss;
    std::stringstream ss2;

    // 마찬가지로 출력은 << 연산자를 사용한다. => ss 클래스는 Hello를 받는다.
    ss << "Hello";
    ss2 << "asd";

    // 입력은 >> 연산자를 사용한다.
    std::string str;
    ss >> str; //ss 클래스에 있던 hello를 str 클래스에 넘겨준다.
    ss2 >> str;
    std::cout << str; //=> str에 있던 hello를 출력 클래스에 넘겨준다.
    //asd

    // str()을 이용하면 스트림에 있는 문자열을
    // std::string 객체로 변환한다.
    std::string str2 = ss.str();
    std::cout << str2; //str2클래스에 있던 hello를 출력클래스에 넘겨준다.
    //Hello
    
    return 0;
}
