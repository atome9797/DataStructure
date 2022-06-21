#include "forward_list2.h"
#include <utility>






// �⺻ ������
ForwardList::ForwardList()
{
	//begin() == end()
	//head->Next == nullptr
	//_head = new Node(0, nullptr)
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
	: ForwardList()
{
	Node* inserted = before_begin();
	
	
	for (const Node* iter = other.begin(); iter != other.end(); iter++)
	{
		inserted = insert_after(inserted, other._head->Data); //�ι�° �ּҺ����� ������ �ݺ��ڸ� iterator�� �־���
	}


}

// �Ҵ� ������
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{


	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
	}
	return *this;
}

// �Ҹ���
ForwardList::~ForwardList()
{
	clear();

	delete _head;
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

const ForwardList::Node* ForwardList::before_begin() const
{
	return _head;
}


// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}

const ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}



// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
ForwardList::Node* ForwardList::end()
{
	return nullptr;
}

const ForwardList::Node* ForwardList::end() const
{
	return nullptr;
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
	/*if (empty)
	{
		return end();
	}*/

	Node* where = pos;
	Node* removed = pos->Next;
	where->Next = removed->Next;
	removed->Next = nullptr;


	return removed;
}

const ForwardList::Node* ForwardList::erase_after(Node* pos) const
{
	/*if (empty)
	{
		return end();
	}*/

	Node* where = pos;
	Node* removed = pos->Next;
	where->Next = removed->Next;
	//removed->Next = nullptr;
	delete removed;

	return where->Next;
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
	if (_head->Next == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//// �����̳ʸ� ���������.
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
	

	for (const Node* iter= begin(); iter != end(); iter++)
	{
		if (iter->Data == value)
		{
			return true;
		}
	}

	return false;
}

int main()
{

	ForwardList list(10);
	list.push_front(15);
	list.push_front(45);
	list.push_front(65);
	
	list.contains(65);

	return 0;
}