#include "forward_list2.h"
#include <utility>

// �⺻ ������
ForwardList::ForwardList()
{
	_head->Next = _end;
}

// count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
ForwardList::ForwardList(size_t count)
{
	for (int i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// ���� ������.
ForwardList::ForwardList(const ForwardList& other)
{
	

}

// �Ҵ� ������
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	//���� ������ ������ 
	ForwardList(rhs);
	//���� �ϱ�
	std::swap(_head, rhs._head);
	std::swap(_end, rhs._end);
}

// �Ҹ���
ForwardList::~ForwardList()
{
	clear();

	delete _end;
	delete _head;
	_end = nullptr;
	_head = nullptr;
}

// ù ��° ��Ҹ� ��ȯ�Ѵ�.
int& ForwardList::front()
{
	return begin()->Data;
}

// ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}


// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}


// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::end()
{
	return _end;
}

// pos ������ value�� �����Ѵ�.
// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::insert_after(Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* where = pos;
	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

// pos ���� ��Ҹ� �����Ѵ�.
// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
// �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::erase_after(Node* pos)
{
	if (empty)
	{
		return end();
	}

	Node* where = pos;
	Node* removed = pos->Next;
	where->Next = removed->Next;
	removed->Next = nullptr;


	return removed;
}

// ���� ��ҿ� value�� �����Ѵ�.
void	ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

// ���� ��Ҹ� �����Ѵ�.
void    ForwardList::pop_front()
{
	erase_after(before_begin());
}

// �����̳ʰ� ������� �Ǵ��Ѵ�.
bool    ForwardList::empty() const
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

// �����̳ʸ� ���������.
void    ForwardList::clear()
{
	while (empty() == false)
	{
		pop_front();
	}
}

// value�� �ִ��� �˻��Ѵ�.
bool    ForwardList::contains(int value) const
{
	for (int i = 0; _head[i].Data != '\0'; i++)
	{
		if (_head[i].Data == value)
		{
			return true;
		}
	}

	return false;
}