#include "forward_list.h"
#include <utility>
#include <iostream>

//노드에 대한 값과 다음 주소를 생성함
ForwardList::Node::Node(int data, Node* next)
	: Data(data), Next(next)
{

}

ForwardList::Node::~Node()
{
	Next = nullptr;
}

//새로운 주소값을 넘겨줌
ForwardList::const_iterator::const_iterator(Node* p)
	:_p(p)
{

}

//_p(주소값)를 null로 초기화
ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

//const_iterator 클래스의 역잠초 데이터를 반환
const int& ForwardList::const_iterator::operator*()const
{
	return _p->Data; //데이터를 반환함
}

//데이터에 대한 주소값을 반환하여, 해당 주소값을 -> 로 받음
const int* ForwardList::const_iterator::operator->()const
{
	return &(_p->Data); //데이터에 대한 주소를 반환함
}

//자기 자신의 주소의 다음 주소로 받은후 자기 자신을 반환함
ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{ 
	_p = _p->Next;
	return *this; //자기 자신을 다시 사용함
}

//자기 자신의 주소값을 받은 후 포인터 주소값을 변경한후 , iterator 주소값을 반환함으로써 
ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	//p++
	//1. p를 1증가 시키고
	//2. 이전 p를 반환
	const_iterator temp = *this;
	_p = _p->Next; //리턴 해준값이 전 주소값이고, _p는 다음 주소값을 가리킴
	return temp;
}

bool ForwardList::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool ForwardList::const_iterator::operator==(nullptr_t p) const
{
	//nullptr;//c++ 11
	//왜 나왔냐면 null의 모호함 때문
	//null은 정수로써 0도 되고
	//포인터로써 null도 되기 때문

	if(_p == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(nullptr_t p) const
{
	//nullptr;//c++ 11
	//왜 나왔냐면 null의 모호함 때문
	//null은 정수로써 0도 되고
	//포인터로써 null도 되기 때문

	if (_p != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//iterator 는 const_iterator를 상속 받기 때문에, const_iterator에 주소를 생성한다. (iterator자체는 주소 없음)
ForwardList::iterator::iterator(Node* p)
	:const_iterator(p)
{
	
}

//operator는 우변값을 좌변에 넘겨주는 형태인데, 우변값의 매개변수가 없으므로 const_iterator 부모 클래스로 조작한다.

//const_iterator에 접근해서 해당 주소에 대한 값을 반환한 다음, 반환 값을 int형 레퍼런스로 반환 => 역참조값을 출력해줌
int& ForwardList::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

//내부 주소를 반환(-> 자체가 내부주소에 접근하는 거임)
//포인터 타입이므로, 데이터에 대한 주소를 반환 => const_iterator에 접근해서 데이터에 대한 주소값을 반환하게함
int* ForwardList::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

//자기 자신의 _p 주소값을 다음 주소로 변경한후 this를 사용해서 자기 자신의 주소값을 가져옴
ForwardList::iterator& ForwardList::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

//자기 자신의 _p 주소를 따로 저장한뒤, 
ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	//const_iterator::operator++(0); => 아무 수나 넘기면 후위 연산자가 실행됨
	return temp;
}


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


int main()
{
	ForwardList list(10);
	
	if (!list.contains(10))
	{
		std::cout << "틀렸습니다." << std::endl;
	}
	

	for (ForwardList::iterator iter = list.begin(); iter != list.end(); iter++) //iter++에서 operator++(int) 실행되면서 다음 주소가 실행됨
	{
		std::cout << *iter << std::endl; //operator*()를 실행시킴으로써 _p->Data를 리턴함

		//iter-> 직접적으로 사용못함 
		//iter->는 멤버 접근하는데, iter자체는 class이므로 class를 int 포인터로 대입하려니까 안됨
	}



	return 0;
}