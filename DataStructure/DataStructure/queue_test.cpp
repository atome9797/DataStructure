#include <iostream>

using namespace std;

// ���� ť
class Queue
{
public:
    // ť�� value�� �����մϴ�. push
    // �� �� ��� �ƹ��͵� ���� �ʽ��ϴ�.
    //����
    void Enqueue(int value)
    {
        if (!IsFull())
        {
            //��ȯ ������ rear�� ����� �Ѿ�� 0 index���� ������ �� �ְ� ���ش�.
            rear = (rear + 1) % size; 
            elements[rear] = value;
        }
    }

    // ť���� �����͸� ������, ��ȯ�մϴ�. pop
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    //����
    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << -1 << "\n";
        }
        else
        {
            //��ȯ ������ front�� ����� �Ѿ�� 0 index���� ������ �� �ְ� ���ش�.
            front = (front + 1) % size;
            return elements[front]; //���� ������ ��ȯ
        }
    }

    // ť���� �տ� �ִ� ���Ҹ� ��ȯ�մϴ�.
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
    //�б�
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

    // ť���� �ڿ� �ִ� ���Ҹ� ��ȯ�մϴ�.
    // ť�� �����Ͱ� ���� ��� -1�� ��ȯ�մϴ�.
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

    // ť�� ����ٸ� true, �ƴϸ� false�Դϴ�.
    bool IsEmpty()
    {
        return rear == front;
    }

    //ť�� ���� �ִٸ� true, �ƴϸ� false �Դϴ�.
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

    //�� ���� �ҷ���
    cout << que.GetFront() << "\n";
    //�� ���Ҹ� �ҷ���
    cout << que.GetBack() << "\n";

    //����
    cout << que.Dequeue() << "\n";

    cout << que.GetFront() << "\n";



}