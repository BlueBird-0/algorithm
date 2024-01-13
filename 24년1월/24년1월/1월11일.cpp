#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

namespace {
	enum {
		R = 0,
		G,
		B
	};

	int result = 0;
	vector<int> values[3];
	char recently;

	int minimum(int a, int b, int c, int d, int e, int f, int g, int h)
	{
		int min = a;
		if (b < min)
			min = b;
		if (c < min)
			min = c;
		if (d < min)
			min = d;
		if (e < min)
			min = e;
		if (f < min)
			min = f;
		if (g < min)
			min = g;
		if (h < min)
			min = h;


		if (min == a || min == b|| min == c || min == d)
			return 1;
		else
			return 2;
	}

	void SelectValue(int i)
	{
		int j = i + 1;
		int k = i + 2;
		if (recently == 'R')
		{
			int min = minimum(
				values[G][i] + values[R][j] + values[G][k],
				values[G][i] + values[R][j] + values[B][k],
				values[G][i] + values[B][j] + values[G][k],
				values[G][i] + values[B][j] + values[R][k], 
				values[B][i] + values[R][j] + values[B][k], 
				values[B][i] + values[R][j] + values[G][k],
				values[B][i] + values[G][j] + values[B][k],
				values[B][i] + values[G][j] + values[R][k]);
			if (min == 1)
			{
				recently = 'G';
				result += values[G][i];
			}
			else {
				recently ='B';
				result += values[B][i];
			}
		}
		else  if (recently == 'G')
		{
			int min = minimum(
				values[R][i] + values[B][j] + values[R][k],
				values[R][i] + values[B][j] + values[G][k],
				values[R][i] + values[G][j] + values[R][k],
				values[R][i] + values[G][j] + values[B][k],
				values[B][i] + values[G][j] + values[B][k],
				values[B][i] + values[G][j] + values[R][k],
				values[B][i] + values[R][j] + values[B][k],
				values[B][i] + values[R][j] + values[G][k]);
			if (min == 1)
			{
				recently = 'R';
				result += values[R][i];
			}
			else {
				recently = 'B';
				result += values[B][i];
			}
		}
		else // if (recently == 'B')
		{
			int min = minimum(
				values[R][i] + values[B][j] + values[R][k],
				values[R][i] + values[B][j] + values[G][k],
				values[R][i] + values[G][j] + values[R][k],
				values[R][i] + values[G][j] + values[B][k],
				values[G][i] + values[B][j] + values[G][k],
				values[G][i] + values[B][j] + values[R][k],
				values[G][i] + values[R][j] + values[G][k],
				values[G][i] + values[R][j] + values[B][k]);
			if (min == 1)
			{
				recently = 'R';
				result += values[R][i];
			}
			else {
				recently = 'G';
				result += values[G][i];
			}
		}
		//cout << recently << '\n';
	}
}
int Q1149() {
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	int N;
	cin >> N;
	
	for (int i = 0; i < 3 * N; i++)
	{
		int value;
		cin >> value;
		values[i % 3].push_back(value);
	}
	values[R].push_back(1000);
	values[G].push_back(1000);
	values[B].push_back(1000);
	values[R].push_back(1000);
	values[G].push_back(1000);
	values[B].push_back(1000);
	values[R].push_back(1000);
	values[G].push_back(1000);
	values[B].push_back(1000);

	
	//반복계산
	for (int i = 0; i < N; i++)
	{
		SelectValue(i);
	}
	cout << result;
	
	
	return 0;
}