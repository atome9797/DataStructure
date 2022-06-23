#include "Deque.h"
#include <deque>
#include <iostream>

using namespace std;

inline void error(const char* message) {
    puts(message);
    exit(EXIT_FAILURE); //���μ��� ����� ��� => EXIT_FAILURE���� main�Լ� ���Ͻ� �޴°��� �ش��
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
    //deque ���� ����
    Deque dequetest(10);
    dequetest.pushFront(5);
    dequetest.pushBack(40);
    dequetest.display();

    cout << "���� ���� ��" << endl;


    //deque<int> dq;

    ////����
    //dq.push_front(1); //1 
    //dq.push_back(2); //1 , 2 
    //dq.insert(dq.begin() + 1, 3);// 1,3,2

    ////��������Ʈ�� ������ ���ϰ� �����Ƿ� �ݺ��ڰ� �����Ѵ�. queue�� �����̳� ����Ͷ� �ݺ��ڰ� ����
    ////�ݺ���
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



    ////����
    //dq.pop_front();
    //dq.pop_back();
    //dq.erase(dq.begin()); //�� ������

    ////�Ʒ� ó�� �ʱ�ȭ�� �����ϴ�.
    //deque<int> dq2 = { 1,2,3,4,5 };
    //
    ////�б� 
    //cout << "dq2.front() : " << dq2.front() << "\n"; //1
    //cout << "dq2.back() : " << dq2.back() << "\n"; //2
    //cout << "dq2[2] : " << dq2[2] << "\n"; //3

    ////ũ��
    //cout << "dq2.size() : " << dq2.size() << "\n";//5

    ////����
    //dq2.clear();
    //if (dq2.empty())
    //{
    //    cout << "dq2 is empty\n";
    //}

    ////Ÿ�� ������ �൵ c++ 11 ���� �ڵ����� �ν��ϰԵ�
    //deque dq3 = { 1,2,3 };//deque<int>


}