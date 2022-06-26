#include <iostream>

using namespace std;

// 원형 큐
class Queue
{
public:
    // 큐에 value를 삽입합니다. push
    // 다 찬 경우 아무것도 하지 않습니다.
    //삽입
    void Enqueue(int value)
    {
        if (!IsFull())
        {
            //순환 구조로 rear가 사이즈를 넘어가면 0 index부터 시작할 수 있게 해준다.
            rear = (rear + 1) % size; 
            elements[rear] = value;
        }
    }

    // 큐에서 데이터를 꺼내고, 반환합니다. pop
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    //삭제
    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << -1 << "\n";
        }
        else
        {
            //순환 구조로 front가 사이즈를 넘어가면 0 index부터 시작할 수 있게 해준다.
            front = (front + 1) % size;
            return elements[front]; //이전 데이터 반환
        }
    }

    // 큐에서 앞에 있는 원소를 반환합니다.
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    //읽기
    int GetFront()
    {
        if (IsEmpty())
        {
            cout << -1 << "\n";
        }
        else
        {
            return elements[(front + 1) % size];
        }
    }

    // 큐에서 뒤에 있는 원소를 반환합니다.
    // 큐에 데이터가 없는 경우 -1를 반환합니다.
    int GetBack()
    {
        if (IsEmpty())
        {
            cout << -1 << "\n";
        }
        else
        {
            return elements[rear];
        }
    }

    // 큐가 비었다면 true, 아니면 false입니다.
    bool IsEmpty()
    {
        return rear == front;
    }

    //큐가 꽉차 있다면 true, 아니면 false 입니다.
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }

private:
    int size = 100;
    int front = 0;
    int rear = 0;
    int elements[100] = {0};
};

int main()
{

    //
    Queue que;
    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);

    //앞 원소 불러옴
    cout << que.GetFront() << "\n";
    //뒤 원소를 불러옴
    cout << que.GetBack() << "\n";

    //삭제
    cout << que.Dequeue() << "\n";

    cout << que.GetFront() << "\n";



}