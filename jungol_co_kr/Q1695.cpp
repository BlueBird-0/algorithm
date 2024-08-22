#include <iostream>
#include <algorithm>
using namespace std;
bool map[25][25] = { 0, };
int mapInt[25][25] = { 0, };
int arr[25] = { 0, };


void spread(int y, int x, int N, int index)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return;
	if (map[y][x]) {
		map[y][x] = false;
		arr[index]++;
		spread(y, x-1, N, index);
		spread(y, x+1, N, index);
		spread(y-1, x, N, index);
		spread(y+1, x, N, index);
	}
}
int main()
{
	int N;
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			char ch;
			scanf("%c", &ch);
			if (ch == '0')
				map[y][x] = false;
			else if (ch == '1')
				map[y][x] = true;
			else
				x--;
		}
	}

	int index = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x]) {
				spread(y, x, N, index);
				index++;
			}
		}
	}
	cout << index - 1 << endl;
	sort(&arr[1], &arr[index]);
	for (int i = 1; i < index; i++)
		cout << arr[i] << endl;

	return 0;
}