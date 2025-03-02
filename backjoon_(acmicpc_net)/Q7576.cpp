#include <iostream>
#include <queue>

using namespace std;
int arr[1000][1000] = {0,};
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	queue<pair<int, int>> que;
	//input
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &arr[y][x]);

			if (arr[y][x] == 1) {
				que.push(make_pair(y, x));
			}
		}
	}
	
	//check day
	int day = -1;
	for (day = -1; !que.empty(); day++) {
		int queSize = que.size();

		for (int i = 0; i < queSize; i++) {
			pair<int, int> pos = que.front();
			que.pop();

			if (pos.first > 0 && arr[pos.first - 1][pos.second] == 0) {
				arr[pos.first - 1][pos.second] = 1;
				que.push(make_pair(pos.first - 1, pos.second));
			}
			if (pos.first < n - 1 && arr[pos.first + 1][pos.second] == 0) {
				arr[pos.first + 1][pos.second] = 1;
				que.push(make_pair(pos.first + 1, pos.second));
			}
			if (pos.second > 0 && arr[pos.first][pos.second - 1] == 0) {
				arr[pos.first][pos.second - 1] = 1;
				que.push(make_pair(pos.first, pos.second - 1));
			}
			if (pos.second < m - 1 && arr[pos.first][pos.second + 1] == 0) {
				arr[pos.first][pos.second + 1] = 1;
				que.push(make_pair(pos.first, pos.second + 1));
			}
		}
	}

	//check zero
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] == 0) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", day);
	

	return 0;
}