#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int X, Y;
int map[102][102] = { 0, };
bool visit[102][102] = { 0, };

vector<pair<int, int>> arr;
void spread(int x, int y) {
	if (x < 0 || x >= X + 2 || y < 0 || y >= Y + 2 || visit[y][x]) {
		return;
	}
	visit[y][x] = true;
	if (map[y][x] == 0) {
		spread(x - 1, y);
		spread(x + 1, y);
		spread(x, y - 1);
		spread(x, y + 1);
	}

	if (map[y][x] ==1) {
		arr.push_back(make_pair(y, x));
	}
}

int main()
{
	scanf("%d %d", &Y, &X);
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%d", &map[y+1][x+1]);
		}
	}

	int time = 0;
	int melt = 0;
	while (true) {
		arr.clear();		
		memset(visit, false, 102 * 102);
		spread(0, 0);


		if (arr.size() == 0)
			break;
		time++;
		melt = arr.size();
		for (auto e : arr) {
			map[e.first][e.second] = 0;
		}
		/*printf("\n\n");
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				printf("%d ", map[y + 1][x + 1]);
			}
			printf("\n");
		}*/
	}
	cout << time << endl;
	cout << melt;
}