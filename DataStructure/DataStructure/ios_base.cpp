#include <iostream> // 표준 파일 입출력은 이 헤더를 포함해야 한다.
#include <iomanip>  // 입출력과 관련된 조작을 위한 헤더다.
#include <string>

int main()
{
    // 출력은 << 연산자를 사용하면 된다.
    std::cout << "Hello World!\n";

    // 포맷팅도 가능하다.
    // 1. 정수 관련 포맷
    std::cout << 12 << "\n";     // "12"
    std::cout << std::hex;       // 16진수로 출력한다.
    std::cout << 12 << "\n";     // "c"
    std::cout << std::showbase;  // 진법을 표현한다.
    std::cout << 12 << "\n";     // "0xc"
    // 다시 원래대로 되돌린다. => 10진수로 바꾸고 , showbase를 삭제
    std::cout << std::dec << std::noshowbase; 

    // 2. 실수 관련 포맷
    std::cout << 12.34 << "\n";         // "12.34"
    std::cout << std::fixed;            // 소수점 자리를 고정시켜 표현한다. (기본 소수점 자리수는 6자리)
    std::cout << 12.34 << "\n";         // "12.340000"
    std::cout << std::setprecision(12); // 소수점 자리를 12자리로 고정한다. (자리수 변화 시켜줌)
    std::cout << 12.34 << "\n";         // "12.340000000000"
    // 다시 원래대로 되돌린다.
    std::cout << std::defaultfloat << std::setprecision(6);

    // 3. 불리언 관련 포맷 
    std::cout << std::boolalpha;    // 불리언 값을 출력할 때 숫자 대신 문자로 출력한다.
    std::cout << true << "\n";      // "true"
    // 다시 원래대로 되돌린다.
    std::cout << std::noboolalpha;


    // 4. 정렬 관련 포맷
    
    
    std::cout << std::setfill('*'); // 공백대신 *출력
    //범위 지정했으면 기본이 오른쪽 정렬 한다.
    std::cout << std::setw(12);     // 출력 길이를 '일시적'으로 12로 지정한다.
    std::cout << std::left;         // 왼쪽 정렬 
    std::cout << std::hex << std::showbase; //16진법으로 출력
    std::cout << 100000000 << "\n";        // "0x2a********"
    std::cout << std::right; // 오른쪽 정렬
    std::cout << std::setw(12); 
    std::cout << 42 << "\n"; // "********0x2a"
    // 다시 원래대로 되돌린다.
    std::cout << std::setfill(' ');
    std::cout.width(0);


    // 입력은 >> 연산자를 사용하면 된다.
    std::cout << "숫자를 입력하세요 : ";
    int num;
    std::cin >> num; //cin는 객체임


    // good() / fail()로 오류 여부를 알 수 있다.
    if (std::cin.good())
    {
        std::cout << "숫자를 입력함.\n";
    }
    else if (std::cin.fail())
    {
        std::cout << "숫자가 아닌 다른 값을 입력함.\n";
        std::cin.clear(); // clear()를 사용하면 객체를 정상화할 수 있다.
    }

    // bool 타입으로 변환이 가능하다. cin에 오류가 담겨 있으면 false가 출력된다.
    // std::cin은 ios_base 클래스 템플릿을 재정의 한것 
    if (std::cin) //std::cin.good() 과 같다.
        //1. if에 작성하는 조건식의 타입은 bool
        //2. if (std::cin) => std::cin 의 타입이 istream => bool
        //3. std::cin.operator bool(); 타입을 가진다.
        
    {
        std::cout << "오류가 없음.\n"; //복사 할당후 실행시킴
        /*
            &basic_ostream operator<<(const basic_ostream&)
            {
                return *this;
            }
        */
   
    }
    else
    {
        std::cout << "오류 발생함.\n";
    }

    std::cout << std::setfill('-'); // 공백대신 *출력
    std::cout.width(22);
    std::cout << "\n";
    std::cout << std::setfill(' ');
    std::cout << std::setw(10);     // 출력 길이를 '일시적'으로 12로 지정한다.
    std::cout << std::left;         // 왼쪽 정렬 
    std::cout << "|Name";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << std::right;         // 오른쪽 정렬 
    std::cout << "Age|" << "\n";
    std::cout << std::setfill('-');
    std::cout.width(22);
    std::cout << "\n";

    std::cout << std::dec << std::noshowbase;
    int age [] = {31,28,25,38};
    std::string name[] = { "김영훈", "김재성", "이승일" ,"노우진"};
    std::cout << std::setfill(' ');
    
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|"<< name[i] << std::setw(5) << "|" << std::setw(8) << std::right << age[i] << "|" << "\n";
    }

    
    return 0;
}
