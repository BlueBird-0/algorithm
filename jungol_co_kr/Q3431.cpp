#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

int N, Q;

class TREE{
public:
	int stt;
	int end;
	vector<int> link;
};

TREE arr[100001];

int main()
{
	cin >> N >> Q;
	int y;
	TREE temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &temp.stt, &temp.end, &y);
		arr[i] = temp;

		for (int j = 1; j < i; j++) {
			if ((arr[j].stt <= arr[i].stt && arr[j].end >= arr[i].stt) || (arr[j].stt <= arr[i].end && arr[j].end >= arr[i].end) ||
				(arr[i].stt <= arr[j].stt && arr[i].end >= arr[j].stt) || (arr[i].stt <= arr[j].end && arr[i].end >= arr[j].end)) {
				arr[j].link.push_back(i);
				arr[i].link.push_back(j);
			}
		}
	}

	//Ã£±â
	int q1, q2;
	bool visit[100001];
	for (int i = 0; i < Q; i++) {
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &q1, &q2);

		queue<int> links;
		for (auto e : arr[q1].link) {
			links.push(e);
		}

		bool arrive = false;
		while (!links.empty()) {
			int t = links.front();
			links.pop();
			visit[t] = true;

			if (t == q2) {
				arrive = true;
				break;
			}

			for (auto e : arr[t].link) {
				if (!visit[e]) {
					links.push(e);
				}
			}
		}
		printf("%d\n", arrive? 1 : 0);
	}
}