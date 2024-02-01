//https://www.acmicpc.net/problem/1012
#include <iostream>
#include <queue>
using namespace std;
namespace {
	int Testcase, M, N, K;
	bool map[51][51] = { false, };
	int resultCount = 0;

	queue<pair<int, int>> Q;

	void InsertQ(int x, int y)
	{
		if (x < 0 || x >M || y<0 || y>N)
			return ;
		else
			Q.push(make_pair(x, y));
	}
	void StartBFS(int x, int y)
	{
		resultCount++;
		Q.push(make_pair(x, y));
		while (Q.size() != 0)
		{
			pair<int, int> position = Q.front();
			Q.pop();

			if (map[position.second][position.first])
			{
				map[position.second][position.first] = false;

				InsertQ(position.first - 1, position.second);
				InsertQ(position.first + 1, position.second);
				InsertQ(position.first, position.second - 1);
				InsertQ(position.first, position.second + 1);
			}
		}
	}
}

int Q1012()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	cin >> Testcase;

	while (Testcase--)
	{
		cin >> M >> N >> K;
		resultCount = 0;
		for (int i = 0; i < K; i++)
		{
			int y, x;
			cin >> x >> y;
			map[y][x] = true;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (map[y][x])
				{
					StartBFS(x, y);
				}
			}
		}
		cout << resultCount << endl;
	}
	return 0;
}