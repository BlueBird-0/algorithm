#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N;
int arr[1000];

int main()
{

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(&arr[0], &arr[N]);

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		if (res + 1 < arr[i])
			break;
		res += arr[i];
	}
	res += 1;

	printf("%d\n", res);

	return 0;
}