#include <iostream>
using namespace std;
int N, M;
int arr[301];


bool check(int mid)
{
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + arr[i] <= mid) {
			sum += arr[i];
		}
		else {
			if (arr[i] <= mid)
				sum = arr[i];
			else
				return false;
			cnt++;
		}
	}
	return cnt <= M;
}

int main()
{
	int i, j;
	int low = 0, high = 30000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	while (low < high)
	{
		int mid = (low + high) / 2;
		if (check(mid)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	cout << high;
}