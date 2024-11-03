#include <iostream>
using namespace std;
bool map[100][100] = { 0, };
int N;
void fill(int sttx, int stty) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			map[stty + y][sttx + x] = true;
		}
	}
}

int cal(int x, int y, int xx, int yy) {

	for (int i = x; i <= xx; i++) {
		for (int j = y; j <= yy; j++) {
			if (!map[j][i])
				return 0;
		}
	}
	return (xx - x + 1) * (yy - y + 1);
}

int main()
{
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		fill(x, y);
	}

	int result = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {

			for (int yy = y; yy < 100; yy++) {
				for (int xx = x; xx < 100; xx++) {
					if (result >= (xx - x + 1) * (yy - y + 1))
						continue;

					result = max(result, cal(x, y, xx, yy));
				}
			}
		}
	}
	printf("%d", result);
}
