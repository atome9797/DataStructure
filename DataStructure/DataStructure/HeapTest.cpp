#include "Heap.h"
#include <iostream>

#include <queue>
#include <vector>
#include <functional>


using namespace std;

int main()
{
	Heap heap;
	
	for (int num : {7, 4, 11, 1, 0, 27, 31})
	{
		heap.push(num);
	}

	while (false == heap.empty())
	{
		std::cout << heap.top();
		heap.pop();
	}

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	return 0;
}