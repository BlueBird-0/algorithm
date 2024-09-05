#include <iostream>
using namespace std;

int arr[64001] = { 0, };
int value[64001] = { 0, };

int main()
{
	int N, cost;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> cost;

	for (int i = 0; i <= cost; i++) {
		value[i] = 1<<28;
	}
	value[0] = 0;
	for (int i = 0; i < N; i++) {
		value[arr[i]] = 1;
	}

	for (int i = 1; i <= cost; i++) {
		for (int j = 0; j < i; j++) {
			value[i] = min(value[j]+value[i-j], value[i]);
		}
	}


	if (value[cost] == 1 << 28)
		printf("impossible");
	else
		printf("%d", value[cost]);
}