#include <iostream>
#include <queue>
using namespace std;

namespace {
	int map[100][100];
	int N, M;

	bool checkDown(int x, int y) {
		if (y + 1 < N) {
			if (map[y + 1][x] == 1) {
				if (y == 0 && x == 0)
					map[y + 1][x] += 1;
				else map[y + 1][x] += map[y][x];
				return true;
			}
		}
		return false;
	}

	bool checkUp(int x, int y) {
		if (y - 1 >= 0) {
			if (map[y - 1][x] == 1) {
				if (y == 0 && x == 0)
					map[y - 1][x] += 1;
				else map[y - 1][x] += map[y][x];
				return true;
			}
		}
		return false;
	}

	bool checkLeft(int x, int y) {
		if (x - 1 >= 0) {
			if (map[y][x - 1] == 1) {
				if (y == 0 && x == 0)
					map[y][x - 1] += 1;
				else map[y][x - 1] += map[y][x];
				return  true;
			}
		}
		return false;
	}

	bool checkRight(int x, int y) {
		if (x + 1 < M) {
			if (map[y][x + 1] == 1) {
				if (y == 0 && x == 0)
					map[y][x + 1] += 1;
				else map[y][x + 1] += map[y][x];
				return true;
			}
		}
		return false;
	}
}


int Q2178() {
	cin >> N >> M;

	for (int y=0; y<N; y++)
	{
		cin.get();
		for (int x=0; x<M; x++)
		{
			char temp = cin.get();
			map[y][x] = temp - '0';
		}
	}

	int posX = 0;
	int posY = 0;
	queue<pair<int, int>>Q;
	map[0][0] = 0;

	Q.push(make_pair(posX, posY));

	while (Q.size() != 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		if (x == M - 1 && y == N - 1)
		{
			cout << map[y][x];
			return 0;
		}

		if (checkRight(x, y)) {
			Q.push(make_pair(x + 1, y));
		}
		if (checkLeft(x, y)) {
			Q.push(make_pair(x - 1, y));
		}
		if (checkUp(x, y)) {
			Q.push(make_pair(x, y - 1));
		}
		if (checkDown(x, y)) {
			Q.push(make_pair(x, y + 1));
		}


	}

	cout << "rsult";
	return 0; 
}