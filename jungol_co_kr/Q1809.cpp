#include <iostream>
#include <stack>
int arr[500001] = { 0, };
int result[500001] = { 0, };

using namespace std;
stack<pair<int, int>> q;	// value, idx

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		int temp = arr[i];
		while (true) {
			if (q.empty() || q.top().first >= temp)
				break;
			if (temp > q.top().first) {
				q.pop();
			}
		}
		if(!q.empty())
			result[i] = q.top().second;
		q.push(make_pair(temp, i+1));
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}

// 6 9 5 7 4

