#include <iostream>
#include <string>
using namespace std;

bool map[1024][1024] = { 0, };
string str;
int now = 0;
int strSize;

void check(int l, int u, int r, int d, int& charIdx) {
	if (charIdx >= strSize)
		return;
	if (str[charIdx] == '1') {
		for (int y = u; y < d; y++) {
			for (int x = l; x < r; x++) {
				map[y][x] = true;
			}
		}
		charIdx += 1;
	}
	else if (str[charIdx] == '0') {
		for (int y = u; y < d; y++) {
			for (int x = l; x < r; x++) {
				map[y][x] = false;
			}
		}
		charIdx += 1;
	}
	else if (str[charIdx] == 'X') {
		int midX = l + (r - l) / 2;
		int midY = u + (d - u) / 2;
		charIdx += 1;

		check(l, u, midX, midY, charIdx);
		check(midX, u, r, midY, charIdx);
		check(l, midY, midX, d, charIdx);
		check(midX, midY, r, d, charIdx);
	}
}

int main()
{
	int n;
	cin >> n;
	cin >> str;
	strSize = str.size();

	check(0, 0, n, n, now);
	printf("%d\n", n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%-2d", map[y][x]);
		}
		printf("\n");
	}


	
	return 0;
}