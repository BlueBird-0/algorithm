#include <iostream>
using namespace std;
int apart[15][15] = { 0, };

int Q2775()
{
	int T = 0;
	cin >> T;
	//아파트 사람수 체크
	for (int i=0; i<15; i++)
	{
		apart[0][i] = i;
	}
	for (int y = 1; y < 15; y++)
	{
		for (int x = 1; x < 15; x++)
		{
			apart[y][x] = apart[y - 1][x] + apart[y][x - 1];
		}
	}


	while (T--)
	{
		int k, n;
		cin >> k >> n;
		
		cout << apart[k][n] << '\n';
	}
	return 0;
}