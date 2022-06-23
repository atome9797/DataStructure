#include "Deque.h"
#include <deque>
#include <iostream>

using namespace std;

inline void error(const char* message) {
    puts(message);
    exit(EXIT_FAILURE); //프로세스 종료시 사용 => EXIT_FAILURE사용시 main함수 리턴시 받는값이 해당됨
}

Deque::Deque(const int size) {
    elements = new int[size];
    maxSize = size;
    dataSize = 0;
    frontIndex = 0;
    rearIndex = 1;
}

Deque::~Deque() {
    delete[] elements;
}

bool Deque::empty() const {
    return dataSize == 0;
}

bool Deque::full() const {
    return dataSize == maxSize;
}

int Deque::size() const {
    return dataSize;
}

int Deque::front() const {
    if (empty()) {
        error("Deque is empty!");
    }
    int tempIndex = (frontIndex + 1) % maxSize;
    return elements[tempIndex];
}

int Deque::back() const {
    if (empty()) {
        error("Deque is empty!");
    }
    int tempIndex = ((rearIndex - 1) + maxSize) % maxSize;
    return elements[tempIndex];
}

void Deque::pushFront(const int data) {
    if (full()) {
        error("Deque is full!");
    }
    elements[frontIndex] = data;
    frontIndex = ((frontIndex - 1) + maxSize) % maxSize;
    dataSize++;
}

void Deque::pushBack(const int data) {
    if (full()) {
        error("Deque is full!");
    }
    elements[rearIndex] = data;
    rearIndex = (rearIndex + 1) % maxSize;
    dataSize++;
}

int Deque::popFront() {
    int frontData = front();// if empty, error occurred
    frontIndex = (frontIndex + 1) % maxSize;
    dataSize--;
    return frontData;
}

int Deque::popBack() {
    int backData = back();// if empty, error occurred
    rearIndex = ((rearIndex - 1) + maxSize) % maxSize;
    dataSize--;
    return backData;
}

void Deque::display() const {
    puts("====================================================================================================");
    if (empty()) {
        puts("Deque is empty!");
        puts("====================================================================================================");
        return;
    }
    printf("%-5s : %s\n", "full", full() ? "true" : "false");
    printf("%-5s : %d\n", "size", size());
    printf("%-5s : %d\n", "front", front());
    printf("%-5s : %d\n", "back", back());
    printf("(FRONT) ");
    for (int i = 1; i <= dataSize; i++) {
        int tempIndex = (frontIndex + i) % maxSize;
        printf("[%d] ", elements[tempIndex]);
    }
    puts("(BACK)");
    puts("====================================================================================================");
}

int main()
{
    //deque 직접 구현
    Deque dequetest(10);
    dequetest.pushFront(5);
    dequetest.pushBack(40);
    dequetest.display();

    cout << "구현 문제 끝" << endl;


    //deque<int> dq;

    ////삽입
    //dq.push_front(1); //1 
    //dq.push_back(2); //1 , 2 
    //dq.insert(dq.begin() + 1, 3);// 1,3,2

    ////선형리스트의 성격을 지니고 있으므로 반복자가 존재한다. queue는 컨테이너 어댑터라서 반복자가 없음
    ////반복자
    //deque<int>::iterator iter;
    //iter = dq.begin();
    //iter = dq.end();

    //for (int i : dq)
    //{
    //    cout << i << endl; // 1 3 2
    //}

    //deque<int>::reverse_iterator riter;
    //riter = dq.rbegin();
    //riter = dq.rend();



    ////삭제
    //dq.pop_front();
    //dq.pop_back();
    //dq.erase(dq.begin()); //다 삭제됨

    ////아래 처럼 초기화도 가능하다.
    //deque<int> dq2 = { 1,2,3,4,5 };
    //
    ////읽기 
    //cout << "dq2.front() : " << dq2.front() << "\n"; //1
    //cout << "dq2.back() : " << dq2.back() << "\n"; //2
    //cout << "dq2[2] : " << dq2[2] << "\n"; //3

    ////크기
    //cout << "dq2.size() : " << dq2.size() << "\n";//5

    ////비우기
    //dq2.clear();
    //if (dq2.empty())
    //{
    //    cout << "dq2 is empty\n";
    //}

    ////타입 안적어 줘도 c++ 11 부터 자동으로 인식하게됨
    //deque dq3 = { 1,2,3 };//deque<int>


}