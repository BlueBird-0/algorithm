#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000] = { 0, };

int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(&arr[0], &arr[N]);

	int top = 1000000000;
	int btm = 0;
	int mid = (top + btm) / 2;
	int result = 0;
	while (1) {
		int count = 1;
		int nowIdx = 0;
		for (int i = nowIdx + 1; i < N; i++) {
			if (arr[i] - arr[nowIdx] >= mid) {
				count++;
				nowIdx = i;
				if (count >= C)
					break;
			}
		}
		if (count < C) {//불가능
			top = mid - 1;
			mid = (top + btm) / 2;
		}
		else {//가능
			result = max(result, mid);
			btm = mid + 1;
			mid = (top + btm) / 2;
		}
		if (btm > top)
			break;
	}
	printf("%d", result);
}