#include <iostream>
using namespace std;

int binarySearch(int A[], int low, int high, int target) {
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (target == A[mid])
			return mid;
		else if (target < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int binarySearchRecur(int A[], int low, int high, int target) {
	if (low >= high)
		return -1;
	int mid = (low + high) / 2;
	if (target == A[mid])
		return mid;
	else if (target < A[mid])
		return binarySearchRecur(A, low, mid - 1, target);
	else
		return binarySearchRecur(A, mid + 1, high, target);
}

int main()
{
	int N, Q;
	scanf("%d", &N);
	int *arr = new int[500001];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &Q);
	int  num;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &num);
		printf("%d ", binarySearch(arr, 0, N - 1, num));
	}
}