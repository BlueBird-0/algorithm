#include <iostream>
using namespace std;

int arr[100001] = { 0, };
int fun(int n) {
	if (arr[n] == 0)
		arr[n] = fun(n - 1) + fun(n - 2) * 2;
	return arr[n] % 20100529;
};

int main()
{
	arr[1] = 1;
	arr[2] = 3;
	int N;
	cin >> N;
	printf("%d", fun(N));

	return 0;
}