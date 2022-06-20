#include "forward_list.h"
#include <utility>
#include <iostream>

//�⺻ ������
ForwardList::ForwardList()
{

	//_head -> []
	//_end -> []

	//[] -> []

	//ó�� ����� => _head -> data + ���� �ּ�(end) -> end �����ͼ����ε�
	//�ι�° �ּҿ� end()�� �־������ν� ���۰��� null�� �������
	_head->Next = _end;

}

//count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
ForwardList::ForwardList(size_t count)
	: ForwardList()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

//ForwardList A;
// ForwardList B;
// A = B; B�� �����͸� A�� ����
// ���� ������.
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	iterator inserted = before_begin(); //B�� �ּҸ� �ݺ��ڷ� �ް� �ش� �ּҿ� ���� �Ҵ�����
	for (const_iterator iter = other.begin(); iter != other.end(); iter++)
	{
		//�ش� �ּҿ� ���� �Ҵ����� => �ݺ��ڴ� �ᱹ �ּҸ� ����ų�� �ƹ� ���Ҿ���
		inserted = insert_after(inserted, *iter); //�ι�° �ּҺ����� ������ �ݺ��ڸ� iterator�� �־���
	}
}


ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}
	return *this;
}


ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;
	delete _end;
	_end = nullptr;
	
}


int& ForwardList::front()
{
	return *begin();
}

const int& ForwardList::front() const
{
	return *begin();
}

//����������
ForwardList::iterator ForwardList::before_begin()
{
	//iterator �ݺ����� �������� _p ���
	return _head; 
}

//����������
ForwardList::const_iterator ForwardList::before_begin() const
{
	return _head;
}

ForwardList::iterator ForwardList::begin()
{
	return _head->Next;
}

ForwardList::const_iterator ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::iterator ForwardList::end()
{
	return _end;
}

ForwardList::const_iterator ForwardList::end() const
{
	return _end;
}
											//head �ּҰ��� �ݺ��ڷ� ����
ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	//[] - > [] -> [] -> []
	//		pos
	//			  value
	
	//�ּҰ��� value���� ���� C
	Node* newNode = new Node(value);
	//head �ּ� A
	Node* where = pos._p;

	//���� �ι�° �ּ�(head����)�� newNode�� �ι�° �ּҿ� �־��� C -> B
	newNode->Next = where->Next; 
	//���� �ι�° �ּҸ� ���� ������ �������� �ּҷ� ������ A -> C -> B ���°���
	where->Next = newNode;
	
	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	//[] - > [] -> [] -> []
	//		where  removed
	//pos�� ���� ��尡 end() => ����ٸ�
	if (empty())
	{
		return end();
	}
	Node* where = pos._p; //A
	Node* removed = where->Next; //B
	
	where->Next = removed->Next; //A -> C
	removed->Next = nullptr; //���� removed�� ����Ű�� �ִ��� ������(�ּҸ� null�� ������ذ���, ���� null������ �ƴ�!!!!)
	//removed->Next�� c���µ� (B -> C), null�� �����ν� �����ִ� ������ ��

	return removed;
	
}


//���� ��ҿ� value�� �����Ѵ�.
void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}


void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	//if(begin() == end())
	//���Ḯ��Ʈ�� head -> next -> end �����̸� ��� �ִٴ� ��
	if (_head->Next == _end)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


void ForwardList::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); iter++)
	{
		//operator* ����
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}
