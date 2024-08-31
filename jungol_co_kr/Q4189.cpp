#include <iostream>
#include <queue>
using namespace std;
bool map[1001][1001] = { 0, };
int X, Y, resultX, resultY;

class st {
public:
	st(int y, int x, int c):x(x), y(y), c(c) {}
	int y, x, c;
};
queue<st> q;

int result = 0;
inline bool visit(int y, int x)
{
	if (x<1 || x>X || y<1 || y>Y || map[y][x] == true)
		return false;
	return true;
}
void move(int y, int x)
{
	q.push(st(y, x, 0));

	while (!q.empty()) {
		st t = q.front();
		q.pop();

		if (t.y == resultY && t.x == resultX) {
			result = t.c;
			return;
		}
		else {
			map[t.y][t.x] = true;
			if (visit(t.y - 2, t.x - 1)) {
				map[t.y - 2][t.x - 1] = true;
				q.push(st(t.y - 2, t.x - 1, t.c + 1));
			}
			if (visit(t.y - 1, t.x - 2)) {
				map[t.y - 1][t.x - 2] = true;
				q.push(st(t.y - 1, t.x - 2, t.c + 1));
			}
			if (visit(t.y + 1, t.x - 2)) {
				map[t.y + 1][t.x - 2] = true;
				q.push(st(t.y + 1, t.x - 2, t.c + 1));
			}
			if (visit(t.y + 2, t.x - 1)) {
				map[t.y + 2][t.x - 1] = true;
				q.push(st(t.y + 2, t.x - 1, t.c + 1));
			}
			if (visit(t.y + 2, t.x + 1)) {
				map[t.y + 2][t.x + 1] = true;
				q.push(st(t.y + 2, t.x + 1, t.c + 1));
			}
			if (visit(t.y + 1, t.x + 2)) {
				map[t.y + 1][t.x + 2] = true;
				q.push(st(t.y + 1, t.x + 2, t.c + 1));
			}
			if (visit(t.y - 1, t.x + 2)) {
				map[t.y - 1][t.x + 2] = true;
				q.push(st(t.y - 1, t.x + 2, t.c + 1));
			}
			if (visit(t.y - 2, t.x + 1)) {
				map[t.y - 2][t.x + 1] = true;
				q.push(st(t.y - 2, t.x + 1, t.c + 1));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &X, &Y);
	int x, y;
	scanf("%d %d", &x, &y);
	scanf("%d %d", &resultX, &resultY);
	move(y, x);
	printf("%d", result);
}