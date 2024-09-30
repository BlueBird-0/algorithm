#include <iostream>
#include <queue>
using namespace std;
int arr[1000][1000] = { 0, };
typedef struct tomato{
	int first;
	int second;
	int level;
}tomato;

queue<tomato> checker;

bool checkExistZero(int W, int H)
{
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++) {
			if (arr[y][x] == 0)
				return true;
		}
	}
	return false;
}

int main()
{
	int W, H;
	cin >> W >> H;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++) {
			scanf("%d", &arr[y][x]);
			if (arr[y][x] == 1)
				checker.push({y, x, 0});
		}
	}

	int result = 0;
	while (checker.size() != 0) {
		tomato* ptr = &checker.front();
		result = max(ptr->level, result);
		if (ptr->second - 1 >= 0 && arr[ptr->first][ptr->second - 1] == 0) {
			arr[ptr->first][ptr->second - 1] = ptr->level + 1;
			checker.push({ ptr->first, ptr->second - 1, ptr->level + 1 });
		}
		if (ptr->second + 1 < W && arr[ptr->first][ptr->second + 1] == 0) {
			arr[ptr->first][ptr->second + 1] = ptr->level + 1;
			checker.push({ ptr->first, ptr->second + 1, ptr->level + 1 });
		}
		if (ptr->first - 1 >= 0 && arr[ptr->first - 1][ptr->second] == 0) {
			arr[ptr->first - 1][ptr->second] = ptr->level + 1;
			checker.push({ ptr->first - 1, ptr->second, ptr->level + 1 });
		}
		if (ptr->first + 1 < H && arr[ptr->first + 1][ptr->second] == 0) {
			arr[ptr->first + 1][ptr->second] = ptr->level + 1;
			checker.push({ ptr->first + 1, ptr->second, ptr->level + 1 });
		}
		checker.pop();
	}

	/*for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++) {
			printf("%d", arr[y][x]);
		}
		printf("\n");
	}*/

	if (checkExistZero(W, H)) {
		printf("-1");
	}
	else {
		printf("%d", result);
	}
	return 0;
}