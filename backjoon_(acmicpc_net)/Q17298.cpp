#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<pair<int, int>> nge;

	int n, temp;
	scanf("%d", &n);
	int* result = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		pair<int, int> newValue = make_pair(i, temp);


		while (!nge.empty() && nge.top().second < newValue.second) {
			result[nge.top().first] = newValue.second;
			nge.pop();
		}
		nge.push(newValue);
	}

	while (!nge.empty()) {
		result[nge.top().first] = -1;
		nge.pop();
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	delete result;
}