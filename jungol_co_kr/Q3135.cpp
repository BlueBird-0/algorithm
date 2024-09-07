#include <iostream>
using namespace std;

int arr[1000001];
long long sumArr[1000001] = { 0, };
int main()
{
	int N, M;
	cin >> N;
	cin.tie(NULL);
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		sumArr[i] = sum;
	}
	cin >> M;
	int stt, end;
	for (int i = 0; i < M; i++) {
		cin >> stt >> end;

		printf("%lld\n", sumArr[end] - sumArr[stt-1]);
	}
}