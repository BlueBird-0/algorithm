#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {
	int delay[1001];
	bool link[1001][1001];
	int DPValue[1001];
	int N, K;
	int win;
}

int DP(int index)
{
	if (DPValue[index] == -1)
	{
		for (int i = 1; i <= N; i++)
		{
			if (link[index][i] == true)
			{
				int newValue = DP(i) + delay[index];
				if (newValue > DPValue[index])
				{
					DPValue[index] = newValue;
				}
			}
		}
		if (DPValue[index] == -1)
			DPValue[index] = delay[index];
	}

	return DPValue[index];
}

int Q1005()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int T;
	cin >> T;

	while (T--)
	{
		//초기화
		for (int i = 0; i < 1001; i++)
		{
			DPValue[i] = -1;
			delay[i] = 0;
			for (int j = 0; j < 1001; j++)
			{
				link[i][j] = false;
			}
		}

		//입력
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			cin >> delay[i];
		}
		for (int i = 1; i <= K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			link[Y][X] = true;
		}
		cin >> win;

		//DP
		cout << DP(win) << '\n';
	}
	return 0;
}