#include <iostream>
using namespace std;

int N;
void quickSort(int A[], int low, int high)
{
	if (low >= high)
		return;
	int i = low;
	int pivot = A[high];
	for (int j = low; j < high; j++)
	{
		if (A[j] < pivot) {
			swap(A[i++], A[j]);
		}
	}
	swap(A[i], A[high]);
	//print
	for (int j = 0; j < N; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;

	quickSort(A, low, i - 1);
	quickSort(A, i + 1, high);
}
int main()
{
	cin >> N;
	int A[1000];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	quickSort(A, 0, N-1);

}