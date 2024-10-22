#include <iostream>
#include <map>
using namespace std;
int arr[9][9] = { 0, };
int counts[10] = { 0, };

bool ableHorizon(int y, int v) {
	for (int i = 0; i < 9; i++)
		if (arr[y][i] == v)
			return false;
	return true;
}

bool ableVertical(int x, int v) {
	for (int i = 0; i < 9; i++)
		if (arr[i][x] == v)
			return false;
	return true;
}

bool ableBox(int xx, int yy, int v) {
	int boxX = (xx) / 3;
	int boxY = (yy) / 3;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++) {
			if (arr[boxY * 3 + y][boxX * 3 + x] == v)
				return false;
		}
	}
	return true;
}

bool findResult(int zeros)
{
	if (zeros == 0)
		return true;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (arr[y][x] == 0) {
				for (int i = 1; i <= 9; i++) {
					if (counts[i] < 9 && ableHorizon(y, i) && ableVertical(x, i) && ableBox(x, y, i)) {
						arr[y][x] = i;
						counts[i]++;
						if (findResult(zeros - 1))
							return true;
						counts[i]--;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	int zeros = 0;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &arr[y][x]);
			if (arr[y][x] == 0)
				zeros++;
			else
				counts[arr[y][x]]++;
		}
	}

	findResult(zeros);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			printf("%-2d", arr[y][x]);
		}
		printf("\n");
	}



	return 0;
}