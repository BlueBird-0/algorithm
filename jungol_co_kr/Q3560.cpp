#include <iostream>
#include <string>
using namespace std;

bool map[1024][1024];
string result = "";

bool check(int _x, int _y, int size) {
	if (size == 1)
		return true;

	bool ch = map[_y][_x];
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
		{
			if (ch != map[_y + y][_x + x])
				return false;
		}
	return true;
}

void divide(int x, int y, int size) {
	if (check(x, y, size)) {
		result += ('0' + map[y][x]);
	}
	else {
		result += 'X';

		int harf = size / 2;
		divide(x, y, harf);
		divide(x + harf, y, harf);
		divide(x, y + harf, harf);
		divide(x + harf, y + harf, harf);
	}
}

int main()
{
	int N, n;
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			scanf("%d", &n);
			map[y][x] = n ? true : false;
		}
	divide(0, 0, N);
	cout << result;
}