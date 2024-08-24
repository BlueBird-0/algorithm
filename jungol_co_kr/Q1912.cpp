#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Room {
public:
	vector<int> link;
};

Room arr[100001];
vector<int> history;
bool visit[100001] = { false, };

void move(Room arr[], int now)
{
	history.push_back(now);
	visit[now] = true;

	sort(arr[now].link.begin(), arr[now].link.end());
	for (int e: arr[now].link)
	{
		if(!visit[e])
			move(arr, e);
	}

}


int main()
{
	int N, M;
	cin >> N >> M;
	int x1, x2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x1, &x2);
		arr[x1].link.push_back(x2);
		arr[x2].link.push_back(x1);
	}
	move(arr, 1);
	for (int e : history)
		printf("%d ", e);
}