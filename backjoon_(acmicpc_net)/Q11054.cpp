#include <iostream>
#include <vector>
using namespace std;
int num[1001] = { 0, };
int increase[1001] = { 0, };
int decrease[1001] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	//increase
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j] && increase[j] > max)
				max = increase[j];
		}
		increase[i] = max + 1;
	}
	//decrease
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (num[n - i - 1] > num[n - j - 1] && decrease[n - j - 1] > max)
				max = decrease[n - j - 1];
		}
		decrease[n - i - 1] = max + 1;
	}

	/*
	for (int i = 0; i < n; i++) {
		printf("%d ", increase[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", decrease[i]);
	}
	*/
	int maxIdx = 0;
	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		if (maxSum < increase[i] + decrease[i]) {
			maxSum = increase[i] + decrease[i];
			maxIdx = i;
		}
	}
	printf("%d", maxSum - 1);
}