#include<iostream>
#include<queue>
using namespace std;

int Y, X;
char map[51][51] = { 0, };
bool burnd[51][51] = { 0, };
bool moved[51][51] = { 0, };

bool check(int y, int x) {
	if (y < 0 || y >= Y || x < 0 || x >= X)
		return false;
	return true;
}

int main()
{
	cin >> Y >> X;
	queue<pair<int, int>> burn;
	queue<pair<int, int>> move;

	for (int y = 0; y < Y; y++) {
		scanf("%s", &map[y]);
		for (int x = 0; x < X; x++) {
			if (map[y][x] == 'S') {
				moved[y][x] = true;
				move.push(make_pair(y, x));
			}
			else if (map[y][x] == '*') {
				burnd[y][x] = true;
				burn.push(make_pair(y, x));
			}if (map[y][x] == 'X') {
				moved[y][x] = true;
				burnd[y][x] = true;
			}
		}
	}

	int turn = 0;
	while (1)
	{
		int tt = burn.size();
		for (int i = 0; i < tt; i++) {
			if (check(burn.front().first - 1, burn.front().second) && !burnd[burn.front().first - 1][burn.front().second] && map[burn.front().first - 1][burn.front().second] != 'D') {
				burnd[burn.front().first - 1][burn.front().second] = true;
				burn.push(make_pair(burn.front().first - 1, burn.front().second));
			}if (check(burn.front().first + 1, burn.front().second) && !burnd[burn.front().first + 1][burn.front().second] && map[burn.front().first + 1][burn.front().second] != 'D') {
				burnd[burn.front().first + 1][burn.front().second] = true;
				burn.push(make_pair(burn.front().first + 1, burn.front().second));
			}if (check(burn.front().first, burn.front().second - 1) && !burnd[burn.front().first][burn.front().second - 1] && map[burn.front().first][burn.front().second - 1] != 'D') {
				burnd[burn.front().first][burn.front().second - 1] = true;
				burn.push(make_pair(burn.front().first, burn.front().second - 1));
			}if (check(burn.front().first, burn.front().second + 1) && !burnd[burn.front().first][burn.front().second + 1] && map[burn.front().first][burn.front().second + 1] != 'D') {
				burnd[burn.front().first][burn.front().second + 1] = true;
				burn.push(make_pair(burn.front().first, burn.front().second + 1));
			}

			burn.pop();
		}

		int t = move.size();
		if (t == 0)
		{
			printf("impossible");
			return 0;
		}
		for (int i = 0; i < t; i++) {
			if (map[move.front().first][move.front().second] == 'D') {
				printf("%d", turn);
				return 0;
			}


			if (check(move.front().first - 1, move.front().second) && !moved[move.front().first - 1][move.front().second] && !burnd[move.front().first - 1][move.front().second]) {
				moved[move.front().first - 1][move.front().second] = true;
				move.push(make_pair(move.front().first - 1, move.front().second));
			}if (check(move.front().first + 1, move.front().second) && !moved[move.front().first + 1][move.front().second] && !burnd[move.front().first + 1][move.front().second]) {
				moved[move.front().first + 1][move.front().second] = true;
				move.push(make_pair(move.front().first + 1, move.front().second));
			}if (check(move.front().first, move.front().second - 1) && !moved[move.front().first][move.front().second - 1] && !burnd[move.front().first][move.front().second - 1]) {
				moved[move.front().first][move.front().second - 1] = true;
				move.push(make_pair(move.front().first, move.front().second - 1));
			}if (check(move.front().first, move.front().second + 1) && !moved[move.front().first][move.front().second + 1] && !burnd[move.front().first][move.front().second + 1]) {
				moved[move.front().first][move.front().second + 1] = true;
				move.push(make_pair(move.front().first, move.front().second + 1));
			}
			move.pop();
		}




		turn++;
	}

}