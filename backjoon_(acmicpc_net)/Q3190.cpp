#include <iostream>
#include <queue>
using namespace std;

const int WALL = 1;
const int APPLE = 2;
const int PLAYER = 3;
int map[101][101] = { 0, };
struct character {
	queue<pair<int, int>> pos;	// y, x
	int dir = 0; // 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
	void move() {
		if (dir == 0)
			pos.push(make_pair(pos.back().first, pos.back().second + 1));
		else if(dir == 1)
			pos.push(make_pair(pos.back().first + 1, pos.back().second));
		else if(dir == 2)
			pos.push(make_pair(pos.back().first, pos.back().second - 1));
		else if(dir == 3)
			pos.push(make_pair(pos.back().first - 1, pos.back().second));
	}
	void turnLeft() {
		dir += 4;
		dir--;
		dir %= 4;
	}
	void turnRight() {
		dir++;
		dir %= 4;
	}
};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][n + 1] = WALL;
		map[n + 1][i] = WALL;
	}

	for (int i = 0; i < k; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		map[y][x] = APPLE;
	}
	queue<pair<int, char>> commands;
	int cmdCount;
	scanf("%d", &cmdCount);
	for (int i = 0; i < cmdCount; i++) {
		int time;
		char ch;
		scanf("%d %c", &time, &ch);
		commands.push(make_pair(time, ch));
	}
	
	//PLAY
	character player;
	player.pos.push(make_pair(1, 1));

	int time = 0;
	while (1) {
		time++;
		//Move
		player.move();

		pair<int, int>& newPos = player.pos.back();

		

		if (map[newPos.first][newPos.second] == WALL || map[newPos.first][newPos.second] == PLAYER) {
			break;
		}

		if (map[newPos.first][newPos.second] != APPLE) {
			map[player.pos.front().first][player.pos.front().second] = 0;
			player.pos.pop();
		}

		map[newPos.first][newPos.second] = PLAYER;

		//change direct
		if (!commands.empty() && commands.front().first == time) {
			if (commands.front().second == 'L') {
				player.turnLeft();
			}
			else if (commands.front().second == 'D') {
				player.turnRight();
			}
			commands.pop();
		}
	}
	printf("%d", time);

	return 0;
}