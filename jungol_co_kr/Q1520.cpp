#include <iostream>
using namespace std;
int arr[10001] = { 0, };
int value[10001] = { 0, };

int check(int n)
{
	if (n == 0)
		return 0;
	if (value[n] == 0) {
		value[n] = max(check(n - 2) + arr[n - 1], check(n - 3) + arr[n - 2] + arr[n - 1]);
	}
	return value[n];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	value[1] = arr[0];
	value[2] = arr[0]+arr[1];

	printf("%d", check(n));

}