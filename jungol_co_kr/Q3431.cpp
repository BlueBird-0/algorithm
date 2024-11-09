#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr(100000);	// x1, x2
vector<vector<int>> link(100000);
int main()
{
	int N, Q;
	cin >> N >> Q;
	int y;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i].first, &arr[i].second, &y);
	}
	sort(&arr[0], &arr[N]);
	
	int minV, maxV=0;
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].first <= maxV)
			continue;

		minV = arr[i].first;
		maxV = max(arr[i].second, maxV);

		for (int j = i + 1; j < N; j++) {
			if (arr[j].first <= maxV) {
				link[a].push_back(j);
				maxV = max(arr[j].second, maxV);
			}
			else {
				break;
			}
		}

		a++;
	}

	int stt, end;
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &stt, &end);
	}

	for (auto e : link) {
		for (auto f : e) {
			printf("%3d", f);
		}
		printf("\n");
	}
}