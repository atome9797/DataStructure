#include "forward_list2.h"
#include <utility>






// 기본 생성자
ForwardList::ForwardList()
{
	//begin() == end()
	//head->Next == nullptr
	//_head = new Node(0, nullptr)
}

// count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
ForwardList::ForwardList(size_t count)
{
	for (int i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// 복사 생성자.
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	Node* inserted = before_begin();
	
	
	for (const Node* iter = other.begin(); iter != other.end(); iter++)
	{
		inserted = insert_after(inserted, other._head->Data); //두번째 주소부터의 포인터 반복자를 iterator에 넣어줌
	}


}

// 할당 연산자
ForwardList& ForwardList::operator=(const ForwardList& rhs)
{


	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
	}
	return *this;
}

// 소멸자
ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;
}

// 첫 번째 요소를 반환한다.
int& ForwardList::front()
{
	return begin()->Data;
}

// 시작 전 요소를 가리키는 반복자를 반환한다.
ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}

const ForwardList::Node* ForwardList::before_begin() const
{
	return _head;
}


// 시작 요소를 가리키는 반복자를 반환한다.
ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}

const ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}



// 끝 다음 요소를 가리키는 반복자를 반환한다.
ForwardList::Node* ForwardList::end()
{
	return nullptr;
}

const ForwardList::Node* ForwardList::end() const
{
	return nullptr;
}

// pos 다음에 value를 삽입한다.
// 삽입된 요소를 가리키는 반복자를 반환한다.
ForwardList::Node* ForwardList::insert_after(Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* where = pos;
	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

// pos 다음 요소를 삭제한다.
// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
// 아무 요소도 없으면 end()를 반환한다.
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

// 시작 요소에 value를 삽입한다.
void	ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

// 시작 요소를 제거한다.
void    ForwardList::pop_front()
{
	erase_after(before_begin());
}

// 컨테이너가 비었는지 판단한다.
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

//// 컨테이너를 비워버린다.
void    ForwardList::clear()
{
	while (empty() == false)
	{
		pop_front();
	}
}

// value가 있는지 검사한다.
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