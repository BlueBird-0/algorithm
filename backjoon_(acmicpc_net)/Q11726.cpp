#include <iostream>

using namespace std;

bool calCheck[1000] = { 0, };
int arr[1000] = { 0, };

int DP(int i)
{
	if (calCheck[i] == true) {
		return arr[i];
	}
	else {
		arr[i] = (DP(i - 2) + DP(i - 1)) % 10007;
		calCheck[i] = true;
		return arr[i];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	arr[0] = 0;
	calCheck[0] = true;
	arr[1] = 1;
	calCheck[1] = true;
	arr[2] = 2;
	calCheck[2] = true;

	/*for (int i = 0; i < 1000; i++) {
		printf("%d\n", DP(i));
	}*/

	int result = DP(n) % 10007;
	printf("%d", result);
}