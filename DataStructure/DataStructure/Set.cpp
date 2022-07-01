#include "Set.h"
#include <iostream>
using namespace std;
Set::Node::Node(int data, Node*parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{
	
}

Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Set::height() const
{
	return 0;
}

int Set::height2() const
{
	return 0;
}

bool Set::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Set::size() const
{
	return _size;
}

void Set::clear()
{
	_size = 0;
	_root = nullptr;
}

pair<Set::Node*, bool> Set::insert(int value)
{
	if (empty())
	{
		_root = new Node(value);
		++_size;

		return make_pair(_root, true);
	}

	//이진 검색 트리 : 왼쪽 서브 트리는 자기 보다 작은 값, 오른쪽 서브 트리는 자기보다 큰값.
	Node* currentNode = _root; //뿌리 노드 넣음
	Node* prevNode = nullptr;

	//트리의 자식끝까지 감
	while (currentNode)
	{
		prevNode = currentNode;

		//이진 검색 수행.
		//같은 값이라면 해당값을 가리키는 노드와 false를 반환하면됨
		if (currentNode->Data == value)
		{
			return make_pair(currentNode, false);
		}
		else if (currentNode->Data > value)
		{
			currentNode = currentNode->Left; //자식 노드로 갱신해줌
		}
		else
		{
			currentNode = currentNode->Right; //자식 노드로 갱신해줌
		}
	}

	//currentNode에 새로운 자식 노드를 생성함 => prevNode는 부모 노드가 됨
	currentNode = new Node(value, prevNode);

	//currentNode를 prevNode에 왼쪽 자식으로 삽입할 건지 오른쪽 자식으로 삽입할건지
	if (prevNode->Data < value)
	{
		prevNode->Right = currentNode; //새로 생성한 자식노드를 부모 노드가 된prevNode의 자식 노드에 할당해줌
	}
	else
	{
		prevNode->Left = currentNode; //새로 생성한 자식노드를 부모 노드가 된prevNode의 자식 노드에 할당해줌
	}

	++_size;
	//자식노드를 새로 만들어 주는게 성공했으니까 true로 반환해줌
	return make_pair(currentNode, true);
}

void Set::erase(Node* pos)
{
	//1. pos가 _head라면?
	if (pos->Parent == nullptr)
	{
		//1. 자식이 없다면?
		if (pos->IsLeaf())
		{
			_root = nullptr;
			
			delete pos;
			pos = nullptr;
			
			--_size;
			return;
		}
		//2. 왼쪽 자식만 있다면?
		if (pos->Right == nullptr)
		{
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}
		//3. 오른쪽 자식만 있다면?
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}

		//4. 둘다 있다면?
		if (pos->Left != nullptr && pos->Right != nullptr)
		{

			
		}
	}
	//2. pos가 리프 노드라면?
	//3. pos가 왼쪽 자식만 있다면?
	//4. pos가 오른족 자식만 있다면?
	//5. pos가 자식을 둘다 가지고 있다면?


}

size_t Set::erase(int value)
{
	return size_t();
}

Set::Node* Set::find(int value)
{
	return nullptr;
}

const Set::Node* Set::find(int value) const
{
	return nullptr;
}

void Set::traverseByPreorder() const
{
}

void Set::traverseByInorder() const
{
}

void Set::traverseByPostorder() const
{
}

void Set::traverseByLevelorder() const
{
}
