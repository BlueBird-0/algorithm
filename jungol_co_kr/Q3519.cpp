#include<iostream>
#include<string>
using namespace std;

int _A[1001] = { 0, };
int _B[1001];
int N;

void mergeSort(int A[], int low, int high, int B[])
{
	//1. Base condition
	if (low >= high)
		return;
	//2. 분할
	int mid = (low + high) / 2;
	//3. 정복
	mergeSort(A, low, mid, B);
	mergeSort(A, mid + 1, high, B);
	//4. 결합
	int i = low;
	int j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (j > high)
			B[k] = A[i++];
		else if (i > mid)
			B[k] = A[j++];
		else if (A[i] <= A[j])
			B[k] = A[i++];
		else
			B[k] = A[j++];
	}
	//5. 복사
	for (i = low; i <= high; i++)
		A[i] = B[i];

	for (i = 0; i <= N-1; i++)
		cout << _A[i] <<" ";
	cout << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> _A[i];
	mergeSort(_A, 0, N - 1, _B);
	return 0;
}