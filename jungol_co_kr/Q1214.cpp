#include <iostream>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;
int N;
stack<pair<int, int>> arr;
int temp[100001] = { 0, };

int main() {
	cin >> N;

	int newH=0, prev = 0;

	int stackMaxArea = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &newH);
		if (prev < newH) {
			arr.push(make_pair(i, newH));
		}
		else {
			int sum = 0;
			int maxIdx = 0;
			int minIdx = INT_MAX;
			while (!arr.empty()) {
				if (arr.top().second > newH) {
					maxIdx = max(maxIdx, arr.top().first);
					minIdx = min(minIdx, arr.top().first);
					sum = max(sum, arr.top().second * (maxIdx - minIdx + 1));

					stackMaxArea = max(stackMaxArea, sum + temp[arr.top().first]);
					arr.pop();
				}
				else {
					arr.push(make_pair(i, newH));
					temp[i] = (maxIdx - minIdx + 1) * newH;
					break;
				}
			}
		}

		prev = newH;
	}
	int maxIdx = 0;
	int minIdx = INT_MAX;
	while (!arr.empty()) {
		if (arr.top().second > newH) {
			maxIdx = max(maxIdx, arr.top().first);
			minIdx = min(minIdx, arr.top().first);

			stackMaxArea = max(stackMaxArea, arr.top().second * (maxIdx - minIdx + 1));
			arr.pop();
		}
		else
			break;
	}
	printf("%d", stackMaxArea);
}