#include <iostream>
using namespace std;
int map[13][13] = { 0, };
bool check[13];
int minCost = 100000;

void move(bool check[], int N, int now, int cost, int depth)
{
	if (depth == N-1 || cost > minCost) {
		if (map[now][0] != 0) {
			int turnback = map[now][0] + cost;
			minCost = min(minCost, turnback);
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (i != now && !check[i] && map[now][i] != 0) {
			check[i] = true;
			move(check, N, i, cost + map[now][i], depth + 1);
			check[i] = false;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	check[0] = true;
	move(check, N, 0, 0, 0);
	cout << minCost;
}