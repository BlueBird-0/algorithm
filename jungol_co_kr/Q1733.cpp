#include <iostream>

using namespace std;

static const int DARK = 1;
static const int WHITE = 2;

int result_x;
int result_y;
int checkL(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkL(go, x - 1, y, stone, depth+1);
}
int checkR(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkR(go, x + 1, y, stone, depth + 1);
}
int checkU(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkU(go, x, y - 1, stone, depth + 1);
}
int checkD(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkD(go, x, y + 1, stone, depth + 1);
}

int checkLU(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkLU(go, x - 1, y - 1, stone, depth + 1);
}
int checkRD(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkRD(go, x + 1, y + 1, stone, depth + 1);
}
int checkRU(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkRU(go, x + 1, y - 1, stone, depth + 1);
}
int checkLD(int go[21][21], int x, int y, int stone, int depth)
{
	if (go[y][x] != stone)
		return depth;
	return checkLD(go, x - 1, y + 1, stone, depth + 1);
}

int main()
{
	int go[21][21] = {0,};
	for (int y = 0; y < 19; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			cin >> go[y+1][x+1];
		}
	}

	int winner = 0;
	for (int y = 1; y < 21; y++)
	{
		for (int x = 1; x < 21; x++)
		{
			if (go[y][x] != 0)
			{
				int horizon = checkL(go, x-1, y, go[y][x], 0) + checkR(go, x+1, y, go[y][x], 0);
				if (horizon == 4)
				{
					winner = go[y][x];
					result_x = x;
					result_y = y;
					break;
				}
				int vertical = checkU(go, x, y-1, go[y][x], 0) + checkD(go, x, y+1, go[y][x], 0);
				if (vertical == 4)
				{
					winner = go[y][x];
					result_x = x;
					result_y = y;
					break;
				}
				int slash1 = checkLU(go, x-1, y-1, go[y][x], 0) + checkRD(go, x+1, y+1, go[y][x], 0);
				if (slash1 == 4)
				{
					winner = go[y][x];
					result_x = x;
					result_y = y;
					break;
				}
				int slash2 = checkLD(go, x-1, y+1, go[y][x], 0) + checkRU(go, x+1, y-1, go[y][x], 0);
				if (slash2 == 4)
				{
					winner = go[y][x];
					result_x = x - 4;
					result_y = y + 4;
					break;
				}
			}
		}
		if (winner != 0)
			break;
	}
	cout << winner << endl;
	if(winner!=0)
		cout << result_y << " " <<result_x;
}