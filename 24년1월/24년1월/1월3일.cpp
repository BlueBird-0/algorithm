//https://www.acmicpc.net/problem/11279
#include <iostream>
#include <queue>
using namespace std;

int Q11279()
{
	cin.tie(0);
	priority_queue<int> maxQ;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (maxQ.size() == 0)
			{
				cout << 0 << '\n';
			}
			else {
				cout << maxQ.top() << '\n';
				maxQ.pop();
			}
		}
		else
		{
			maxQ.push(x);
		}
	}

	return 0;
}