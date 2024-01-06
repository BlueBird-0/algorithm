#include <iostream>
using namespace std;

int Q2839()
{
	int N;
	cin >> N;
	int smallCount = 0;

	bool unavailable = false;
	for (int i = N / 5; i >= 0; i--)
	{
		int remainder = N - (i * 5);
		smallCount = remainder/ 3;
		if (remainder % 3 == 0)
		{
			cout << i + smallCount;
			unavailable = true;
			break;
		}
	}
	
	if (!unavailable)
	{
		cout << -1;
	}


	return 0;
}