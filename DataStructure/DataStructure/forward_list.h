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

    //�����͸� �����Ҽ� ���� �ݺ���
    //const int*
    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr);
        ~const_iterator();

        const int&          operator*() const; //������ ������
        const int*          operator->() const; //��� ����
        const_iterator&     operator++(); //���� ���� ������
        const_iterator      operator++(int); //���� ���� ������
        bool                operator==(const const_iterator& rhs) const;
        bool                operator!=(const const_iterator& rhs) const;
        bool                operator==(nullptr_t p) const;
        bool                operator!=(nullptr_t p) const;

    public:
        Node* _p = nullptr;
    };

    //������ ������ ������ �ݺ���
    //int * 
    class iterator : public const_iterator
    {
    public:
        iterator(Node* p = nullptr);

        //4������ ����ҰŶ� 4���� �������̵���
        int& operator*() const;
        int* operator->() const;
        iterator& operator++();
        iterator        operator++(int);
    };

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
    iterator            before_begin();
    const_iterator      before_begin() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            begin();
    const_iterator      begin() const;

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            end();
    const_iterator      end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            insert_after(const_iterator pos, int value);

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    iterator            erase_after(const_iterator pos);

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