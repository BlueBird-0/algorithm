#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
struct TREE {
	int s, e, v;
};

vector<TREE> arr(100000);	// x1, x2
vector<map<int, bool>> link;
int main()
{
	int N, Q;
	cin >> N >> Q;
	int y;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i].s, &arr[i].e, &y);
		arr[i].v = i + 1;
	}
	sort(&arr[0], &arr[N], [](TREE &a, TREE &b)->int{
		if (a.s == b.s) {
			return a.e < b.e;
		}
		return a.s < b.s;
	});
	
	int minV, maxV=0;
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].s <= maxV)
			continue;

		minV = arr[i].s;
		maxV = max(arr[i].e, maxV);
		link.push_back(map<int, bool>());
		link[a][arr[i].v] = true;

		for (int j = i + 1; j < N; j++) {
			if (arr[j].s <= maxV) {
				link[a][arr[j].v] = true;
				maxV = max(arr[j].e, maxV);
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

		bool able = false;
		for (auto e : link) {
			if (e[stt] && e[end]) {
				able = true;
				break;
			}
		}
		printf("%d\n", able ? 1 : 0);
	}

	/*for (auto e : link) {
		for (auto f : e) {
			printf("%3d", f);
		}
		printf("\n");
	}*/
}