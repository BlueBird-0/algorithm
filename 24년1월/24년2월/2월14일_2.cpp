#include <iostream>
#include <vector>
using namespace std;

namespace {
	int n;
	vector<pair<int, short>> link[10001];

	int maxSum = 0;
	int last_Index = 0;

	void FindDFS(int current, int input, int sum)
	{
		bool leafNode = true;
		for (pair<int, short> node : link[current])
		{
			if (node.first != input)
			{
				leafNode = false;
				FindDFS(node.first, current, sum + node.second);
			}
		}
		if (leafNode && maxSum < sum)
		{
			maxSum = sum;
			last_Index = current;
		}
	}
}

int Q1967()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		link[a].push_back(make_pair(b, c));
		link[b].push_back(make_pair(a, c));
	}

	//제일 멀리 있는것 찾기
	FindDFS(1, 0, 0);
	maxSum = 0;
	FindDFS(last_Index, 0, 0);
	cout << maxSum;

	return 0;
}