#include "forward_list.h"
#include <utility>
#include <iostream>

//기본 생성자
ForwardList::ForwardList()
{

	//_head -> []
	//_end -> []

	//[] -> []

	//처음 선언시 => _head -> data + 다음 주소(end) -> end 데이터순으로들어감
	//두번째 주소에 end()를 넣어줌으로써 시작값을 null로 만들어줌
	_head->Next = _end;

}

//count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
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
// A = B; B의 데이터를 A에 복사
// 복사 생성자.
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	iterator inserted = before_begin(); //B의 주소를 반복자로 받고 해당 주소에 값을 할당해줌
	for (const_iterator iter = other.begin(); iter != other.end(); iter++)
	{
		//해당 주소에 값을 할당해줌 => 반복자는 결국 주소를 가리킬뿐 아무 역할안함
		inserted = insert_after(inserted, *iter); //두번째 주소부터의 포인터 반복자를 iterator에 넣어줌
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

//이중포인터
ForwardList::iterator ForwardList::before_begin()
{
	//iterator 반복자의 포인터인 _p 사용
	return _head; 
}

//이중포인터
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
											//head 주소값을 반복자로 받음
ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	//[] - > [] -> [] -> []
	//		pos
	//			  value
	
	//주소값과 value값이 생김 C
	Node* newNode = new Node(value);
	//head 주소 A
	Node* where = pos._p;

	//기존 두번째 주소(head다음)를 newNode의 두번째 주소에 넣어줌 C -> B
	newNode->Next = where->Next; 
	//기존 두번째 주소를 새로 선언한 포인터의 주소로 받으면 A -> C -> B 상태가됨
	where->Next = newNode;
	
	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	//[] - > [] -> [] -> []
	//		where  removed
	//pos의 다음 노드가 end() => 비었다면
	if (empty())
	{
		return end();
	}
	Node* where = pos._p; //A
	Node* removed = where->Next; //B
	
	where->Next = removed->Next; //A -> C
	removed->Next = nullptr; //원래 removed가 가리키고 있던걸 끊어줌(주소를 null로 만들어준거지, 값을 null넣은게 아님!!!!)
	//removed->Next가 c였는데 (B -> C), null로 줌으로써 끊어주는 역할을 함

	return removed;
	
}


//시작 요소에 value를 삽입한다.
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
	//연결리스트가 head -> next -> end 상태이면 비어 있다는 뜻
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
		//operator* 받음
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}
