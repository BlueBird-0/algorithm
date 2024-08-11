#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int& x, int& y)
{
	return x > y;
}

int main()
{
	int i;
	int N;
	cin >> N;
	int arr[100001] = { 0,};
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//sort(&arr[0], &arr[8]);
	//reverse(arr + 0, arr + 8);
	sort(arr + 0, arr + N, compare);

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	
}