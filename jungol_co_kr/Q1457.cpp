#include <iostream>
#include <algorithm>
using namespace std;
bool map[100][100] = { 0, };
int mapInt[100][100] = { 0, };
int arr[100] = { 0, };


void spread(int y, int x,int M, int N, int index)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return;
	if (!map[y][x]) {
		map[y][x] = true;
		arr[index]++;
		spread(y, x - 1, M, N, index);
		spread(y, x + 1, M, N, index);
		spread(y - 1, x, M, N, index);
		spread(y + 1, x, M, N, index);
	}
}

void fill(pair<int, int> &lBottom, pair<int, int> &rTop) {
	for (int y = lBottom.second; y < rTop.second; y++) {
		for (int x = lBottom.first; x < rTop.first; x++) {
			map[y][x] = true;
		}
	}
}
int main()
{
	int M, N, K;
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		pair<int, int> lBottom;
		pair<int, int> rTop;
		scanf("%d %d %d %d", &lBottom.first, &lBottom.second, &rTop.first, &rTop.second);
		fill(lBottom, rTop);
	}

	/*for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}*/


	int index = 1;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (!map[y][x]) {
				spread(y, x, M, N, index);
				index++;
			}
		}
	}
	cout << index - 1 << endl;
	sort(&arr[1], &arr[index]);
	for (int i = 1; i < index; i++)
		cout << arr[i] << " ";

	return 0;
}