#include <iostream>

using namespace std;
int arr[5001] = { 0, };
int result[5001] = { 0, };

bool isPrime(int n)
{
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int maxPrime(int n)
{
	for (int i = n; i >= 1; i--)
	{
		if (n % i == 0) {
			if (isPrime(i))
				return i;
		}
	}
	return 1;
}
int main()
{
	int N;
	cin >> N;

	int result = 0;
	int resultIdx = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		int m = maxPrime(arr[i]);
		if (m > result) {
			result = m;
			resultIdx = i;
		}
	}
	printf("%d", arr[resultIdx]);
}