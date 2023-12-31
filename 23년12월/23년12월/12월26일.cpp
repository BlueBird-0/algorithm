//https://www.acmicpc.net/problem/2751
#include <iostream>
using namespace std;
int nums[1000000] = { 0, };
namespace {
	void Swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void QuickSort(int left, int right) {
		if (right <= left)
			return;

		int low = left;
		int high = right;
		Swap(nums[left], nums[left + (rand() % (right - left))]);	//피봇값을 랜덤으로 선택후, 제일 왼쪽으로 이동
		int pivot = left;

		low += 1;
		while (low <= high)
		{
			if (nums[low] > nums[pivot] && nums[high] < nums[pivot])
			{
				Swap(nums[low], nums[high]);
			}
			if (nums[low] < nums[pivot])
				low++;
			if (nums[high] > nums[pivot])
				high--;
		}
		Swap(nums[pivot], nums[high]);


		QuickSort(left, high - 1);
		QuickSort(high + 1, right);
	}
}

int Q2751() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	QuickSort(0, N-1);

	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << '\n';
	}
	
	return 0;
}