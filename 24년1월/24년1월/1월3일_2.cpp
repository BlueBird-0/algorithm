#include <iostream>
#include <queue>
using namespace std;

int Q11286()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	priority_queue<int> positiveQ;
	priority_queue<int> negativeQ;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (negativeQ.size() != 0 && positiveQ.size() != 0)
			{
				int negativeNum = negativeQ.top();
				int positiveNum = positiveQ.top();
				if (positiveNum > negativeNum)
				{
					int result = positiveQ.top();
					positiveQ.pop();
					cout << -result << '\n';
				}
				else {	// negativeNum <= positiveNum
					int result = negativeQ.top();
					negativeQ.pop();
					cout << result << '\n';
				}

			}
			else if (negativeQ.size() != 0)
			{
				int result = negativeQ.top();
				negativeQ.pop();
				cout << result << '\n';
			}
			else if (positiveQ.size() != 0)
			{
				int result = positiveQ.top();
				positiveQ.pop();
				cout << -result << '\n';
			}
			else {
				cout << 0 << '\n';
			}


		}
		else if (x < 0)
		{
			negativeQ.push(x);
		}
		else if (x > 0)
		{
			positiveQ.push(-x);
		}
	}
	return 0;
}