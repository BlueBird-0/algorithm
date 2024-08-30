#include <iostream>
#include <string>
#include <queue>
using namespace std;

int X, Y;
int map[100][100] = { 0, };
int result = 0;

class C {
public:
	C(int y, int x, int t):y(y), x(x), time(t) {}
	int y;
	int x;
	int time;
};
queue<C> que;

void poison(int y, int x, int time) {
	if (x < 0 || x >= X || y < 0 || y >= Y || map[y][x] == 0)
		return;
	if (map[y][x] == 1) {
		result = max(time + 3, result);
		map[y][x]--;


		que.push(C(y, x - 1, time + 1));
		que.push(C(y, x + 1, time + 1));
		que.push(C(y - 1, x, time + 1));
		que.push(C(y + 1, x, time + 1));

		while (!que.empty()) {
			C c = que.front();
			que.pop();
			poison(c.y, c.x, c.time);
		}
	}

}

int main() {
	cin >> X >> Y;

	const char str[100] ="";
	for (int y = 0; y < Y; y++) {
		scanf("%s", str);
		for (int x = 0; x < X; x++) {
			map[y][x] = str[x]-'0';
		}
	}
	int x, y;
	cin >> x >> y;
	poison(y-1, x-1, 0);

	int count = 0; 
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == 1)
				count++;
		}
	}

	printf("%d\n%d", result, count);
}