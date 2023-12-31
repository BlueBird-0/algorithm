//바이러스
//https://www.acmicpc.net/problem/2606
#include <iostream>
#include <queue>

namespace {
	using namespace std;
	bool network[101][101] = { false, };
	bool connected[101] = { false, };
}

int Q2606()
{
	int PCCount = 0;
	int connectCount =0;
	cin >> PCCount;
	cin >> connectCount;
	for (int i = 0; i < connectCount; i++)
	{
		int networkA, networkB = 0;
		cin >> networkA >> networkB;
		network[networkA][networkB] = true;
		network[networkB][networkA] = true;
	}
	
	queue<int> waves;
	waves.push(1);

	int result = -1;
	while (waves.size() != 0)
	{
		int wave = waves.front();
		waves.pop();

		if (connected[wave] == false)
		{
			connected[wave] = true;
			result++;
			for (int i = 0; i < 101; i++)
			{
				if (network[wave][i] == true)
				{
					if(connected[i] == false)
						waves.push(i);
				}
			}
		}
	}
	
	cout << result;
	

	return 0;
}