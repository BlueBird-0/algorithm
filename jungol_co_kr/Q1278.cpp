#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[1001][10001] = { 0, };

int main()
{
	vector<pair<int, int>> arr;
	int N, W, w, v;
	cin >> N >> W;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &w, &v);
		arr.push_back(make_pair(w, v));
	}
	sort(arr.begin(), arr.end());

	//init
	for (int y = 0; y < arr.size(); y++) {
		for (int x = arr[y].first; x <= W; x++) {
			map[y][x] = arr[y].second;
		}
	}


	//DP 계산
	for (int x = 1; x <= W; x++) {
		for (int y = arr.size() - 2; y >= 0; y--)
		{
			int temp  = max(map[y+1][x], map[y][x-1]);
			if((x - arr[y].first) > 0)
				temp = max(map[y + 1][(x - arr[y].first)] + arr[y].second, temp);
			map[y][x] = max(temp, map[y][x]);
		}
	}

	//출력테스트
	/*for (int y = 0; y < arr.size(); y++) {
		for (int x = 0; x <= W; x++) {
			printf("%4d ", map[y][x]);
		}
		printf("\n");
	}*/
	printf("%d", map[0][W]);
}