#include <iostream>
#include <memory.h>
using namespace std;
int arr[100001] = { 0, };

int fibo(int N) {
	if (arr[N] != -1)
		return arr[N] % 1000000007;
	else {
		arr[N] = fibo(N - 2) + fibo(N - 1);
		return arr[N] % 1000000007;
	}
}

int main()
{
	memset(arr, -1, sizeof(int) * 100001);
	arr[0] = arr[1] = arr[2] = 1;

	int N;
	cin >> N;
	

	printf("%d", fibo(N));


	return 0;
}