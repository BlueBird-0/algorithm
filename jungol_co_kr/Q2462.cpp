#include <iostream>
#include <memory.h>

using namespace std;
bool downlink[501][501] = { 0, };
bool uplink[501][501] = { 0, };

int checkCount = 0;
bool check[501] = { 0, };
int N, M;

void propagation(int idx, bool dirUp)
{
	if (!check[idx]) {
		checkCount++;
		check[idx] = true;

		for (int i = 1; i <= N; i++)
		{
			if (dirUp && uplink[idx][i] && check[i] == false) {
				propagation(i, dirUp);
			}

			if (!dirUp && downlink[idx][i] && check[i] == false) {
				propagation(i, dirUp);
			}
		}
	}

}

int main()
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		downlink[a][b] = true;
		uplink[b][a] = true;
	}

	//Ã£±â
	int result=0;
	for (int i = 1; i <= N; i++)
	{
		checkCount = 0;
		memset(check, 0, sizeof(check));
		propagation(i, true);
		check[i] = false;
		checkCount--;
		propagation(i, false);

		if (checkCount == N)
			result++;
	}
	printf("%d", result);
}