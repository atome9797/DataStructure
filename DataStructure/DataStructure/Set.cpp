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

	//���� �˻� Ʈ�� : ���� ���� Ʈ���� �ڱ� ���� ���� ��, ������ ���� Ʈ���� �ڱ⺸�� ū��.
	Node* currentNode = _root; //�Ѹ� ��� ����
	Node* prevNode = nullptr;

	//Ʈ���� �ڽĳ����� ��
	while (currentNode)
	{
		prevNode = currentNode;

		//���� �˻� ����.
		//���� ���̶�� �ش簪�� ����Ű�� ���� false�� ��ȯ�ϸ��
		if (currentNode->Data == value)
		{
			return make_pair(currentNode, false);
		}
		else if (currentNode->Data > value)
		{
			currentNode = currentNode->Left; //�ڽ� ���� ��������
		}
		else
		{
			currentNode = currentNode->Right; //�ڽ� ���� ��������
		}
	}

	//currentNode�� ���ο� �ڽ� ��带 ������ => prevNode�� �θ� ��尡 ��
	currentNode = new Node(value, prevNode);

	//currentNode�� prevNode�� ���� �ڽ����� ������ ���� ������ �ڽ����� �����Ұ���
	if (prevNode->Data < value)
	{
		prevNode->Right = currentNode; //���� ������ �ڽĳ�带 �θ� ��尡 ��prevNode�� �ڽ� ��忡 �Ҵ�����
	}
	else
	{
		prevNode->Left = currentNode; //���� ������ �ڽĳ�带 �θ� ��尡 ��prevNode�� �ڽ� ��忡 �Ҵ�����
	}

	++_size;
	//�ڽĳ�带 ���� ����� �ִ°� ���������ϱ� true�� ��ȯ����
	return make_pair(currentNode, true);
}

void Set::erase(Node* pos)
{
	//1. pos�� _head���?
	if (pos->Parent == nullptr)
	{
		//1. �ڽ��� ���ٸ�?
		if (pos->IsLeaf())
		{
			_root = nullptr;
			
			delete pos;
			pos = nullptr;
			
			--_size;
			return;
		}
		//2. ���� �ڽĸ� �ִٸ�?
		if (pos->Right == nullptr)
		{
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}
		//3. ������ �ڽĸ� �ִٸ�?
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}

		//4. �Ѵ� �ִٸ�?
		if (pos->Left != nullptr && pos->Right != nullptr)
		{

			
		}
	}
	//2. pos�� ���� �����?
	//3. pos�� ���� �ڽĸ� �ִٸ�?
	//4. pos�� ������ �ڽĸ� �ִٸ�?
	//5. pos�� �ڽ��� �Ѵ� ������ �ִٸ�?


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
