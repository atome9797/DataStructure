#pragma once
#include <stddef.h>

class ForwardList
{
    //���Ḯ��Ʈ���� �����͸� �����ϱ� ���� Ÿ��
    //�� ���� ����Ʈ�� �����͸� ���������� �ٷ�� ���� �ƴ϶� 
    //node��°����� �ٷ��.
    struct Node

    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0; //���� ������
        Node* Next = nullptr; //���������ּ� ������
    };

public:

   

    // �⺻ ������
    ForwardList();

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit ForwardList(size_t count);

    // ���� ������.
    ForwardList(const ForwardList& other);

    // �Ҵ� ������
    ForwardList& operator=(const ForwardList& rhs);

    // �Ҹ���
    ~ForwardList();

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();
    const int& front() const;

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_begin();
    
    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            begin();
    
    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            end();

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value);

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos);

    // ���� ��ҿ� value�� �����Ѵ�.
    void                push_front(int value);

    // ���� ��Ҹ� �����Ѵ�.
    void                pop_front();

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool                empty() const;

    // �����̳ʸ� ���������.
    void                clear();

    // value�� �ִ��� �˻��Ѵ�.
    bool                contains(int value) const;
private:
    //���� ���, ���� �����͸� ���� ����, ������ ������ ���Ǽ����� ���� ����

    //ó�� ����� => _head -> data + ���� �ּ�(end) -> end �����ͼ����ε�
    Node* _head = new Node(); //before_begin() 
    //���� ���
    Node* _end = new Node(); //end()
};
