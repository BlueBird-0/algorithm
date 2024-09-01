#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int Y, X;
int map[50][50] = { false, };
int map2[50][50] = { false, };

struct st {
	int x, y, v;
};

bool check(int temp[50][50], int x, int y) {
	if (x < 0 || x >= X || y < 0 || y >= Y || temp[y][x]!=-1)
		return false;
	return true;
}

st fill(int temp[50][50], int x, int y)
{
	st max = { x,y, 0 };
	queue<st> q;
	q.push(max);

	while (!q.empty()) {
		st t = q.front();
		q.pop();

		if (check(temp, t.x, t.y))
		{
			temp[t.y][t.x] = t.v;
			if (t.v > max.v) {
				max = t;
			}
			q.push({ t.x + 1, t.y, t.v + 1 });
			q.push({ t.x - 1, t.y, t.v + 1 });
			q.push({ t.x, t.y + 1, t.v + 1 });
			q.push({ t.x, t.y - 1, t.v + 1 });
		}
	}
	return max;
}

int main()
{
	cin >> Y >> X;
	string str;
	for (int y = 0; y < Y; y++) {
		cin >> str;
		for (int x = 0; x < X; x++) {
			if (str[x] == 'L') {
				map[y][x] = -1;
				map2[y][x] = -1;
			}
			
		}
	}

	//max
	int maxDistance = 0;

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x]) {
				st ob1 = fill(map2, x, y);
				memcpy(map2, map, sizeof(int) * 50 * 50);
				maxDistance = max(ob1.v, maxDistance);
			}
		}
	}


	
	printf("%d", maxDistance);
	/*
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == 0)
				printf("   ");
			else 
				printf("%2d ", map[y][x]);
		}
		printf("\n");
	}*/
}