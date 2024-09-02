#include <iostream>

using namespace std;

bool arr[41] = { 0 , };
int num[41] = { 0, };

int check(int n)
{
	if (num[n] == 0)
		num[n] = check(n - 1) + check(n - 2);
	return num[n];
}

int main()
{
	num[0] = 1;
	num[1] = 1;
	num[2] = 2;
	
	int c, n, num;
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr[num] = true;
	}

	int count = 0;
	int result = 1;
	for (int i = 1; i <= c; i++)
	{
		if (arr[i]) {
			result *= check(count);
			count = 0;
		}
		else {
			count++;
		}
	}
	result *= check(count);

	printf( "%d", result);
}