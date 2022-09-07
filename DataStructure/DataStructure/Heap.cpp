#include "Heap.h"
const int& Heap::top() const
{
	return _container.front();
}
bool Heap::empty() const
{
	return _container.empty();
}
size_t Heap::size() const
{
	return _container.size();
}
void Heap::push(int value)
{
	// 1. 먼저 맨 끝에 데이터를 삽입한다.
	_container.push_back(value);
	// 2. 힙의 불변성을 만족할 때까지 데이터를 바꿔준다.
	// Hack : 첫 번째 노드를 1로 생각
	size_t currentIndex = size();
	while (currentIndex > 1)
	{
		// 2 -1. 부모 노드를 찾는다.
		size_t parrentIndex = currentIndex / 2;
		if (_container[parrentIndex - 1] >= _container[currentIndex - 1])
		{
			// 2-2-1. 부모가 나보다 더 크다면 힙의 불변성을 만족하는 것이므로 종료
			break;
		}
		std::swap(_container[parrentIndex - 1], _container[currentIndex - 1]);
		currentIndex = parrentIndex;
	}

}
void Heap::pop()
{
	// 1. 마지막 노드를 루트 노드로 가져온다.
	_container[0] = _container.back();
	// 2. 마지막 노드를 제거한다.
	_container.pop_back();
	// 3. 힙의 불변성을 만족할 때까지 자식이랑 바꾼다.
	const size_t currentSize = _container.size();
	size_t currentIndex = 1;

	while (true)
	{
		size_t left = currentIndex * 2;
		size_t right = left + 1;
		// 3-1. 자식이 존재해야 한다.
		if (left > currentSize)
		{
			break;
		}
		// 3-2. 왼쪽 자식과 오른쪽 자식 중 더 큰 쪽으로 바꾼다.
		//미리 바꿔놓고 밑의 조건이 맞으면 다시 right로 만든다.
		size_t child = left; //미리바꿈
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}
		// 3-3. 바꿀 자식이 없다면 종료한다. => 더 작아야 진행가능
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}
		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;
	}
}