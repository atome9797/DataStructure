#include "List.h"
#include <utility>
#include <iostream>

//���
List::Node::Node(int data , Node* prev , Node* next )
	:Data(data), Prev(prev), Next(next)
{

}


List::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}


//�θ�Ŭ���� �Ҵ� ���� ������
List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next; 
	return *this;
}

List::const_iterator List::const_iterator::operator++(int)
{
	const_iterator temp = *this;
	_p = _p->Next;
	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;
	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	const_iterator temp = *this;
	_p = _p->Prev;
	return temp;
}


//�ڽ� Ŭ���� �Ҵ� ���� ������
List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

List::iterator List::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();
	return *this;
}

List::iterator List::iterator::operator--(int)
{
	iterator temp = *this;
	const_iterator::operator--();
	return temp;
}


//�θ� Ŭ���� �Ҵ���� ������
const int& List::const_iterator::operator*() const
{
	return _p->Data;
}

const int* List::const_iterator::operator->() const
{
	return &(_p->Data);
};

bool List::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p) //this �����Ȱ�
	{
		return true;
	}
	
	return false;
};

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(rhs == *this);
}
bool List::const_iterator::operator==(nullptr_t p) const
{
	if (_p == nullptr) //this �����Ȱ�
	{
		return true;
	}

	return false;
}
bool List::const_iterator::operator!=(nullptr_t p) const
{
	if (_p != nullptr) //this �����Ȱ�
	{
		return true;
	}

	return false;
}

//�ڽ�Ŭ���� �Ҵ���� ������
int& List::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* List::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
};

//����Ʈ
List::List()
{
	_end->Next = _end; //begin() ����
	_end->Prev = _end; //end() ����
}

//����Ʈ Ŭ���� ������
List::List(size_t count)
	:List()
{
	for (int i = 0; i < count; i++)
	{
		push_front(0);
	}
}
//���� ������
List::List(const List& other)
	:List()
{
	for (const_iterator iter = other.begin(); iter != other.end(); iter++)
	{
		push_back(*iter);
	}
}

//�Ҵ� ������
List& List::operator=(const List& rhs)
{
	if (&rhs != this)
	{
		//���� ������ ������ ����
		List temp(rhs);
		std::swap(_end, temp._end);
	}

	return *this;
}

//�Ҹ���
List::~List()
{
	clear();
	delete _end;
	_end = nullptr;
}



void List::push_front(int value)
{
	insert(begin(), value);
}

void List::push_back(int value)
{
	insert(end(), value);
}

void List::pop_front()
{
	erase(begin());
}

void List::pop_back()
{
	//iterator iter = end();
	//iter--;
	//erase(iter); //end->prev
	//erase(_end->Prev); 
	erase(--end());
}


int& List::front()
{
	return *begin();
}

const int& List::front() const
{
	return *begin();
}

int& List::back()
{
	return *(--end());
	//return _end->Prev->Data; �� ����.
}

const int& List::back() const
{
	return *(--end());
}


List::iterator List::insert(iterator pos, int value)
{
	Node* NextNode = pos._p; //B  end() ,newNode(���� ��� �ּ� ����)
	Node* PrevNode = NextNode->Prev; //A  end->prev = end() ,end
	//Node* newNode = new Node(value); //C

	//newNode->Prev = NextNode; //A -> C
	//newNode->Next = PrevNode; //C -> B
	Node* newNode = new Node(value , PrevNode , NextNode);

	PrevNode->Next = newNode; //A -> C
	NextNode->Prev = newNode; //C -> B
	

	++_size;

	return newNode;
}


List::iterator List::erase(iterator pos)
{
	//pos._p->Next->Prev �̷������� �����ص���

	Node* removed = pos._p; //B
	Node* PrevNode = removed->Prev; //A
	Node* NextNode = removed->Next; //C

	PrevNode->Next = NextNode;//A -> C
	NextNode->Prev = PrevNode;//A -> C

	_size--;

	delete removed;

	return NextNode;
}



List::iterator List::begin()
{
	return iterator(_end->Next);
}

List::const_iterator List::begin() const
{
	return const_iterator(_end->Next);
}

List::iterator List::end()
{
	return iterator(_end);
}

List::const_iterator List::end() const
{
	return const_iterator(_end);
}


bool List::empty() const
{
	if (_size == 0)
	{
		return true;
	}

	return false;
}

size_t List::size() const
{
	return _size;
}

void List::clear()
{

	//iterator�� ������ ���԰� �����Ҷ� �����ؾ��Ѵ�.
	//��? ������ ���԰� �����Ҷ� �ݺ��ڴ� �׻� ��ȿȭ(������ ���) �Ǳ� ����

	while (empty() == false)
	{
		pop_front();
	}
}

bool List::contains(int value) const
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


int main()
{
	List list(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);

	std::cout << list.front() << std::endl;

	for (List::const_iterator iter = list.begin(); iter != list.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}





