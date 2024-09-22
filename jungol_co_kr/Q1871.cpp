#include <iostream>
using namespace std;
int N;
int arr[201] = { 0, };
int LCS[201] = { 0, };

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	int lcs = -1;
	for (int i = N; i > 0; i--) {
		int pivot = arr[i];
		int maxV = 0;
		for (int k = i + 1; k <= N; k++) {
			if (pivot < arr[k] && maxV < LCS[k]) {
				maxV = LCS[k];
			}
		}
		LCS[i] = maxV + 1;

		lcs = max(lcs, LCS[i]);
	}
	printf("%d", N - lcs);
}