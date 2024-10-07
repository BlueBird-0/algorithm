#include <iostream>
using namespace std; 
int arr[101] = { 0, };
int cost[101] = { 0, };
int costSum = 0;
int temp[10000] = { 0, };

int main()
{
	int N, M;
	cin >> N >> M;	//M바이트 확보
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &cost[i]);
		costSum += cost[i];
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int v = costSum; v >= 1; v--) {
			if (v - cost[i] >= 0) {
				temp[v] = max(temp[v], temp[v - cost[i]] + arr[i]);
			}
			if (i == N - 1 && temp[v] >= M) {
				result = v;
			}

		}
	}
	printf("%d", result);
}