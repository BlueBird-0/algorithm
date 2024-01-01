//https://www.acmicpc.net/problem/1927
#include <iostream>
using namespace std;

namespace {
	unsigned int minHeap[100001] = { 0, };
	int heapSize = 0;

	void Swap(unsigned int& a, unsigned int&b)
	{
		unsigned int temp = a;
		a = b;
		b = temp;
	}
	void Insert(unsigned int num)
	{
		heapSize++;
		minHeap[heapSize] = num;

		int index = heapSize;
		int parent = index / 2;
		while (parent)
		{
			if (minHeap[index] < minHeap[parent])
			{
				Swap(minHeap[index], minHeap[parent]);
			}
			else {
				break;
			}
			index = parent;
			parent = parent / 2;
		}
	}
	unsigned int Pop()
	{
		if (heapSize == 0)
			return 0;
		unsigned int result = minHeap[1];
		minHeap[1] = minHeap[heapSize];
		minHeap[heapSize] = 0;

		heapSize--;
		int child = 2;
		while (child <= heapSize)
		{
			int minChildIndex = heapSize;
			if (minHeap[child] < minHeap[child + 1] && minHeap[child] != 0)
			{
				minChildIndex = child;
			}
			else if (minHeap[child + 1] < minHeap[child] && minHeap[child + 1] != 0)
			{
				minChildIndex = child + 1;
			}

			if (minHeap[minChildIndex] < minHeap[child / 2])
			{
				Swap(minHeap[child / 2], minHeap[minChildIndex]);
				child = minChildIndex * 2;
			}
			else {
				break;
			}
		}

		return result;
	}
}

int Q1927()
{
	//ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		unsigned int num;
		cin >> num;
		if (num == 0)
		{
			cout << Pop() << '\n';
		}
		else {
			Insert(num);
		}
	}

	return 0;
}