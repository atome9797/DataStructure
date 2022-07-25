#include <iostream>
#include "forward_list.h"

ForwardList::ForwardList()
{
	_head->Next = _end;
}

ForwardList::ForwardList(size_t count)
{
	for (int i = 0; i < count; i++)
	{
		push_front(0);
	}
}

//���� ���� ��ü
ForwardList::ForwardList(const ForwardList& other)
	:ForwardList()
{
	iterator inserted = before_begin();
	for (const_iterator iter = other.begin(); iter != other.end(); iter++)
	{
		inserted = insert_after(inserted, *iter); //���ο� ��ü�� �����͸� �־���
	}
}

ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	//���� ������ ������ ������ ����������
	if (&rhs != this)
	{
		ForwardList temp(rhs);//������ ������
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}

	return *this;
}

ForwardList::~ForwardList()
{
	clear();

	delete _head;
	delete _end;
	_head = nullptr;
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


ForwardList::iterator ForwardList::before_begin()
{
	return _head;
}

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
												//�ݺ����� �ּҿ� �ص� �ּ� ����
ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	//C ��� ����
	Node* newNode = new Node(value);
	Node* where = pos._p; 
	
	newNode->Next = where->Next; //C -> B;
	where->Next = newNode; //A -> C -> B

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	if (empty())
	{
		return end();
	}

	Node* where = pos._p; //A
	Node* removed = where->Next; //B
	where->Next = removed->Next; //A -> C
	removed->Next = nullptr;

	return removed;
}

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
	while (empty() == false)
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); iter++)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}


