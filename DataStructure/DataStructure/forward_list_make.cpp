#include "forward_list.h"
#include <utility>
#include <iostream>

//��忡 ���� ���� ���� �ּҸ� ������
ForwardList::Node::Node(int data, Node* next)
	: Data(data), Next(next)
{

}

ForwardList::Node::~Node()
{
	Next = nullptr;
}

//���ο� �ּҰ��� �Ѱ���
ForwardList::const_iterator::const_iterator(Node* p)
	:_p(p)
{

}

//_p(�ּҰ�)�� null�� �ʱ�ȭ
ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

//const_iterator Ŭ������ ������ �����͸� ��ȯ
const int& ForwardList::const_iterator::operator*()const
{
	return _p->Data; //�����͸� ��ȯ��
}

//�����Ϳ� ���� �ּҰ��� ��ȯ�Ͽ�, �ش� �ּҰ��� -> �� ����
const int* ForwardList::const_iterator::operator->()const
{
	return &(_p->Data); //�����Ϳ� ���� �ּҸ� ��ȯ��
}

//�ڱ� �ڽ��� �ּ��� ���� �ּҷ� ������ �ڱ� �ڽ��� ��ȯ��
ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{ 
	_p = _p->Next;
	return *this; //�ڱ� �ڽ��� �ٽ� �����
}

//�ڱ� �ڽ��� �ּҰ��� ���� �� ������ �ּҰ��� �������� , iterator �ּҰ��� ��ȯ�����ν� 
ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	//p++
	//1. p�� 1���� ��Ű��
	//2. ���� p�� ��ȯ
	const_iterator temp = *this;
	_p = _p->Next; //���� ���ذ��� �� �ּҰ��̰�, _p�� ���� �ּҰ��� ����Ŵ
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
	//�� ���Գĸ� null�� ��ȣ�� ����
	//null�� �����ν� 0�� �ǰ�
	//�����ͷν� null�� �Ǳ� ����

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
	//�� ���Գĸ� null�� ��ȣ�� ����
	//null�� �����ν� 0�� �ǰ�
	//�����ͷν� null�� �Ǳ� ����

	if (_p != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//iterator �� const_iterator�� ��� �ޱ� ������, const_iterator�� �ּҸ� �����Ѵ�. (iterator��ü�� �ּ� ����)
ForwardList::iterator::iterator(Node* p)
	:const_iterator(p)
{
	
}

//operator�� �캯���� �º��� �Ѱ��ִ� �����ε�, �캯���� �Ű������� �����Ƿ� const_iterator �θ� Ŭ������ �����Ѵ�.

//const_iterator�� �����ؼ� �ش� �ּҿ� ���� ���� ��ȯ�� ����, ��ȯ ���� int�� ���۷����� ��ȯ => ���������� �������
int& ForwardList::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

//���� �ּҸ� ��ȯ(-> ��ü�� �����ּҿ� �����ϴ� ����)
//������ Ÿ���̹Ƿ�, �����Ϳ� ���� �ּҸ� ��ȯ => const_iterator�� �����ؼ� �����Ϳ� ���� �ּҰ��� ��ȯ�ϰ���
int* ForwardList::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

//�ڱ� �ڽ��� _p �ּҰ��� ���� �ּҷ� �������� this�� ����ؼ� �ڱ� �ڽ��� �ּҰ��� ������
ForwardList::iterator& ForwardList::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

//�ڱ� �ڽ��� _p �ּҸ� ���� �����ѵ�, 
ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	//const_iterator::operator++(0); => �ƹ� ���� �ѱ�� ���� �����ڰ� �����
	return temp;
}


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


int main()
{
	ForwardList list(10);
	
	if (!list.contains(10))
	{
		std::cout << "Ʋ�Ƚ��ϴ�." << std::endl;
	}
	

	for (ForwardList::iterator iter = list.begin(); iter != list.end(); iter++) //iter++���� operator++(int) ����Ǹ鼭 ���� �ּҰ� �����
	{
		std::cout << *iter << std::endl; //operator*()�� �����Ŵ���ν� _p->Data�� ������

		//iter-> ���������� ������ 
		//iter->�� ��� �����ϴµ�, iter��ü�� class�̹Ƿ� class�� int �����ͷ� �����Ϸ��ϱ� �ȵ�
	}



	return 0;
}