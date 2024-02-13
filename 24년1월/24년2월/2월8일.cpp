#include <iostream>
#include <algorithm>
using namespace std;
namespace {
	int N, W;
	int map[2][10000];

	bool CheckCombine(int a, int b)
	{
		return a + b <= W ? true : false;
	}

	int DP(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return (map[0][0] + map[1][0] <= W) ? 1 : 2;
		}
		else if (n == 2)
		{
			int front = 0;




		}

		min(DP(n-2), DP(n-1));
		return 0;
	}
}


int Q1006() {
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> W;
		for (int i = 0; i < N; i++)
		{
			cin >> map[0][i]; 
		}
		for (int i = 0; i < N; i++)
		{
			cin >> map[1][i];
		}
	}

	//n == 10이라면?
	DP(10);

	return 0;
}

