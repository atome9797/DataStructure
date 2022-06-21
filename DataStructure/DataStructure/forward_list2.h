#pragma once
#include <stddef.h>

class ForwardList
{
public:
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
    const Node* before_begin() const;
    
    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            begin();
    const Node*            begin()const;
    
    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*            end();
    const Node*            end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value);
    const Node* insert_after(Node* pos, int value) const;

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos) ;
    const Node* erase_after(Node* pos) const;

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
};


