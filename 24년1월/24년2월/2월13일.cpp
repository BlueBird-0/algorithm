#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {
	int T, N;
	int Arr[20];
	pair<int, int> points[20];
	int x, y;
	double ans;

	double xSum, ySum, xNegSum, yNegSum;

	double VectorSum(double x, double y)	//x2-x1, y2-y1이 올때, 벡터합 반환
	{
		return sqrt(x * x + y * y);
	}

	void BruteForce(int n, int k)
	{
		if (k == N / 2)
		{
			xSum = 0;
			ySum = 0;
			xNegSum = 0;
			yNegSum = 0;
			for (int i = 0; i < N; i++)
			{
				if (Arr[i] == 0) 
				{
					xSum += points[i].first;
					ySum += points[i].second;
				}
				else {
					xNegSum += points[i].first;
					yNegSum += points[i].second;
				}
			}
			if (ans == -1)
			{
				ans = VectorSum(xSum - xNegSum, ySum - yNegSum);
			}
			else {
				ans = min(ans, VectorSum(xSum - xNegSum, ySum - yNegSum));
			}
			return;
		}
		else if (n == N){
			return;
		}
		else {
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
					BruteForce(n + 1, k);
				else {
					Arr[n] = 1;
					BruteForce(n + 1, k + 1);
					Arr[n] = 0;
				}
			}
		}
	}
}

int Q1007()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cout.precision(12);
	cout << fixed;
	cin >> T;
	while (T--)
	{
		cin >> N;
		ans = -1;
		for (int j = 0; j < N; j++)
		{
			Arr[j] = 0;
		}


		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			points[i] = make_pair(x, y);
		}
		BruteForce(0, 0);
		cout << ans << '\n';
	}

	return 0;
}