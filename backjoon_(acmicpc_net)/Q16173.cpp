#include <iostream>
using namespace std;
int map[3][3];
bool arrive = false;
int N;

void move(int x, int y) {
	if (x >= N || y >= N || map[y][x] == 0)
		return;
	if (map[y][x] == -1) {
		arrive = true;
		return;
	}
	if(x+map[y][x] <= N)
		move(x + map[y][x], y);
	if(y+map[y][x] <= N)
		move(x, y + map[y][x]);
}

int main()
{
	cin >> N;
	for(int y=0; y<N; y++){
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	move(0, 0);

	printf("%s", arrive? "HaruHaru" : "Hing");

	return 0;
}