#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int Q1463()
{
	int X;
	cin >> X;

	arr.push_back(0);
	arr.push_back(0);
	for (int i=2; i<=X; i++)
	{
		int max = 1000000;
		if (i % 3 == 0 && arr[i / 3] < max)
		{
			max = arr[i / 3] + 1;
		}
		if (i % 2 == 0 && arr[i / 2] < max)
		{
			max = arr[i / 2] + 1;
		}
		if (arr[i - 1] < max)
		{
			max = arr[i - 1] + 1;
		}
		arr.push_back(max);
	}
	cout << arr[X];
	return 0;
}