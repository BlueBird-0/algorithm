#include <iostream>
#include <queue>

using namespace std;
int map[101][101] = { 0, };
class piece {
public:
	int x, y;
};

class fun {
public:
	int x, y, count;
	fun(int x, int y, int c):x(x),y(y),count(c) {}
};

bool findPawn = false;
queue <fun> Q;
void move(int x, int y, piece& knight, int N, int M, int count) {
	if (x < 1 || x > N || y < 1 || y > M || map[x][y] != 0)
		return ;
	if (findPawn)
		return ;
	if (x == knight.x && y == knight.y) {
		cout << count;
		findPawn = true;
		return ;
	}
	else
		map[x][y] = count+1;
	Q.push(fun(x - 2, y - 1, count + 1));
	Q.push(fun(x - 1, y - 2, count + 1));
	Q.push(fun(x + 1, y - 2, count + 1));
	Q.push(fun(x + 2, y - 1, count + 1));
	Q.push(fun(x + 2, y + 1, count + 1));
	Q.push(fun(x + 1, y + 2, count + 1));
	Q.push(fun(x - 1, y + 2, count + 1));
	Q.push(fun(x - 2, y + 1, count + 1));

	while(Q.size() != 0) {
		fun f = Q.front();
		Q.pop();
		move(f.x, f.y, knight, N, M, f.count);
	}
}

int main()
{
	piece knight;
	int N, M;
	scanf("%d %d", &N, &M);
	int x, y;
	scanf("%d %d %d %d", &knight.x, &knight.y, &x, &y);
	move(x, y, knight, N, M, 0);

}